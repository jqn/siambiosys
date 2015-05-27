<?php
/**
 * @file
 * edgy_node_test.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function edgy_node_test_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:edgy_test_landing_page:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'edgy_test_landing_page';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'edgy-boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
    'style' => 'edgy',
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '4894eea3-30b3-494c-9ce0-a865ad9f6ed9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9055371f-093a-4eae-8ec9-fd622e46eb58';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_edgy_test_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'container',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9055371f-093a-4eae-8ec9-fd622e46eb58';
    $display->content['new-9055371f-093a-4eae-8ec9-fd622e46eb58'] = $pane;
    $display->panels['contentmain'][0] = 'new-9055371f-093a-4eae-8ec9-fd622e46eb58';
    $pane = new stdClass();
    $pane->pid = 'new-83be5ae6-9990-4910-a3f2-5b82c4603d3d';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_edgy_test_paras';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'paragraphs_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '83be5ae6-9990-4910-a3f2-5b82c4603d3d';
    $display->content['new-83be5ae6-9990-4910-a3f2-5b82c4603d3d'] = $pane;
    $display->panels['contentmain'][1] = 'new-83be5ae6-9990-4910-a3f2-5b82c4603d3d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9055371f-093a-4eae-8ec9-fd622e46eb58';
  $panelizer->display = $display;
  $export['node:edgy_test_landing_page:default'] = $panelizer;

  return $export;
}
