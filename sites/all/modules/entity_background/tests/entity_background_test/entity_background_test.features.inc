<?php
/**
 * @file
 * entity_background_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function entity_background_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function entity_background_test_node_info() {
  $items = array(
    'eb_test_landing_page' => array(
      'name' => t('EB Test landing page'),
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

/**
 * Implements hook_paragraphs_info().
 */
function entity_background_test_paragraphs_info() {
  $items = array(
    'eb_content_test' => array(
      'name' => 'EB Content (test)',
      'bundle' => 'eb_content_test',
      'locked' => '1',
    ),
  );
  return $items;
}
