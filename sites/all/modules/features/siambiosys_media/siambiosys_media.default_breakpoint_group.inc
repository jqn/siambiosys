<?php
/**
 * @file
 * siambiosys_media.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function siambiosys_media_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'siambiosys';
  $breakpoint_group->name = 'Siambiosis Custom Theme';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.siambiosys.tv',
    1 => 'breakpoints.theme.siambiosys.wide',
    2 => 'breakpoints.theme.siambiosys.narrow',
    3 => 'breakpoints.theme.siambiosys.mobile',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['siambiosys'] = $breakpoint_group;

  return $export;
}
