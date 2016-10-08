<?php
/* @var $this RatingController */
/* @var $model Rating */

$this->breadcrumbs=array(
	'Ratings'=>array('index'),
	'Create',
);

$this->menu=array(
	array('label'=>'List Rating', 'url'=>array('index')),
	array('label'=>'Manage Rating', 'url'=>array('admin')),
);
?>

<h1>Create Rating</h1>

<?php $this->renderPartial('_form', array('model'=>$model)); ?>