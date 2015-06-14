<?php
/**
 * Technically this is considered a "development" system in the SOW/RFP.
 *
 * All staging settings possible should mimic those of production for maximum
 *   similarities for testing.
 */

/**
 * Add the production settings to ensure maximum consistency.
 */
if (file_exists(DRUPAL_ROOT . '/sites/all/settings/prod.settings.php')) {
	include_once DRUPAL_ROOT . '/sites/all/settings/prod.settings.php';
}

# Testing for emails
//$conf['mail_system'] = array('default-system' => 'HelperDebugMailLog');

# Unlike Production, we don't want spiders here.
$conf['robotstxt'] = 'User-agent: *
Disallow: /';

# Environment Indicator
$conf['environment_indicator_overwritten_name'] = 'Environment: STAGE';
$conf['environment_indicator_overwritten_color'] = '#cbb311';
$conf['environment_indicator_overwrite'] = TRUE;
$conf['environment_indicator_overwritten_position'] = 'top';
$conf['environment_indicator_overwritten_fixed'] = FALSE;

// Diable GA tracking on this environment.
$conf['googleanalytics_account'] = "UA-XXXXXXX-X";
