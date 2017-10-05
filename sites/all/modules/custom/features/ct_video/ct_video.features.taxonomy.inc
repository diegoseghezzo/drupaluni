<?php
/**
 * @file
 * ct_video.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ct_video_taxonomy_default_vocabularies() {
  return array(
    'emocion' => array(
      'name' => 'Emocion',
      'machine_name' => 'emocion',
      'description' => 'Campo utilizado para categorizar contenido segun emociones',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
