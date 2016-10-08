<?php
/* @var $this EventServicesController */
/* @var $dataProvider CActiveDataProvider */

$this->breadcrumbs=array(
	'Event Services',
);

$this->menu=array(
	array('label'=>'Create EventServices', 'url'=>array('create')),
	array('label'=>'Manage EventServices', 'url'=>array('admin')),
);
?>

<h1>Event Services</h1>

<?php $this->widget('zii.widgets.CListView', array(
	'dataProvider'=>$dataProvider,
	'itemView'=>'_view',
)); ?>
