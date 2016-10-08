<?php
/* @var $this RatingController */
/* @var $model Rating */
/* @var $form CActiveForm */
?>

<div class="form">

<?php $form=$this->beginWidget('CActiveForm', array(
	'id'=>'rating-form',
	// Please note: When you enable ajax validation, make sure the corresponding
	// controller action is handling ajax validation correctly.
	// There is a call to performAjaxValidation() commented in generated controller code.
	// See class documentation of CActiveForm for details on this.
	'enableAjaxValidation'=>false,
)); ?>

	<p class="note">Fields with <span class="required">*</span> are required.</p>

	<?php echo $form->errorSummary($model); ?>

	<div class="row">
		<?php echo $form->labelEx($model,'id'); ?>
		<?php echo $form->textField($model,'id'); ?>
		<?php echo $form->error($model,'id'); ?>
	</div>

	<div class="row">
		<?php echo $form->labelEx($model,'vendor_id'); ?>
		<?php echo $form->textField($model,'vendor_id'); ?>
		<?php echo $form->error($model,'vendor_id'); ?>
	</div>

	<div class="row">
		<?php echo $form->labelEx($model,'noOfRatings'); ?>
		<?php echo $form->textField($model,'noOfRatings'); ?>
		<?php echo $form->error($model,'noOfRatings'); ?>
	</div>

	<div class="row">
		<?php echo $form->labelEx($model,'rating'); ?>
		<?php echo $form->textField($model,'rating'); ?>
		<?php echo $form->error($model,'rating'); ?>
	</div>

	<div class="row buttons">
		<?php echo CHtml::submitButton($model->isNewRecord ? 'Create' : 'Save'); ?>
	</div>

<?php $this->endWidget(); ?>

</div><!-- form -->