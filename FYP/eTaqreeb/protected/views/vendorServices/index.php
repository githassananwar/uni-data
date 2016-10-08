<?php
/* @var $this VendorServicesController */
/* @var $dataProvider CActiveDataProvider */

$this->breadcrumbs=array(
	'Vendor Services',
);

$this->menu=array(
	array('label'=>'Create VendorServices', 'url'=>array('create')),
	array('label'=>'Manage VendorServices', 'url'=>array('admin')),
);
?>

<h1>Vendor Services</h1>

<?php $this->widget('zii.widgets.CListView', array(
	'dataProvider'=>$dataProvider,
	'itemView'=>'_view',
)); ?>
