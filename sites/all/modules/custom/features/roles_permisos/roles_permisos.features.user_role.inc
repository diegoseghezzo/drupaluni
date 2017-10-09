<?php
/**
 * @file
 * roles_permisos.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function roles_permisos_user_default_roles() {
  $roles = array();

  // Exported role: alumno.
  $roles['alumno'] = array(
    'name' => 'alumno',
    'weight' => 5,
  );

  // Exported role: profesor.
  $roles['profesor'] = array(
    'name' => 'profesor',
    'weight' => 4,
  );

  return $roles;
}
