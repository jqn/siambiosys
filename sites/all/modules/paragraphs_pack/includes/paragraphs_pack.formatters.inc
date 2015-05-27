<?php

/**
 * @file
 * Implements custom formatters: PP_FORMATTER_VIEW_MODE
 *
 */

// Variables:
define('PP_VIEW_MODE_SELECTION_FIELD', 'view_mode_selection_field');

/**
 * Implements hook_field_formatter_info().
 */
function paragraphs_pack_field_formatter_info() {
  $formatters = array(
    PP_FORMATTER_VIEW_MODE => array(
      'label' => t('Selected view mode'),
      'description' => t('Display the referenced entities rendered by entity_view() with selected view mode.'),
      'field types' => array('entityreference'),
      'settings' => array(
        PP_VIEW_MODE_SELECTION_FIELD => PP_VALUE_DEFAULT,
        'links' => TRUE,
      ),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function paragraphs_pack_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $element = array();

  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  if ($display['type'] == PP_FORMATTER_VIEW_MODE) {
    //$options = array(PP_VALUE_DEFAULT => 'Default'); // Possibility for no view mode by field value.
    $options = array();

    // Get all available View mode fields.
    foreach ($form['#fields'] as $field_name) {
      $field_info = field_info_field($field_name);
      $instance_info = field_info_instance($form['#entity_type'], $field_name, $form['#bundle']);
      if (!empty($field_info) && !empty($instance_info) && $field_info['type'] == PP_FIELD_TYPE_VIEW_MODE) {
        $options[$field_name] = $instance_info['label'];
      }
    }

    // Prepare default value.
    $default_value = $settings[PP_VIEW_MODE_SELECTION_FIELD];
    if (count($options) == 1) {
      reset($options);
      $default_value = key($options);
    }

    $element[PP_VIEW_MODE_SELECTION_FIELD] = array(
      '#type' => 'select',
      '#title' => t('View mode field render.'),
      '#description' => t('Select a field of which value will be used as a view mode for rendering.'),
      '#options' => $options,
      '#default_value' => $default_value,
      '#access' => count($options) > 1,
    );

    $element['links'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show links'),
      '#default_value' => $settings['links'],
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function paragraphs_pack_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  if ($display['type'] == PP_FORMATTER_VIEW_MODE) {
    $field_label = '';

    // Get View mode field.
    $view_mode_selection_field = $settings[PP_VIEW_MODE_SELECTION_FIELD];
    if ($view_mode_selection_field == PP_VALUE_DEFAULT) {
      $field_label = t('Default');
    }
    else {
      // Get field label from field machine name.
      $field_info = field_info_field($view_mode_selection_field);
      $instance_info = field_info_instance($instance['entity_type'], $view_mode_selection_field, $instance['bundle']);
      $field_label = $instance_info['label'];
    }

    $summary[] = t('Rendered by "@field" field view mode selection.', array('@field' => $field_label));
    $summary[] = !empty($settings['links']) ? t('Display links.') : t('Do not display links.');
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function paragraphs_pack_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  switch ($field['type']) {
    case 'entityreference':
      // Call the original entityreference functionality first.
      entityreference_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, $items, $displays);

      // Iterate through the fieldable entities again to attach the loaded data.
      foreach ($entities as $id => $entity) {
        $display = $displays[$id];
        $settings = $display['settings'];

        foreach ($items[$id] as $delta => $item) {
          // Get View mode field.
          $view_mode = 'full';
          $view_mode_selection_field = $settings[PP_VIEW_MODE_SELECTION_FIELD];
          if ($view_mode_selection_field != PP_VALUE_DEFAULT) {
            // Get view mode for rendering.
            $view_mode = $entity->{$view_mode_selection_field}[$langcode][0]['value'];
          }
          // Use the first one field with view mode value.
          else {
            list(,, $bundle) = entity_extract_ids($entity_type, $entity);
            $instances = field_info_instances($entity_type, $bundle);

            //$fields = field_read_fields(array('type' => $bundle_name));
            foreach ($instances as $field_name => $instance) {
              $field_info = field_info_field($field_name);
              if ($field_info['type'] == PP_FIELD_TYPE_VIEW_MODE) {
                $view_mode = $entity->{$field_name}[$langcode][0]['value'];
                break;
              }
            }
          }

          // Set view mode.
          $items[$id][$delta]['view_mode'] = $view_mode;
        }
      }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function paragraphs_pack_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $result = array();
  $settings = $display['settings'];

  // Rebuild the items list to contain only those with access.
  foreach ($items as $key => $item) {
    if (empty($item['access'])) {
      unset($items[$key]);
    }
  }

  switch ($display['type']) {
    case PP_FORMATTER_VIEW_MODE:
      foreach ($items as $delta => $item) {
        // Protect ourselves from recursive rendering.
        static $depth = 0;
        $depth++;
        if ($depth > 20) {
          throw new EntityReferenceRecursiveRenderingException(t('Recursive rendering detected when rendering entity @entity_type(@entity_id). Aborting rendering.', array('@entity_type' => $entity_type, '@entity_id' => $item['target_id'])));
        }

        $entity = clone $item['entity'];
        unset($entity->content);
        $result[$delta] = entity_view($field['settings']['target_type'], array($item['target_id'] => $entity), $item['view_mode'], $langcode, FALSE);

        if (empty($settings['links']) && isset($result[$delta][$field['settings']['target_type']][$item['target_id']]['links'])) {
          $result[$delta][$field['settings']['target_type']][$item['target_id']]['links']['#access'] = FALSE;
        }
        $depth = 0;
      }
      break;
  }

  return $result;
}
