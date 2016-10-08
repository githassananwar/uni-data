<!-- Start main-content -->
  <div class="main-content">
    <!-- Section: inner-header -->
    <section class="inner-header divider layer-overlay overlay-dark" data-bg-img="images/contact.jpg">
      <div class="container pt-30 pb-30">
        <!-- Section Content -->
        <div class="section-content text-center">
          <div class="row"> 
            <div class="col-md-6 col-md-offset-3 text-center">
              <h2 class="text-orange font-36">Contact</h2>
              <ol class="breadcrumb text-center mt-10 white">
                <li><a href="#">Home</a></li>
                <li class="active">Contact</li>
              </ol>
            </div>
          </div>
        </div>
      </div>      
    </section>
    
    <!-- Divider: Google map -->
    <section id="contact" class="divider" data-bg-color="#fff">
      <div class="container pb-30">
        <div class="row">
          <div class="col-sm-5 col-md-3">
            <img src="images/office_building.jpg" alt="">
          </div>
          <div class="col-sm-7 col-md-4 pl-60">
            <h4 class="text-uppercase">Get In Touch</h4>
            <div class="line-bottom mb-30"></div>
            <ul class="list-default footer-contact">
              <li><i class="fa fa-phone"></i>+92 324 4563233</li>
              <li><i class="fa fa-envelope"></i>contact@eTaqreeb.com</li>
              <li><i class="fa fa-globe"></i>www.eTaqreeb.com</li>
              <li><i class="fa fa-clock-o"></i>Mon-Fri 9.00am-5.00pm</li>
              <li><i class="fa fa-map-marker"></i>Tricon Corporate Centre, Jail Road, Lahore</li>
            </ul>
            <ul class="social-icons icon-blue small m-0 mt-30 mb-30">
              <li><a href="#"><i class="fa fa-facebook"></i></a></li>
              <li><a href="#"><i class="fa fa-twitter"></i></a></li>
              <li><a href="#"><i class="fa fa-google-plus"></i></a></li>
              <li><a href="#"><i class="fa fa-youtube"></i></a></li>
              <li><a href="#"><i class="fa fa-instagram"></i></a></li>
            </ul>
          </div>
          <div class="col-sm-12 col-md-5">
            <h4 class="text-uppercase">Find Our Location</h4>
            <div class="line-bottom mb-30"></div>
            <div class="map-canvas autoload-map" data-height="200" data-address="Tricon Corporate Centre, Jail Road, Lahore" data-zoom="14" data-mapstyle="style2" data-marker="images/map-icon-blue.png"></div>
          </div>
        </div>
      </div>
    </section>
	<?php
/* @var $this SiteController */
/* @var $model ContactForm */
/* @var $form CActiveForm */

$this->pageTitle=Yii::app()->name . 'Contact Us';
$this->breadcrumbs=array(
	'Contact',
);
?>

<h2 align="center">Drop Your Message</h2>

<?php if(Yii::app()->user->hasFlash('contact')): ?>

<div class="flash-success">
	<?php echo Yii::app()->user->getFlash('contact'); ?>
</div>

<?php else: ?>

<?php $form=$this->beginWidget('CActiveForm', array(
	'id'=>'contact-form',
	'enableClientValidation'=>true,
	'clientOptions'=>array(
		'validateOnSubmit'=>true,
	),
)); ?>
<?php echo $form->errorSummary($model); ?>


    <!-- Divider: Contact form -->
    <section>
      <div class="container pt-0">
        <div class="row">
          <div class="col-md-12">
            <h4 class="text-uppercase">Send Us a Messase</h4>
            <div class="line-bottom mb-30"></div>
            <form id="contact-form" class="contact-form-transparent mb-0 mb-sm-60">
              <div class="row">
                <div class="col-sm-12">
                  <div class="form-group">
				  <?php echo $form->textField($model,'name',['class'=>'form-control','placeholder'=>'Enter Name']); ?>
                    
                  </div>
                </div>
                <div class="col-sm-6">
                  <div class="form-group">
				  <?php echo $form->textField($model,'email',['class'=>'form-control','placeholder'=>'Enter Email']); ?>
                    
                  </div>
                </div>
                <div class="col-sm-6">
                  <div class="form-group">
				  <?php echo $form->textField($model,'subject',['class'=>'form-control','placeholder'=>'Enter Subject']); ?>
                    
                  </div>
                </div>
              </div>
              <div class="form-group">
			  <?php echo $form->textArea($model,'body',['class'=>'form-control','placeholder'=>'Enter Message']); ?>
                
              </div>
			  <div class="form-group">
			  <?php if(CCaptcha::checkRequirements()): ?>
		<?php echo $form->labelEx($model,'verifyCode'); ?>
		<div>
		<?php $this->widget('CCaptcha'); ?>
		<?php echo $form->textField($model,'verifyCode',['class'=>'form-control','placeholder'=>'Enter CCaptcha']); ?>
		</div>
		<div class="hint">Please enter the letters as they are shown in the image above.
		<br/>Letters are not case-sensitive.</div>
		<?php echo $form->error($model,'verifyCode'); ?>
	</div>
	<?php endif; ?>
			  
              <div class="form-group text-center">
                <button data-loading-text="Please wait..." class="btn btn-colored btn-rounded btn-orange pl-30 pr-30" type="submit">Send your message</button>
              </div>
            </form>
          </div>
        </div>
      </div>
    </section>
  </div>
  <!-- end main-content -->
  <?php $this->endWidget(); ?>

<?php endif; ?>

<script>
$(document).ready(function(){
  $("#signup").click(function() {
  $('#modal-donate-now').modal('hide');
  })
});

</script>