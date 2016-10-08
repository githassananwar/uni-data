<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'vendor-form',
  'htmlOptions'=>['enctype'=>'multipart/form-data'],
 ));?>
    <section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">
              <h4 class="text-uppercase mb-5">Add Service!</h4>
              <div class="line-bottom mb-20"></div>
              
                <div class="row">
                  <div class="form-group">

<div class="col-sm-12">
                  <div class="col-sm-6">
                    
                      <label>Service Name:</label>
                      <?php echo $form->textField($model,'name',['class'=>'form-control','placeholder'=>'Enter Service', 'id'=>'name']); ?>
                      <span id="name_err" style="color:red;"></span>
                    </div>
                  
          
          <div class="col-sm-6">
         
                      <label>Service Price/Head:</label>
                      <?php echo $form->textField($model,'price',['class'=>'form-control','placeholder'=>'Enter Amount(Rs)', 'id'=>'price']); ?>
                      <span id="price_err" style="color:red;"></span>
                    </div>
                   
               </div>  



           <div class="col-sm-12">

           <div class="col-sm-6">
                      <label>Service Type:</label>
                        <?php
                          $types = array('---Select---','Caterers'=>'Caterers','Venue'=>'Venue','Decorators'=>'Decorators','Photography'=>'Photography','Sound & DJ'=>'Sound & DJ','Salon & Spa'=>'Salon & Spa', 'Event Managers'=>'Event Managers', 'Other'=>'Other'); 
                          echo $form->dropDownList($model,'type',$types,['id'=>'type','class'=>'form-control','placeholder'=>'Enter Amount(Rs)']); ?>
                          <span id="type_err" style="color:red;"></span>
                    </div>


                     <div class="col-sm-6">
                      <label>Pricing:</label>
                        <?php
                          $types = array('---Select---','Per Head'=>'Per Head','Package Price'=>'Package Price'); 
                          echo $form->dropDownList($model,'pricemode',$types,['id'=>'pricemode','class'=>'form-control']); ?>
                          <span id="pricemode_err" style="color:red;"></span>
                    </div>
   
</div>


<div class="col-sm-12">
<div class="col-sm-6">
                    <div class="form-group">
                      <label>Service Image:</label>
                      <?php echo $form->fileField($model,'simage',['id'=>'serviceImage','class'=>'form-control','placeholder'=>'Image']); ?>
                      <span id="serviceImage_err" style="color:red;"></span>
                    </div>
                  </div>
</div>
          
            <!--array('empty'=>'Select Service')  after type-->

				   </div>
        </div>

            <div class="row">
             
                <div class="col-sm-12">
                  <div class="col-sm-6">
                  <button id="addService" data-loading-text="Please wait..." class="btn btn-colored btn-orange pl-30 pr-30" type="button" onclick="addServiceAJAX()" >Add</button>
                </div>
                </div>


            </div>
          </div>
          <div class="col-md-5">
          </div>
        </div>
      </div>
    </section>
	<?php $this->endWidget();?>
</div>

<script src="js/addService.js"></script>