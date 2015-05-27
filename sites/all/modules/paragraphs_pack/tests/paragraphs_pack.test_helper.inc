<?php

/**
 * @file
 * Paragraphs pack content module's tests.
 */

/**
 * Class ParagraphsPackWebTestCase
 *
 * Extends DrupalWebTestCase by field existence check method.
 */
class ParagraphsPackWebTestCase extends DrupalWebTestCase {

  /**
   * Check if the bundle exists.
   *
   * @param string $bundle
   *   The bundle name.
   */
  function check_bundle_existence($bundle) {
    $content_bundle_loaded = (paragraphs_bundle_load($bundle) != FALSE);

    $this->assertTrue($content_bundle_loaded, t('Paragraph "@paragraph_bundle" bundle was successfully created.', array(
      '@paragraph_bundle' => $bundle,
    )));
  }

  /**
   * Check if the field base and its instance exist.
   *
   * @param string $field_name
   *   A name of the field.
   * @param string $field_bundle
   *   The bundle name for the field instance.
   */
  function check_field_existence($field_name, $field_bundle) {
    $field = field_info_field($field_name);
    $this->assertTrue(!empty($field), t('Field "@paragraph_field" exists.', array(
      '@paragraph_field' => $field_name,
    )));

    $instance = field_info_instance(PP_PARAGRAPH_TYPE, $field_name, $field_bundle);
    $this->assertTrue(!empty($instance), t('Paragraph "@paragraph_bundle" bundle contains "@paragraph_field" field instance.', array(
      '@paragraph_bundle' => $field_bundle,
      '@paragraph_field' => $field_name,
    )));
  }

}

/**
 * Class ParagraphsPackWebTestCase
 *
 * Extends DrupalWebTestCase by .
 */
class ParagraphsPackFeatureWebTestCase extends DrupalWebTestCase {

  /**
   *
   * @param string $entity_type
   *   The specified entity type.
   */
  function check_view_mode_options($entity_type = 'node') {
    // Prepare page for testing.
    $this->load_create_new_content_page();
    $this->click_add_paragraph_button();

    // Get view mode options.
    $select_element = $this->check_paragraphs_select_element_existence();
    if ($select_element == FALSE) {
      // There's nothing more to test if the element doesn't exist.
      return;
    }

    $options = $this->get_options_machine_names($select_element);

    // Do the testing.
    $this->validate_view_mode_options($entity_type, $options);
  }

  /**
   * Load the page for creating new content (Landing page in this case).
   */
  function load_create_new_content_page() {
    $new_landing_page_path = 'node/add/pp-test-landing-page';
    $this->drupalGet($new_landing_page_path);
  }

  /**
   * Click 'Add a Paragraph' button.
   */
  function click_add_paragraph_button() {
    $button_name = 'field_pp_test_paragraphs_add_more_add_more';
    $this->drupalPostAJAX(NULL, array(), $button_name);
  }

  /**
   * Check paragraphs select element existence.
   *
   * @return object
   *  Returns the paragraphs select element or FALSE if element wasn't found.
   */
  function check_paragraphs_select_element_existence() {
    $xpath_view_mode_name = '@name=\'field_pp_test_paragraphs[' . LANGUAGE_NONE . '][0][' . PP_FIELD_VIEW_MODE . '][' . LANGUAGE_NONE . ']\'';
    $xpath_view_mode = "//input[$xpath_view_mode_name]|//select[$xpath_view_mode_name]";

    // Get view mode field options.
    $elements = $this->xpath($xpath_view_mode);
    $this->assertTrue(!empty($elements), t('View mode options exists.'));

    // For non existing paragraphs select element return FALSE
    if (empty($elements)) {
      return FALSE;
    }

    return reset($elements);
  }

  /**
   * Get all options machine names.
   *
   * @param object $select_element
   *   A select element.
   * @return array
   *   An array of options machine names.
   */
  function get_options_machine_names($select_element) {
    $options = $this->getAllOptions($select_element);
    $options_machine_names = array();
    foreach ($options as $option) {
      $options_machine_names[] = (string) $option->attributes()->value;
    }

    return $options_machine_names;
  }

  /**
   * Validate if all correct view modes are present.
   *
   * @param string $entity_type
   *   The specified entity type.
   * @param array $view_modes
   *   An array of view modes to validate.
   */
  function validate_view_mode_options($entity_type, $view_modes) {
    $all_view_modes_are_present = TRUE;
    foreach (paragraphs_pack_get_entity_type_view_modes($entity_type) as $machine_name => $label) {
      if (!in_array($machine_name, $view_modes)) {
        $all_view_modes_are_present = FALSE;
      }
    }

    $this->assertTrue($all_view_modes_are_present, t('All correct view modes are present.'));
  }

}
