<?php

/**
 * @file
 * Main admin file edgy_paragraphs.module.
 */

/**
 * Menu callback function for settings form.
 */
function edgy_settings_form($form, &$form_state) {
  $form[EDGY_CONTAINER_VARIABLE] = array(
    '#type' => 'textfield',
    '#title' => t('Container class'),
    '#default_value' => variable_get(EDGY_CONTAINER_VARIABLE, EDGY_CONTAINER_NAME),
    '#description' => t('Enter the class which is used as the container, e.g., .container'),
  );
  return system_settings_form($form);
}
