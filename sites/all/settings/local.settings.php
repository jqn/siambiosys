<?php

/**
 * This file is not actually used, it's just an example of what to do.
 *
 * To use this file:
 *   1. Copy it into your sites/all/settings directory as local.settings.php.
 *   2. Tweak as necessary.
 */

global $conf;

/**
 * Set the environment type.
 *
 * Allowed values are 'dev', 'stage', and 'prod'.
 *
 * These in turn include the respective xxxx.settings.php file
 *   located in sites/all/settings/.
 */
$conf['drupal_env'] = 'local';

/**
 * Each site needs to maintain it's own database configuration.
 *
 * MUST be above all.settings.php include because of domain.module.
 */
$databases = array();
$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'db578048223',
  'username' => 'dbo578048223',
  'password' => 'PurpleNurple12',
  'host' => 'db578048223.db.1and1.com',
  'prefix' =>'', 
);

/**
 * Include the main settings.php file for the system.
 */
if (file_exists(DRUPAL_ROOT .'/sites/all/settings/all.settings.php')) {
  include_once DRUPAL_ROOT .'/sites/all/settings/all.settings.php';
}

