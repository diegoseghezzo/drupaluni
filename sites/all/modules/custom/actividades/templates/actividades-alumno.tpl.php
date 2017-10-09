<div id="actividades-alumno-wrapper">
	<h3>Mis actividades</h3>
	<?php if (!empty($actividades)): ?>
	  <?php foreach ($actividades as $actividad): ?>
	  	<div class="actividad">
	  	  <div class="titulo"><?php echo $actividad['link_actividad']; ?></div>
	  	  <div class="fecha"><?php echo $actividad['fecha_limite']; ?></div>
	  	  <div class="estado"><?php echo $actividad['estado']; ?></div>
	  	  <?php if (!empty($actividad['puntuacion'])): ?>
	  	  	<div class="puntuacion"><?php echo $actividad['puntuacion']; ?></div>
	  	  <?php endif; ?>
	  	</div>
	  <?php endforeach; ?>
    <?php endif; ?>
</div>
