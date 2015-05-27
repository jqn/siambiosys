<?php
/**
 * @file
 * paragraphs_pack_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function paragraphs_pack_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function paragraphs_pack_test_node_info() {
  $items = array(
    'pp_test_landing_page' => array(
      'name' => t('PP Test Landing page'),
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
