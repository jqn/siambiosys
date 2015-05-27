<?php

/**
 * @file
 * Plugin for entity background parallax.
 */
$plugin = array(
  'name' => 'parallax',
  'label' => t('Add parallax images to paragraphs.'),
  'handler' => 'entity_background_parallax_decorator',
);

/**
 * Perform the image decorator job.
 *
 * @param string $selector
 *   CSS selector that identifies the entity wrapper.
 * @param object $field_collection
 *   An entity of type field_collection_item.
 */
function entity_background_parallax_decorator($selector, $field_collection) {
  if (($library = libraries_load(EB_PARALLAX_LIBRARY)) && !empty($library['loaded'])) {
    $wrapper = entity_metadata_wrapper('field_collection_item', $field_collection);
    $speed = $wrapper->field_eb_parallax_speed->value(array('sanitize' => TRUE));
    $image = $wrapper->field_eb_parallax_image->value();

    // Image must exist.
    if (!empty($image)) {
      $image_url = file_create_url($image['uri']);
      // Build options.
      $options = array(
        'imageSrc' => $image_url,
      );
      // Add speed if present.
      if (!empty($speed)) {
        $options['speed'] = $speed;
      }

      $js_settings = array($selector => $options);
      drupal_add_js(array('entity_background_parallax' => $js_settings), 'setting');
      drupal_add_js(drupal_get_path('module', 'entity_background_parallax') . '/plugins/entity_background/parallax.js');
    }
  }
}
