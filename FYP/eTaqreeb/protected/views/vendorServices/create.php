<?php
/* @var $this VendorServicesController */
/* @var $model VendorServices */

$this->breadcrumbs=array(
	'Vendor Services'=>array('index'),
	'Create',
);

$this->menu=array(
	array('label'=>'List VendorServices', 'url'=>array('index')),
	array('label'=>'Manage VendorServices', 'url'=>array('admin')),
);
?>

<h1>Create VendorServices</h1>

<?php $this->renderPartial('_form', array('model'=>$model)); ?>