<?php

/**
 * @file
 * Plugin for entity background image.
 */
$plugin = array(
  'name' => 'image',
  'label' => t('Add background images to entities.'),
  'handler' => 'entity_background_image_decorator',
);

/**
 * Perform the image decorator job.
 *
 * @param string $selector
 *   CSS selector that identifies the entity wrapper.
 * @param object $field_collection
 *   An entity of type field_collection_item.
 */
function entity_background_image_decorator($selector, $field_collection) {
  $wrapper = entity_metadata_wrapper('field_collection_item', $field_collection);
  $image = $wrapper->field_eb_image->value();
  $style = $wrapper->field_eb_image_style->value(array('sanitize' => TRUE));

  if (!empty($style)) {
    $style = 'eb-image-' . drupal_clean_css_identifier($style);
  }

  // Image must exist.
  if (!empty($image)) {
    // Get stored image style.
    $image_style = variable_get('entity_background_image_image_style', EB_IMAGE_STYLE);
    $resized_image = image_style_url($image_style, $image['uri']);

    // Set the background image.
    $js_settings = array($selector => array(
        'image' => $resized_image,
        'style' => $style,
    ));
    drupal_add_js(array('entity_background_image' => $js_settings), 'setting');
    drupal_add_js(drupal_get_path('module', 'entity_background_image') . '/plugins/entity_background/image.js');
    drupal_add_css(drupal_get_path('module', 'entity_background_image') . '/plugins/entity_background/image.css');
  }
}