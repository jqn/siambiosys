<?php

/**
 * @file
 * API documentation for the entity_background module.
 */

/**
 * Alter the selector items.
 *
 * @param array $selectors
 *   An array of selector classes.
 *
 * @see entity_background_selectors()
 */
function hook_entity_background_selectors_alter(&$selectors) {
  $selectors['node'] = 'custom-node-';
}
