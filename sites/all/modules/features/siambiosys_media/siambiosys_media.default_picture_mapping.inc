<?php
/**
 * @file
 * siambiosys_media.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function siambiosys_media_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Banner image styles';
  $picture_mapping->machine_name = 'banner_image_styles';
  $picture_mapping->breakpoint_group = 'siambiosys';
  $picture_mapping->mapping = array(
    'breakpoints.theme.siambiosys.tv' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_style_rep_breakpoints_theme_siambiosys_tv_1x',
      ),
    ),
    'breakpoints.theme.siambiosys.wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_style_rep_breakpoints_theme_siambiosys_wide_1x',
      ),
    ),
    'breakpoints.theme.siambiosys.narrow' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_style_rep_breakpoints_theme_siambiosys_narrow_1x',
      ),
    ),
    'breakpoints.theme.siambiosys.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_style_rep_breakpoints_theme_siambiosys_mobile_1x',
      ),
    ),
  );
  $export['banner_image_styles'] = $picture_mapping;

  return $export;
}
