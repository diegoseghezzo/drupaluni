<div id="cuestionarios-alumno-wrapper">
  <h3>Mis cuestionarios</h3>
  <?php if (!empty($cuestionarios)): ?>
    <?php foreach ($cuestionarios as $cuestionario): ?>
      <div class="cuestionario">
        <div class="titulo"><?php echo $cuestionario['link_cuestionario']; ?></div>
        <div class="estado"><?php echo $cuestionario['estado']; ?></div>
      </div>
    <?php endforeach; ?>
    <?php endif; ?>
</div>
