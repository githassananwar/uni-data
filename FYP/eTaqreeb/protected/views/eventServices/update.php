<?php
/* @var $this EventServicesController */
/* @var $model EventServices */

$this->breadcrumbs=array(
	'Event Services'=>array('index'),
	$model->id=>array('view','id'=>$model->id),
	'Update',
);

$this->menu=array(
	array('label'=>'List EventServices', 'url'=>array('index')),
	array('label'=>'Create EventServices', 'url'=>array('create')),
	array('label'=>'View EventServices', 'url'=>array('view', 'id'=>$model->id)),
	array('label'=>'Manage EventServices', 'url'=>array('admin')),
);
?>

<h1>Update EventServices <?php echo $model->id; ?></h1>

<?php $this->renderPartial('_form', array('model'=>$model)); ?>