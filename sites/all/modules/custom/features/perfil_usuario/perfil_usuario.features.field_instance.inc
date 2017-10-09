<?php
/**
 * @file
 * perfil_usuario.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function perfil_usuario_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_asignatura'.
  $field_instances['user-user-field_asignatura'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_asignatura',
    'label' => 'Asignatura',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Asignatura');

  return $field_instances;
}
