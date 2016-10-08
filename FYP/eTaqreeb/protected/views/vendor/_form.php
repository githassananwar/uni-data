<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'vendor-form',
 ));?>
    <section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">
              <h4 class="text-uppercase mb-5">Update!</h4>
              <div class="line-bottom mb-20"></div>
              
                <div class="row">
                  
              <div class="col-sm-12">
                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Name</label>
                      <?php echo $form->textField($model,'name',['class'=>'form-control','placeholder'=>'Enter Name', 'id'=>'name', 'maxlength'=>'200']); ?>
                      <span id="name_err" style="color:red;"></span>
                    </div>
                  </div>
                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Company Name</label>
                      <?php echo $form->textField($model,'companyname',['class'=>'form-control','placeholder'=>'Enter Company', 'id'=>'companyname', 'maxlength'=>'200']); ?>
                      <span id="companyname_err" style="color:red;"></span>
                    </div>
                  </div>
          </div>
          
          <div class="col-sm-12">
          <div class="col-sm-12">
                    <div class="form-group">
                      <label>Address</label>
                      <?php echo $form->textField($model,'address',['class'=>'form-control','placeholder'=>'Enter Address', 'id'=>'address', 'maxlength'=>'500']); ?>
                      <span id="address_err" style="color:red;"></span>
                    </div>
                  </div>

                  </div>
          
          <div class="col-sm-12">
                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Contact#1</label>
                      <?php echo $form->textField($model,'contact1',['class'=>'form-control','placeholder'=>'Enter Contact#1', 'id'=>'contact1', 'maxlength'=>'100']); ?>
                      <span id="contact1_err" style="color:red;"></span>
                    </div>
                  </div>
          
          <div class="col-sm-6">
                    <div class="form-group">
                      <label>Contact#2</label>
                      <?php echo $form->textField($model,'contact2',['class'=>'form-control','placeholder'=>'Enter Contact#2', 'id'=>'contact2', 'maxlength'=>'100']); ?>
                      <span id="contact2_err" style="color:red;"></span>
                    </div>
                  </div>

                  </div>

                  <div class="col-sm-12">
          
          <div class="col-sm-6">
                    <div class="form-group">
                      <label>Email</label>
                      <?php echo $form->EmailField($model,'email',['class'=>'form-control','placeholder'=>'Enter Email', 'id'=>'email', 'maxlength'=>'100']); ?>
                      <span id="email_err" style="color:red;"></span>
                    </div>
                  </div>
          
          
          <div class="col-sm-6">
                    <div class="form-group">
                      <label>Username</label>
                      <?php echo $form->textField($model,'username',['class'=>'form-control','placeholder'=>'Enter Username', 'id'=>'username', 'maxlength'=>'100', 'onblur'=>"updateUserNameAJAX($model->id,'vendor')"]); ?>
                      <span id="username_err" style="color:red;"></span>
                      <span id="available_username" style="color:green;"></span>
                    </div>
                  </div>
          
          </div>
          
          <div class="col-sm-12">

          <div class="col-sm-6">
                    <div class="form-group">
                      <label>Password</label>
                      <?php echo $form->passwordField($model,'password',['class'=>'form-control','placeholder'=>'Enter Password', 'id'=>'password', 'maxlength'=>'100']); ?>
                      <span id="password_err" style="color:red;"></span>
                    </div>
                  </div>

            <div class="col-sm-6">
                    <div class="form-group">
                      <label>Confirm Password</label>
                      <?php echo $form->passwordField($model,'password',['class'=>'form-control','placeholder'=>'Confirm Password', 'id'=>'confirmpassword', 'maxlength'=>'100']); ?>
                      <span id="confirmpassword_err" style="color:red;"></span>
                    </div>
                  </div>

                  </div>

<div class="col-sm-12">
                    <div class="col-sm-6">
                      <label>Availability:</label>
                        <?php
                          $types = array('Yes'=>'Yes','No'=>'No'); 
                          echo $form->dropDownList($model,'availability',$types,['id'=>'availability','class'=>'form-control','placeholder'=>'Enter Amount(Rs)']); ?>
                          <span id="availability_err" style="color:red;"></span>
                    </div>

           </div>

           </div>
                 
             <div class="col-sm-12">
               <div class="form-group">
                  <button data-loading-text="Please wait..." class="btn btn-colored btn-orange pl-30 pr-30" type="button" type="button" onclick="updateVendorAJAX()" id="add_vendor">Update</button>
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

<script src="js/vendorSignup.js"></script>
<script src="js/checkUserName.js"></script>