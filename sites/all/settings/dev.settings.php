<?php
/**
 * This file stores all settings that should be used on development sites.
 */
global $conf;

# Environment Indicator
$conf['environment_indicator_overwritten_name'] = 'Environment: DEV';
$conf['environment_indicator_overwritten_color'] = '#FF8F32';
$conf['environment_indicator_overwrite'] = TRUE;
$conf['environment_indicator_overwritten_position'] = 'top';
$conf['environment_indicator_overwritten_fixed'] = FALSE;


# Disable various caches.
// Since we're using this in acquia's cloud, enable the caches so we
// can test some of the varnish caching stuff.
$conf['cache'] = FALSE;
$conf['block_cache'] = FALSE;
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;

# Don't run poor-man's cron locally.
$conf['cron_safe_threshold'] = 0;

# Secure pages.
$conf['securepages_enable'] = FALSE;

# Don't allow sending mail.
$conf['maillog_send'] = FALSE;

# Show notices.
$conf['error_level'] = 2;

# Robots disable Staging, development
$conf['robotstxt'] = 'User-agent: *
Disallow: /';

// Disable GA tracking on this environment.
$conf['googleanalytics_account'] = "UA-XXXXXXX-X";
