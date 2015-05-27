<?php

/**
 * @file
 * Fields CRUD functions.
 *
 */

/**
 * Adds title field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_title($bundle, $field_label) {
  $field = paragraphs_pack_get_field_title();

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'widget' => array('type' => 'text_textfield'),
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create title field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_title() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_TITLE,
    'type' => 'text',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
  ));

  return $field;
}

/**
 * Adds body field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_body($bundle, $field_label) {
  $field = paragraphs_pack_get_field_body();

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
    ),
    'settings' => array('display_summary' => TRUE),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create body field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_body() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_BODY,
    'type' => 'text_long',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
  ));

  return $field;
}

/**
 * Adds items field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_items($bundle, $field_label, $target_type = 'node') {
  $field = paragraphs_pack_get_field_items($target_type);

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs_pack',
        'settings' => array(
          'entity_type' => $target_type,
        ),
        'type' => PP_FORMATTER_VIEW_MODE,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'module' => 'paragraphs_pack',
        'settings' => array(
          'entity_type' => $target_type,
        ),
        'type' => PP_FORMATTER_VIEW_MODE,
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create items field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @param string $target_type
 *   An entity type that should be allowed as items input.
 * @return array
 *   An array containing field values.
 */
function paragraphs_pack_get_field_items($target_type = 'node') {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_ITEMS . '_' . $target_type,
    'type' => 'entityreference',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'settings' => array(
      'target_type' => $target_type,
    ),
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
  ));

  return $field;
}

/**
 * Adds view mode field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @param $entity_type
 *   An entity type which view modes are displayed.
 * @return array
 *   An view mode field instance.
 */
function paragraphs_pack_add_field_view_mode($bundle, $field_label, $entity_type = 'node') {
  $field = paragraphs_pack_get_field_view_mode();

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'settings' => array(
      'entity_type' => $entity_type,
    ),
    'required' => TRUE,
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -10,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -10,
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create view mode field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_view_mode() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_VIEW_MODE,
    'type' => PP_FIELD_TYPE_VIEW_MODE,
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'cardinality' => 1,
  ));

  return $field;
}

/**
 * Adds file field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param string $field_label
 *   A label of the field.
 * @param array $settings
 *   An instance settings that overrides default settings. Default settings are
 *   commented in this function, so all the options can be found there.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_file($bundle, $field_label, $settings) {
  $field = paragraphs_pack_get_field_file();

  // Default settings with all possible options.
  $settings_default = array(
    'file_extensions' => 'png jpg',
      // 'max_filesize' => '50 MB',
      // 'file_directory' => 'optional_file_directory',
      // 'description_field' => 0,
      // 'user_register_form' => FALSE,
  );

  // Add default settings if some options are missing
  $settings += $settings_default;

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'required' => 1,
    'settings' => $settings,
  ));

  return $instance;
}

/**
 * Get/Create file field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @param string $uri_scheme
 *   A name of a scheme (private/public).
 * @return array
 *   An array containing field values.
 */
function paragraphs_pack_get_field_file($uri_scheme = '') {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_FILE,
    'type' => 'file',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'cardinality' => -1,
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => variable_get('file_default_scheme', 'public'),
    ),
  ));

  if (!empty($uri_scheme)) {
    $field['settings']['uri_scheme'] = $uri_scheme;
  }

  return $field;
}

/**
 * Adds image field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param string $field_label
 *   A label of the field.
 * @param array $settings
 *   An instance settings that overrides default settings. Default settings are
 *   commented in this function, so all the options can be found there.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_image($bundle, $field_label, $settings = array()) {
  $field = paragraphs_pack_get_field_image();

  // Default settings with all possible options.
  $settings_default = array(
    //'file_extensions' => 'png jpg',
    // 'max_filesize' => '50 MB',
    // 'file_directory' => 'optional_file_directory',
    // 'description_field' => 0,
    // 'user_register_form' => FALSE,
  );

  // Add default settings if some options are missing
  $settings += $settings_default;

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'required' => TRUE,
    'settings' => $settings,
  ));

  return $instance;
}

/**
 * Get/Create image field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @param string $uri_scheme
 *   A name of a scheme (private/public).
 * @return array
 *   An array containing field values.
 */
function paragraphs_pack_get_field_image($uri_scheme = '') {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_IMAGE,
    'type' => 'image',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'settings' => array(
      'uri_scheme' => variable_get('file_default_scheme', 'public'),
    ),
  ));

  if (!empty($uri_scheme)) {
    $field['settings']['uri_scheme'] = $uri_scheme;
  }

  return $field;
}

/**
 * Adds expand field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_expand($bundle, $field_label) {
  $field = paragraphs_pack_get_field_expand();

  $instance = _paragraphs_pack_add_field(array(
    'bundle' => $bundle,
    'entity_type' => PP_PARAGRAPH_TYPE,
    'field_name' => $field['field_name'],
    'label' => $field_label,
    'display' => array(
      'default' => array(
        'type' => 'hidden',
      ),
      'paragraphs_editor_preview' => array(
        'type' => 'hidden',
      ),
    ),
    'widget' => array(
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  ));

  return $instance;
}

/**
 * Get/Create expand field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_expand() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_EXPAND,
    'type' => 'list_boolean',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'cardinality' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'contained',
        1 => 'expand',
      ),
    ),
  ));

  return $field;
}

/**
 * Adds/Create field instance of PP_PARAGRAPH_TYPE.
 *
 * Helper function.
 *
 * @param array $instance
 *   An array of instance settings.
 * @return array
 *   An instance.
 */
function _paragraphs_pack_add_field($instance) {
  // Check if the instance exists already.
  $instance_info = field_info_instance(PP_PARAGRAPH_TYPE, $instance['field_name'], $instance['bundle']);
  if (empty($instance_info)) {
    field_create_instance($instance);
  }

  return $instance_info;
}

/**
 * Get/Create field by $field settings.
 *
 * Helper function.
 *
 * @param array $field
 *   An array of field settings.
 * @return array
 *   A field.
 */
function _paragraphs_pack_get_field($field) {
  // Check if the field exists already.
  $field_info = field_info_field($field['field_name']);
  if (empty($field_info)) {
    $field_info = field_create_field($field);
  }

  return $field_info;
}
