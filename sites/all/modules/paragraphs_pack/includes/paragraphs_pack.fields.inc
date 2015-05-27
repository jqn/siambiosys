<?php

/**
 * @file
 * Implements custom fields: PP_FIELD_TYPE_VIEW_MODE.
 *
 */

/**
 * Implements hook_field_info().
 */
function paragraphs_pack_field_info() {
  return array(
    PP_FIELD_TYPE_VIEW_MODE => array(
      'label' => t('View mode Selection'),
      'description' => t('This field stores a view mode that\'s going to be applied on Paragraphs pack items field'),
      'instance_settings' => array(
        // Default to the core entity type node.
        'entity_type' => 'node',
      ),
      'default_widget' => 'options_select',
      'default_formatter' => PP_FORMATTER_VIEW_MODE,
    ),
  );
}

/**
 * Implements hook_field_validate().
 */
function paragraphs_pack_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  foreach ($items as $delta => $item) {
    if (!empty($item['value'])) {
      $view_mode = $item['value'];
      $possible_view_modes = paragraphs_pack_get_allowed_view_modes($instance);

      // Validate the view mode.
      if ($view_mode != PP_VALUE_DEFAULT && !isset($possible_view_modes[$view_mode])) {
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'pp_view_mode_invalid',
          'message' => t('View mode key "%view_mode" doesn\'t exist.', array(
            '%view_mode' => $view_mode,
          )),
        );
      }
    }
  }
}

/**
 * Implements hook_field_is_empty().
 */
function paragraphs_pack_field_is_empty($item, $field) {
  if ($item['value'] == PP_VIEW_MODE_NONE) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Implements hook_field_settings_form().
 */
function paragraphs_pack_field_settings_form($field, $instance, $has_data) {
  $form = array();

  switch ($field['type']) {
    case PP_FIELD_TYPE_VIEW_MODE:
      $settings = $field['settings'];

      // Select the target entity type.
      $entity_type_options = array();
      foreach (entity_get_info() as $entity_type => $entity_info) {
        $entity_type_options[$entity_type] = $entity_info['label'];
      }

      $form['entity_type'] = array(
        '#type' => 'select',
        '#title' => t('Entity type'),
        '#options' => $entity_type_options,
        '#default_value' => $instance['settings']['entity_type'],
        '#required' => TRUE,
        '#description' => t('The entity type whose view modes are displayed.'),
        '#disabled' => $has_data,
        '#size' => 1,
          // '#limit_validation_errors' => array(),
      );
      break;
  }

  return $form;
}

/**
 * Implements hook_field_widget_info_alter().
 *
 * The pp_view_mode field type does not implement widgets of its own, but reuses the
 * widgets defined in options.module.
 *
 * @see paragraphs_pack_options_list()
 */
function paragraphs_pack_field_widget_info_alter(&$info) {
  $widgets = array(
    'options_select' => array(PP_FIELD_TYPE_VIEW_MODE),
  );

  foreach ($widgets as $widget => $field_types) {
    $info[$widget]['field types'] = array_merge($info[$widget]['field types'], $field_types);
  }
}

/**
 * Implements hook_options_list().
 */
function paragraphs_pack_options_list($field, $instance, $entity_type, $entity) {
  $options = array();

  switch ($field['type']) {
    case PP_FIELD_TYPE_VIEW_MODE:
      $options = paragraphs_pack_get_allowed_view_modes($instance);
      break;
  }

  return $options;
}

/**
 * Returns the array of allowed view modes for a list field.
 *
 * @param $instance
 *   The instance information.
 *
 * @return
 *   The array of allowed view modes. Keys of the array are view mode ...,
 *   values of the array are the display labels.
 */
function paragraphs_pack_get_allowed_view_modes($instance) {
  $view_modes = &drupal_static(__FUNCTION__, array());

  if (!isset($view_modes[$instance['id']])) {
    $entity_type = $instance['settings']['entity_type'];
    $view_modes[$instance['id']] = paragraphs_pack_get_entity_type_view_modes($entity_type);
  }

  return $view_modes[$instance['id']];
}

/**
 * Get all possible view modes of specified entity type.
 *
 * @param string $entity_type
 *   The specified entity type.
 * @return array
 *   An array of all view modes of the specified entity type.
 */
function paragraphs_pack_get_entity_type_view_modes($entity_type) {
  $view_modes = array(PP_VALUE_DEFAULT => 'Default');
  $entity_info = entity_get_info($entity_type);

  // Create key => label array of view modes.
  if (isset($entity_info['view modes'])) {
    foreach ($entity_info['view modes'] as $key => $value) {
      $view_modes[$key] = $value['label'];
    }
  }

  return $view_modes;
}

/**
 * Implements hook_field_update_field().
 */
function paragraphs_pack_field_update_field($field, $prior_field, $has_data) {
  switch ($field['type']) {
    case PP_FIELD_TYPE_VIEW_MODE:
      drupal_static_reset('paragraphs_pack_get_allowed_view_modes');
      break;
  }
}
