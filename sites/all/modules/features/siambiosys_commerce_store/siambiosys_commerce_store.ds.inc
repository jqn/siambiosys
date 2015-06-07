<?php
/**
 * @file
 * siambiosys_commerce_store.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function siambiosys_commerce_store_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'commerce_product|product|form';
  $ds_layout->entity_type = 'commerce_product';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_images',
        2 => 'field_description',
      ),
      'right' => array(
        3 => 'field_size',
        4 => 'field_color',
        5 => 'commerce_price',
        6 => 'sku',
        7 => 'status',
      ),
      'hidden' => array(
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_images' => 'left',
      'field_description' => 'left',
      'field_size' => 'right',
      'field_color' => 'right',
      'commerce_price' => 'right',
      'sku' => 'right',
      'status' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['commerce_product|product|form'] = $ds_layout;

  return $export;
}
