<?php
/**
 * @file
 * universidad_granada_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function universidad_granada_rules_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_after_login'] = entity_import('rules_config', '{ "rules_redirect_after_login" : {
      "LABEL" : "Redirect after login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [ { "redirect" : { "url" : "user" } } ]
    }
  }');
  return $items;
}
