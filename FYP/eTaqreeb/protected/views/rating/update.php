<?php
/* @var $this RatingController */
/* @var $model Rating */

$this->breadcrumbs=array(
	'Ratings'=>array('index'),
	$model->id=>array('view','id'=>$model->id),
	'Update',
);

$this->menu=array(
	array('label'=>'List Rating', 'url'=>array('index')),
	array('label'=>'Create Rating', 'url'=>array('create')),
	array('label'=>'View Rating', 'url'=>array('view', 'id'=>$model->id)),
	array('label'=>'Manage Rating', 'url'=>array('admin')),
);
?>

<h1>Update Rating <?php echo $model->id; ?></h1>

<?php $this->renderPartial('_form', array('model'=>$model)); ?>