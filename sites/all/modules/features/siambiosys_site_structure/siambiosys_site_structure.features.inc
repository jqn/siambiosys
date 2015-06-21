<?php
/**
 * @file
 * siambiosys_site_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function siambiosys_site_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function siambiosys_site_structure_node_info() {
  $items = array(
    'about' => array(
      'name' => t('About'),
      'base' => 'node_content',
      'description' => t('Personal Statement and Acknowledgements.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'brand' => array(
      'name' => t('Brand'),
      'base' => 'node_content',
      'description' => t('Content type of brand related content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'enciclopedia' => array(
      'name' => t('Enciclopedia'),
      'base' => 'node_content',
      'description' => t('Definitions of terms used in the site for user experience.'),
      'has_title' => '1',
      'title_label' => t('Define'),
      'help' => '',
    ),
    'homepage' => array(
      'name' => t('Homepage'),
      'base' => 'node_content',
      'description' => t('Front page content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'links' => array(
      'name' => t('Links'),
      'base' => 'node_content',
      'description' => t('Content related to the links page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'main_slideshow_images' => array(
      'name' => t('Main Slideshow Images'),
      'base' => 'node_content',
      'description' => t('Featured images of products.'),
      'has_title' => '1',
      'title_label' => t('Product Name'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Featured news content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_display' => array(
      'name' => t('Product Display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'statement' => array(
      'name' => t('Statement'),
      'base' => 'node_content',
      'description' => t('A more concise version of resume.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'terms_and_definitions' => array(
      'name' => t('Terms and Definitions'),
      'base' => 'node_content',
      'description' => t('Definition of obscure terms used in the site for better user experience.'),
      'has_title' => '1',
      'title_label' => t('Terms and Definitions'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
