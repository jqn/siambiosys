<?php

/**
 * @file
 * Admin include file for entity background image.
 */

/**
 * Menu callback function for settings form.
 */
function entity_background_image_settings_form($form, &$form_state) {
  $image_styles = image_style_options(FALSE, PASS_THROUGH);
  $form['entity_background_image_image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => variable_get('entity_background_image_image_style', EB_IMAGE_STYLE),
  );
  return system_settings_form($form);
}
