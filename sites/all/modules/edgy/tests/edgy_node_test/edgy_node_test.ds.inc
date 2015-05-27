<?php
/**
 * @file
 * edgy_node_test.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function edgy_node_test_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|edgy_test_content_ds|full';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'edgy_test_content_ds';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'edgy_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_edgy_test_body',
      ),
    ),
    'fields' => array(
      'field_edgy_test_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['paragraphs_item|edgy_test_content_ds|full'] = $ds_layout;

  return $export;
}
