<?php
/**
 * This file stores all settings that should be used on production and
 *   development sites alike.
 */

global $conf;

$conf['clean_url'] = 1;

// Enable HTTPS.
// Views UI preferences.
$conf['views_ui_show_advanced_column'] = TRUE;
$conf['views_ui_show_advanced_help_warning'] = FALSE;
$conf['views_ui_show_listing_filters'] = TRUE;
$conf['views_ui_show_sql_query'] = TRUE;
$conf['views_ui_show_performance_statistics'] = TRUE;
$conf['views_show_additional_queries'] = TRUE;

// Block update.php for anonymous users.
$update_free_access = FALSE;

ini_set('arg_separator.output',     '&amp;');
ini_set('magic_quotes_runtime',     0);
ini_set('magic_quotes_sybase',      0);
ini_set('session.cache_expire',     200000);
ini_set('session.cache_limiter',    'none');
ini_set('session.cookie_lifetime',  0);
ini_set('session.gc_maxlifetime',   200000);
ini_set('session.save_handler',     'user');
ini_set('session.use_only_cookies', 1);
ini_set('session.use_trans_sid',    0);
ini_set('url_rewriter.tags',        '');

// Security settings.
$conf['dblog_row_limit'] = 1000000;

// If maillog is enabled, pass stuff back into mimemail.
// $conf['maillog_engine'] = 'mimemail';

/**
* Set the umask so that new directories created by Drupal have the correct permissions
*/
umask(0002);

ini_set('memory_limit', '256M');

/**
 * Add the site-specific settings.
 */
// if (file_exists(DRUPAL_ROOT .'/sites/all/settings/' . $conf['drupal_env'] . '.settings.php')) {
//   include_once DRUPAL_ROOT .'/sites/all/settings/' . $conf['drupal_env'] . '.settings.php';
// }
// Fail safe, if environment isn't set correctly, we'll just assume production.
if (file_exists(DRUPAL_ROOT .'/sites/all/settings/prod.settings.php')) {
  include_once DRUPAL_ROOT .'/sites/all/settings/prod.settings.php';
}

if (file_exists(DRUPAL_ROOT .'/sites/all/settings/local.settings.php')) {
  include_once DRUPAL_ROOT .'/sites/all/settings/local.settings.php';
}
