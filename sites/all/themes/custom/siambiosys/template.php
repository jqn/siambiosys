<?php

/**
 * @file
 * template.php
 */

function shn_custom_menu_tree__primary(&$vars) {
  return '<ul class="menu nav navbar-nav primary">' . $vars['tree'] . '</div>';
}

/**
 * Implements template_preprocess_views_view_table().
 */
function shn_custom_preprocess_views_view_table(&$vars) {
  // dsm($vars);
}