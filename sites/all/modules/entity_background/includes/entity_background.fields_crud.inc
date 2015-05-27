<?php

/**
 * @file
 * Fields CRUD functions.
 */

/**
 * Creates eb_background field instance.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param $bundle
 *   A bundle for the instance.
 * @param $field_label
 *   A field label.
 * @return array
 *   An instance information array.
 */
function entity_background_add_field_eb_background($entity_type, $bundle, $field_label) {
  $field = entity_background_get_field_eb_background();

  $instance = _entity_background_add_field($entity_type, array(
    'bundle' => $bundle,
    'entity_type' => $entity_type,
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
      'type' => 'field_collection_embed',
      'settings' => array(),
      'weight' => 3,
    ),
  ));

  return $instance;
}

/**
 * Create eb_background field.
 *
 * @return array
 *   An field information array.
 */
function entity_background_get_field_eb_background() {
  $field = _entity_background_get_field(array(
    'field_name' => EB_FIELD,
    'type' => 'field_collection',
    'cardinality' => 1
  ));
  return $field;
}

/**
 * Creates eb_selection field instance.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param $bundle
 *   A bundle for the instance.
 * @param $field_label
 *   A field label.
 * @return array
 *   An instance information array.
 */
function entity_background_add_field_eb_selection($entity_type, $bundle, $field_label) {
  $field = entity_background_get_field_eb_selection();

  $instance = _entity_background_add_field($entity_type, array(
    'bundle' => $bundle,
    'entity_type' => $entity_type,
    'field_name' => $field['field_name'],
    'label' => $field_label,
    'display' => array(
      'default' => array(
        'type' => 'hidden',
      ),
    ),
    'widget' => array(
      'type' => 'options_select',
      'weight' => -50,
    ),
  ));

  return $instance;
}

/**
 * Create eb_selection field.
 *
 * @return array
 *   An field information array.
 */
function entity_background_get_field_eb_selection() {
  $field = _entity_background_get_field(array(
    'field_name' => EB_SELECTION_FIELD,
    'type' => 'list_text',
    'cardinality' => 1,
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'entity_background_selection_list',
    ),
  ));
  return $field;
}

/**
 * Callback function used in list_text select list.
 *
 * @return array
 *   An array of all list options.
 */
function entity_background_selection_list() {
  $groups = field_group_read_groups();
  $options = array();

  if (!empty($groups[EB_FC_ENTITY][EB_FIELD]['form'])) {
    $group_list = $groups[EB_FC_ENTITY][EB_FIELD]['form'];
    foreach ($group_list as $name => $group) {
      $options[$name] = $group->label;
    }
  }

  return $options;
}

/**
 * Creates image field instance.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param $bundle
 *   A bundle for the instance.
 * @param $field_name
 *  A field name.
 * @param $field_label
 *   A field label.
 * @param $cardinality
 *   Cardinality of the field. Set to 1 by default.
 * @param array $settings
 *   An image settings array. Allows to set file options.
 * @return array
 *   An instance information array.
 */
function entity_background_add_field_image($entity_type, $bundle, $field_name, $field_label, $cardinality = 1, $settings = array()) {
  $field = entity_background_get_field_image($field_name, $cardinality);

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

  $instance = _entity_background_add_field($entity_type, array(
    'field_name' => $field['field_name'],
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $field_label,
    'required' => FALSE,
    'display' => array(
      'default' => array(
        'type' => 'hidden',
      ),
    ),
    'settings' => $settings,
  ));

  return $instance;
}

/**
 * Create image field.
 *
 * @param $field_name
 *   A field name.
 * @param $cardinality
 *   Cardinality of the field. Set to 1 by default.
 * @param string $uri_scheme
 *   A name of a scheme (private/public).
 * @return array
 *   An field information array.
 */
