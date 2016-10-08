<?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
	
?>

<?php
/* @var $this VendorServicesController */
/* @var $model VendorServices */

$this->breadcrumbs=array(
	'Vendor Services'=>array('index'),
	$model->name=>array('view','id'=>$model->id),
	'Update',
);

?>
<h3 class="page-header" style="text-align:center">Update Service</h3>


<?php $this->renderPartial('_form', array('model'=>$model)); ?>

<?php }
else
{
  $this->redirect(array('site/index'));
  die('Direct Access not permitted');
}?>