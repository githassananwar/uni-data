<?php
/* @var $this EventServicesController */
/* @var $model EventServices */

$this->breadcrumbs=array(
	'Event Services'=>array('index'),
	$model->id,
);

$this->menu=array(
	array('label'=>'List EventServices', 'url'=>array('index')),
	array('label'=>'Create EventServices', 'url'=>array('create')),
	array('label'=>'Update EventServices', 'url'=>array('update', 'id'=>$model->id)),
	array('label'=>'Delete EventServices', 'url'=>'#', 'linkOptions'=>array('submit'=>array('delete','id'=>$model->id),'confirm'=>'Are you sure you want to delete this item?')),
	array('label'=>'Manage EventServices', 'url'=>array('admin')),
);
?>

<h1>View EventServices #<?php echo $model->id; ?></h1>

<?php $this->widget('zii.widgets.CDetailView', array(
	'data'=>$model,
	'attributes'=>array(
		'id',
		'vendor_service_id',
		'event_id',
		'status',
	),
)); ?>
