<?php
/**
 * @file
 * Responsive Background Utilities
 *
 * @author: Daniel Honrade http://drupal.org/user/351112
 *
 * Note: Obviously, this will not work unless the javascript is on.
 *
 */

/**
 * Custom function
 * - gets the image file id from file_managed table
 *   and render the smallest set version of the image
 *
 */
function responsive_background_get_images() {

  global $_responsive_background_set;

  $settings = $_responsive_background_set;

  $images = $settings['images'];

  $rendered_images = array();

  // get the smallest image
  $style = $settings['bp320'];

  if (!empty($style)) {
    foreach ($images as $key => $image_fid) {
      if ($image_fid != 0) {
        // get the file from file_managed IDs
        $image = file_load($image_fid);
        // get the rendered image style
        $rendered_images[] = image_style_url($style, $image->uri);
      }
    }
  }
  else {
    drupal_set_message(t('Please configure your Responsive Background image styles.'));
  }

  return $rendered_images;
}
