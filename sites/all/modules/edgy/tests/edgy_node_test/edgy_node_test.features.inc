<?php
/**
 * @file
 * edgy_node_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function edgy_node_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function edgy_node_test_node_info() {
  $items = array(
    'edgy_test_landing_page' => array(
      'name' => t('Edgy Test Landing page'),
      'base' => 'node_content',
      'description' => t('Used for testing edgy.'),
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
function edgy_node_test_paragraphs_info() {
  $items = array(
    'edgy_test_content' => array(
      'name' => 'Edgy test content',
      'bundle' => 'edgy_test_content',
      'locked' => '1',
    ),
    'edgy_test_content_ds' => array(
      'name' => 'Edgy test content (DS)',
      'bundle' => 'edgy_test_content_ds',
      'locked' => '1',
    ),
  );
  return $items;
}
