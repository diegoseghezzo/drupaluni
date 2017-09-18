<?php
/**
 * @file
 * ct_video.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_video_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_link_video_youtube'.
  $field_bases['field_link_video_youtube'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_link_video_youtube',
    'indexes' => array(
      'video_id' => array(
        0 => 'video_id',
      ),
    ),
    'locked' => 0,
    'module' => 'youtube',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'youtube',
  );

  return $field_bases;
}
