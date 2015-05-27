<?php

/**
 * @file
 * Plugin for entity background color.
 */
$plugin = array(
  'name' => 'color',
  'label' => t('Add background color to entities.'),
  'handler' => 'entity_background_color_decorator',
);

function entity_background_color_decorator($selector, $entity) {
  $wrapper = entity_metadata_wrapper('field_collection_item', $entity);
  $color = $wrapper->field_eb_color->value(array('sanitize' => TRUE));

  if (!empty($color)) {
    drupal_add_css($selector . ' {background-color: #' . $color . ';}', 'inline');
  }

}
