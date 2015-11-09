<?php
/**
 * @file
 * siambiosys_content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function siambiosys_content_types_node_info() {
  $items = array(
    'hero_image' => array(
      'name' => t('Hero Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
