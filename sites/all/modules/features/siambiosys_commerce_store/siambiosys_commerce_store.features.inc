<?php
/**
 * @file
 * siambiosys_commerce_store.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function siambiosys_commerce_store_commerce_product_default_types() {
  $items = array(
    'apparel' => array(
      'type' => 'apparel',
      'name' => 'Apparel',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'prints' => array(
      'type' => 'prints',
      'name' => 'Prints',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function siambiosys_commerce_store_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
