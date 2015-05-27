<?php

/**
 * @file
 * Definition of the 'edgy' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Edgy'),
  'description' => t('The default panel rendering style; displays each pane with a separator.'),
  'render region' => 'edgy_style_render_region',
);

/**
 * Render callback.
 */
function theme_edgy_style_render_region($vars) {
  $output = '';
  $output .= implode('<div class="panel-separator"></div>', $vars['panes']);
  return $output;
}