function entity_background_get_field_image($field_name, $cardinality = 1, $uri_scheme = '') {
  $field = _entity_background_get_field(array(
    'field_name' => $field_name,
    'type' => 'image',
    'cardinality' => $cardinality,
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
 * Create text field instance.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param $bundle
 *   A bundle for the instance.
 * @param $field_name
 *  A field name.
 * @param $field_label
 *   A field label.
 * @return array
 *   An instance information array.
 */
function entity_background_add_field_text($entity_type, $bundle, $field_name, $field_label) {
  $field = entity_background_get_field_text($field_name);

  $instance = _entity_background_add_field($entity_type, array(
    'bundle' => $bundle,
    'entity_type' => $entity_type,
    'field_name' => $field['field_name'],
    'label' => $field_label,
    'display' => array(
      'default' => array(
        'type' => 'hidden',
      ),
    ),
    'widget' => array(
      'type' => 'text_textfield',
    ),
  ));

  return $instance;
}

/**
 * Create text field.
 *
 * @param $field_name
 *   A field name.
 * @return array
 *   An field information array.
 */
function entity_background_get_field_text($field_name) {
  $field = _entity_background_get_field(array(
    'field_name' => $field_name,
    'type' => 'text',
    'cardinality' => 1,
  ));

  return $field;
}

/**
 * Creates color field instance.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param $bundle
 *   A bundle for the instance.
 * @param $field_name
 *  A field name.
 * @param $field_label
 *   A field label.
 * @param $cardinality
 *   Cardinality of the field. Set to 1 by default.
 * @param array $settings
 *   An instance information array.
 */
function entity_background_add_field_color($entity_type, $bundle, $field_name, $field_label, $cardinality = 1) {
  $field = entity_background_get_field_color($field_name, $cardinality);

  $instance = _entity_background_add_field($entity_type, array(
    'field_name' => $field['field_name'],
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $field_label,
    'required' => FALSE,
    'display' => array(
      'default' => array(
        'type' => 'hidden',
      ),
    ),
    'widget' => array(
      'type' => 'jquery_colorpicker',
      'module' => 'jquery_colorpicker',
    ),
  ));

  return $instance;
}

/**
 * Create color field.
 *
 * @param $field_name
 *   A field name.
 * @param $cardinality
 *   Cardinality of the field. Set to 1 by default.
 * @return array
 *   An field information array.
 */
function entity_background_get_field_color($field_name, $cardinality = 1) {
  $field = _entity_background_get_field(array(
    'field_name' => $field_name,
    'type' => 'jquery_colorpicker',
    'cardinality' => $cardinality,
  ));

  return $field;
}

/**
 * Creates list text field instance.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param $bundle
 *   A bundle for the instance.
 * @param $field_name
 *   A field name.
 * @param $field_label
 *   A field label.
 * @param array $settings
 *   An list text field settings array. Allows to set allowed values.
 *
 * @return array
 *   An instance information array.
 */
function entity_background_add_field_list_text($entity_type, $bundle, $field_name, $field_label, $settings = array()) {
  $field = entity_background_get_field_list_text($field_name, $settings);

  $instance = _entity_background_add_field($entity_type, array(
    'bundle' => $bundle,
    'entity_type' => $entity_type,
    'field_name' => $field['field_name'],
    'label' => $field_label,
    'display' => array(
      'default' => array(
        'type' => 'hidden',
      ),
    ),
    'widget' => array(
      'type' => 'options_select',
    ),
  ));

  return $instance;
}

/**
 * Create list text field.
 *
 * @param $field_name
 *   A field name.
 * @param array $settings
 *   An list text field settings array. Allows to set allowed values.
 *
 * @return array
 *   An field information array.
 */
function entity_background_get_field_list_text($field_name, $settings = array()) {
  // Default settings with all possible options.
  $settings_default = array(
    'allowed_values' => array(),
    'allowed_values_function' => '',
  );

  // Add default settings if some options are missing.
  $settings += $settings_default;

  $field = _entity_background_get_field(array(
    'field_name' => $field_name,
    'type' => 'list_text',
    'cardinality' => 1,
    'settings' => $settings,
  ));
  return $field;
}

/**
 * Adds/Create field instance of PP_PARAGRAPH_TYPE.
 *
 * Helper function.
 *
 * @param type $entity_type
 *   An entity type for the instance.
 * @param array $instance
 *   An array of instance settings.
 * @return array
 *   An field instance.
 */
function _entity_background_add_field($entity_type, $instance) {
  // Check if the instance exists already.
  $instance_info = field_info_instance($entity_type, $instance['field_name'], $instance['bundle']);
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
function _entity_background_get_field($field) {
  // Check if the field exists already.
  $field_info = field_info_field($field['field_name']);
  if (empty($field_info)) {
    $field_info = field_create_field($field);
  }

  return $field_info;
}
