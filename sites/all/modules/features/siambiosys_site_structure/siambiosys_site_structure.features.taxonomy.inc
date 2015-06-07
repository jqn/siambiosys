<?php
/**
 * @file
 * siambiosys_site_structure.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function siambiosys_site_structure_taxonomy_default_vocabularies() {
  return array(
    'catalog' => array(
      'name' => 'Catalog',
      'machine_name' => 'catalog',
      'description' => 'Taxonomy Product Filter',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'doctrine' => array(
      'name' => 'Doctrine',
      'machine_name' => 'doctrine',
      'description' => 'Different artistic skills.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'influence_type' => array(
      'name' => 'Influence Type',
      'machine_name' => 'influence_type',
      'description' => 'Types of influences, direct, artistic, cultural.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
