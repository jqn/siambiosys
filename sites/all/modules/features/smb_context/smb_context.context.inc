<?php
/**
 * @file
 * smb_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function smb_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gallery';
  $context->description = '';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'gallery' => 'gallery',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ceramics_box' => array(
          'module' => 'boxes',
          'delta' => 'ceramics_box',
          'region' => 'header',
          'weight' => '-10',
        ),
        'boxes-comissions_box' => array(
          'module' => 'boxes',
          'delta' => 'comissions_box',
          'region' => 'header',
          'weight' => '-9',
        ),
        'boxes-design_box' => array(
          'module' => 'boxes',
          'delta' => 'design_box',
          'region' => 'header',
          'weight' => '-8',
        ),
        'boxes-images_box' => array(
          'module' => 'boxes',
          'delta' => 'images_box',
          'region' => 'header',
          'weight' => '-7',
        ),
        'boxes-polymer_box' => array(
          'module' => 'boxes',
          'delta' => 'polymer_box',
          'region' => 'header',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  $export['gallery'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'All front content';
  $context->tag = 'Featured Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All front content');
  t('Featured Content');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_global';
  $context->description = '';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-copyright' => array(
          'module' => 'boxes',
          'delta' => 'copyright',
          'region' => 'footer_lower',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  $export['site_global'] = $context;

  return $export;
}
