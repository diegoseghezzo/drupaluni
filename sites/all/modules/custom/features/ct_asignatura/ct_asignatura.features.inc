<?php
/**
 * @file
 * ct_asignatura.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ct_asignatura_node_info() {
  $items = array(
    'asignatura' => array(
      'name' => t('Asignatura'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
