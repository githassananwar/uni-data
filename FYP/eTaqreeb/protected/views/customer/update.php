<?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
	
?>

<?php
/* @var $this CustomerController */
/* @var $model Customer */

?>


<h3 class="page-header" style="text-align:center">Update Profile</h3>

<?php $this->renderPartial('_form', array('model'=>$model

	)); ?>


	<?php }

else 
{
  $this->redirect(array('site/index'));
  die('Direct Access not permitted');
}

?>