<?php
/**
 * @file
 * siambiosys_users.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function siambiosys_users_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_to_dashboard'] = entity_import('rules_config', '{ "rules_redirect_to_dashboard" : {
      "LABEL" : "Redirect to Dashboard",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "admin" } } ]
    }
  }');
  return $items;
}
