<?php
/**
 * @file
 * siambiosys_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function siambiosys_media_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function siambiosys_media_image_default_styles() {
  $styles = array();

  // Exported image style: banner_style.
  $styles['banner_style'] = array(
    'label' => 'Banner Style',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1120,
          'height' => 500,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_style_rep_breakpoints_theme_siambiosys_mobile_1x.
  $styles['banner_style_rep_breakpoints_theme_siambiosys_mobile_1x'] = array(
    'label' => 'banner_style_rep_breakpoints_theme_siambiosys_mobile_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 180,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_style_rep_breakpoints_theme_siambiosys_narrow_1x.
  $styles['banner_style_rep_breakpoints_theme_siambiosys_narrow_1x'] = array(
    'label' => 'banner_style_rep_breakpoints_theme_siambiosys_narrow_1x',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 650,
          'height' => 290,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_style_rep_breakpoints_theme_siambiosys_tv_1x.
  $styles['banner_style_rep_breakpoints_theme_siambiosys_tv_1x'] = array(
    'label' => 'banner_style_rep_breakpoints_theme_siambiosys_tv_1x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1120,
          'height' => 500,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_style_rep_breakpoints_theme_siambiosys_wide_1x.
  $styles['banner_style_rep_breakpoints_theme_siambiosys_wide_1x'] = array(
    'label' => 'banner_style_rep_breakpoints_theme_siambiosys_wide_1x',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1120,
          'height' => 500,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_style_rep_module_picture_empty_srcset_1x.
  $styles['banner_style_rep_module_picture_empty_srcset_1x'] = array(
    'label' => 'banner_style_rep_module_picture_empty_srcset_1x',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1120,
          'height' => 500,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
