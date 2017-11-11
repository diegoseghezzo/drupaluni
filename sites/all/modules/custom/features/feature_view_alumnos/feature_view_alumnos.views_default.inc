<?php
/**
 * @file
 * feature_view_alumnos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_view_alumnos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'view_alumnos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Alumnos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Alumnos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_apellido' => 'field_apellido',
    'field_nombre' => 'field_apellido',
    'mail' => 'mail',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'field_nombre';
  $handler->display->display_options['style_options']['info'] = array(
    'field_apellido' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_nombre' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_asignatura_target_id']['id'] = 'field_asignatura_target_id';
  $handler->display->display_options['relationships']['field_asignatura_target_id']['table'] = 'field_data_field_asignatura';
  $handler->display->display_options['relationships']['field_asignatura_target_id']['field'] = 'field_asignatura_target_id';
  $handler->display->display_options['relationships']['field_asignatura_target_id']['label'] = 'Asignatura Usuario';
  /* Campo: Usuario: Apellido */
  $handler->display->display_options['fields']['field_apellido']['id'] = 'field_apellido';
  $handler->display->display_options['fields']['field_apellido']['table'] = 'field_data_field_apellido';
  $handler->display->display_options['fields']['field_apellido']['field'] = 'field_apellido';
  $handler->display->display_options['fields']['field_apellido']['element_label_colon'] = FALSE;
  /* Campo: Usuario: Nombre */
  $handler->display->display_options['fields']['field_nombre']['id'] = 'field_nombre';
  $handler->display->display_options['fields']['field_nombre']['table'] = 'field_data_field_nombre';
  $handler->display->display_options['fields']['field_nombre']['field'] = 'field_nombre';
  $handler->display->display_options['fields']['field_nombre']['element_label_colon'] = FALSE;
  /* Campo: Usuario: Correo electrónico */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_asignatura_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Asignatura';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Usuario: Apellido (field_apellido) */
  $handler->display->display_options['sorts']['field_apellido_value']['id'] = 'field_apellido_value';
  $handler->display->display_options['sorts']['field_apellido_value']['table'] = 'field_data_field_apellido';
  $handler->display->display_options['sorts']['field_apellido_value']['field'] = 'field_apellido_value';
  /* Filter criterion: Usuario: Activo */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Usuario: Asignatura (field_asignatura) */
  $handler->display->display_options['filters']['field_asignatura_target_id']['id'] = 'field_asignatura_target_id';
  $handler->display->display_options['filters']['field_asignatura_target_id']['table'] = 'field_data_field_asignatura';
  $handler->display->display_options['filters']['field_asignatura_target_id']['field'] = 'field_asignatura_target_id';
  $handler->display->display_options['filters']['field_asignatura_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_asignatura_target_id']['expose']['operator_id'] = 'field_asignatura_target_id_op';
  $handler->display->display_options['filters']['field_asignatura_target_id']['expose']['label'] = 'Asignatura';
  $handler->display->display_options['filters']['field_asignatura_target_id']['expose']['operator'] = 'field_asignatura_target_id_op';
  $handler->display->display_options['filters']['field_asignatura_target_id']['expose']['identifier'] = 'field_asignatura_target_id';
  $handler->display->display_options['filters']['field_asignatura_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_asignatura_target_id']['group_info']['label'] = 'Asignatura (field_asignatura)';
  $handler->display->display_options['filters']['field_asignatura_target_id']['group_info']['identifier'] = 'field_asignatura_target_id';
  $handler->display->display_options['filters']['field_asignatura_target_id']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_asignatura_target_id']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Usuario: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'alumnos';
  $translatables['view_alumnos'] = array(
    t('Master'),
    t('Alumnos'),
    t('more'),
    t('Apply'),
    t('Reiniciar'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Asignatura Usuario'),
    t('Apellido'),
    t('Nombre'),
    t('Correo electrónico'),
    t('Asignatura'),
    t('Asignatura (field_asignatura)'),
    t('Page'),
  );
  $export['view_alumnos'] = $view;

  return $export;
}
