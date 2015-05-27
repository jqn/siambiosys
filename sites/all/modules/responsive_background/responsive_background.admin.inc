<?php
/**
 * @file
 * Responsive Background Admin
 *
 * @author: Daniel Honrade http://drupal.org/user/351112
 *
 */

/**
 * Admin Form: UI
 *
 */
function responsive_background_admin($form, &$form_state, $op = NULL) {

  global $_responsive_background_set;

  $settings = $_responsive_background_set;

  $form = array();

  $form['responsive_background'] = array(
    '#type'          => 'fieldset',
    '#title'         => 'Responsive Background Images Configuration',
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
    '#tree'          => TRUE,
  );

  $form['responsive_background']['enabled'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enabled'),
    '#default_value' => $settings['enabled'],
    '#description'   => t('Enable/Disable Responsive Background Images (Useful for testing)'),
    '#prefix'        => '<div class="responsive-background-columns clearfix"><div class="responsive-background-column responsive-background-column-1">',
  );

  $options = image_style_options(TRUE);

  $form['responsive_background']['bp320'] = array(
    '#type'          => 'select',
    '#title'         => t('320px'),
    '#default_value' => $settings['bp320'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 320px'),
  );

  $form['responsive_background']['bp480'] = array(
    '#type'          => 'select',
    '#title'         => t('480px'),
    '#default_value' => $settings['bp480'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 480px'),
  );

  $form['responsive_background']['bp640'] = array(
    '#type'          => 'select',
    '#title'         => t('640px'),
    '#default_value' => $settings['bp640'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 640px'),
  );

  $form['responsive_background']['bp800'] = array(
    '#type'          => 'select',
    '#title'         => t('800px'),
    '#default_value' => $settings['bp800'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 800px'),
  );

  $form['responsive_background']['bp960'] = array(
    '#type'          => 'select',
    '#title'         => t('960px'),
    '#default_value' => $settings['bp960'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 960px'),
  );

  $form['responsive_background']['bp1120'] = array(
    '#type'          => 'select',
    '#title'         => t('1120px'),
    '#default_value' => $settings['bp1120'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 1120px'),
  );

  $form['responsive_background']['bp1280'] = array(
    '#type'          => 'select',
    '#title'         => t('1280px'),
    '#default_value' => $settings['bp1280'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 1280px'),
  );

  $form['responsive_background']['bp1440'] = array(
    '#type'          => 'select',
    '#title'         => t('1440px'),
    '#default_value' => $settings['bp1440'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 1440px'),
  );

  $form['responsive_background']['bp1600'] = array(
    '#type'          => 'select',
    '#title'         => t('1600px'),
    '#default_value' => $settings['bp1600'],
    '#options'       => $options,
    '#description'   => t('Image style for breakpoint 1600px'),
    '#suffix'        => '</div><div class="responsive-background-column responsive-background-column-2">',
  );

  $form['responsive_background']['images'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Images'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix'        => '<div id="images-fieldset-wrapper">',
    '#suffix'        => '</div>',
    '#description'     => t('Upload images with dimensions: 1600px width and 1200px height.'),
  );

  $images = isset($settings['images']) ? $settings['images']: array();
  // for ajax call
  $image_count = count($images);
  if (empty($form_state['image_num'])) $form_state['image_num'] = $image_count;

  if ($images != 0) {

    for ($i = 0; $i < $form_state['image_num']; $i++) {
      
      if (isset($images['rb' . $i])) {
        $image_fid = $images['rb' . $i];
        $image = file_load($image_fid);
        $image_source = '<img src="' . image_style_url('thumbnail', $image->uri) . '" />';
      }
      else {
        $image_source = '';      
      }
      
      $form['responsive_background']['images']['rb' . $i] = array(
        //'#title'           => t('Image'),
        '#type'            => 'managed_file',
        '#description'     => $image_source,
        '#default_value'   => isset($images['rb' . $i]) ? $images['rb' . $i]: '',
        '#upload_location' => 'public://responsive_background/',
        '#progress_indicator' => 'bar',
      );
      $image_source = '';
    }
  }

  $form['responsive_background']['add_another'] = array(
    '#type'      => 'submit',
    '#value'     => t('Add another image'),
    '#submit'    => array('responsive_background_add_another'),
    '#ajax'      => array(
      'callback' => 'responsive_background_add_another_callback',
      'wrapper'  => 'images-fieldset-wrapper',
    ),
  );

  $form['responsive_background']['position'] = array(
    '#type'          => 'radios',
    '#title'         => t('Position'),
    '#default_value' => !empty($settings['position']) ? $settings['position']: 0,
    '#options'       => array( 'fixed' => 'Fixed', 'absolute' => 'Absolute'),
    '#description'   => t('Fixed - stays on screern, Absolute - scrolls.'),
  );

  $form['responsive_background']['center'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Center'),
    '#default_value' => !empty($settings['center']) ? $settings['center']: 0,
    '#description'   => t('This will center image if it\'s larger than the screen'),
  );

  $form['responsive_background']['top'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Top'),
    '#default_value' => !empty($settings['top']) ? $settings['top']: 0,
    '#description'   => t('Top position'),
  );

  $form['responsive_background']['height'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Wrapper Height'),
    '#default_value' => !empty($settings['height']) ? $settings['height']: '',
    '#description'   => t('This will crop the image height.'),
  );

  $form['responsive_background']['exclude'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Excluded Pages'),
    '#default_value' => $settings['exclude'],
    '#description'   => t('List the page paths to be excluded from Responsive Background Images on each line.'),
    '#suffix'        => '</div></div>',
  );

  $form['save']      = array( '#type' => 'submit', '#value' => 'Save', );
  $form['reset']     = array( '#type' => 'submit', '#value' => 'Reset', );

  //dsm($form);
  return $form;
}


/**
 * Callback for both ajax-enabled buttons.
 *
 * Selects and returns the fieldset with the names in it.
 */
function responsive_background_add_another_callback($form, $form_state) {
  return $form['responsive_background']['images'];
}

/**
 * Submit handler for the "add-one-more" button.
 *
 * Increments the max counter and causes a rebuild.
 */
function responsive_background_add_another($form, &$form_state) {
  $form_state['image_num']++;
  $form_state['rebuild'] = TRUE;
}


/**
 * Admin Form: Submit
 *
 */
function responsive_background_admin_submit($form, $form_state) {
  global $user;
  global $_responsive_background_defaults;

  $form_values = $form_state['values'];
  //dsm($form_values);
  // make the images permanent
  $images = $form_values['responsive_background']['images'];
  if (!empty($images)) {
    foreach ($images as $key => $image_fid) {
      if ($image_fid != 0) {
        // Load the file via file.fid.
        $image = file_load($image_fid);
        // Change status to permanent.
        $image->status = FILE_STATUS_PERMANENT;
        // Save.
        file_save($image);
        // Record that the module (in this example, user module) is using the file.
        file_usage_add($image, 'user', 'user', $user->uid);
      }
      elseif ($image_fid == 0) {
        unset($form_values['responsive_background']['images'][$key]);
      }
    }
  }
  if ($form_values['op'] == 'Save') {
    $settings = $form_values['responsive_background']; // save user settings
  }
  elseif ($form_values['op'] == 'Reset') {
    $settings = $_responsive_background_defaults; // save default settings
  }
  // recreate all image styles
  image_flush_caches();

  variable_set('responsive_background', $settings);
}
