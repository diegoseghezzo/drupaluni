<?php
/**
 * @file
 * roles_permisos.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function roles_permisos_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'corregir actividades'.
  $permissions['corregir actividades'] = array(
    'name' => 'corregir actividades',
    'roles' => array(
      'administrator' => 'administrator',
      'profesor' => 'profesor',
    ),
    'module' => 'actividades',
  );

  return $permissions;
}
