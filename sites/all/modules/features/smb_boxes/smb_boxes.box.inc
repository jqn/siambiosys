<?php
/**
 * @file
 * smb_boxes.box.inc
 */

/**
 * Implements hook_default_box().
 */
function smb_boxes_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ceramics_box';
  $box->plugin_key = 'simple';
  $box->title = 'Ceramics';
  $box->description = 'Gallery Ceramics Link';
  $box->options = array(
    'body' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'additional_classes' => 'link-box',
  );
  $export['ceramics_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'comissions_box';
  $box->plugin_key = 'simple';
  $box->title = 'Commissions';
  $box->description = 'Gallery Commissions Link';
  $box->options = array(
    'body' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['comissions_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'design_box';
  $box->plugin_key = 'simple';
  $box->title = 'Design';
  $box->description = 'Gallery Desing Link';
  $box->options = array(
    'body' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['design_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'images_box';
  $box->plugin_key = 'simple';
  $box->title = 'Images';
  $box->description = 'Gallery Images Link';
  $box->options = array(
    'body' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['images_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'polymer_box';
  $box->plugin_key = 'simple';
  $box->title = 'Polymer Clay';
  $box->description = 'Gallery Polymer Link';
  $box->options = array(
    'body' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['polymer_box'] = $box;

  return $export;
}
