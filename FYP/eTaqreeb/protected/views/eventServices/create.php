<?php
/* @var $this EventServicesController */
/* @var $model EventServices */

$this->breadcrumbs=array(
	'Event Services'=>array('index'),
	'Create',
);

$this->menu=array(
	array('label'=>'List EventServices', 'url'=>array('index')),
	array('label'=>'Manage EventServices', 'url'=>array('admin')),
);
?>

<h1>Create EventServices</h1>

<?php $this->renderPartial('_form', array('model'=>$model)); ?>