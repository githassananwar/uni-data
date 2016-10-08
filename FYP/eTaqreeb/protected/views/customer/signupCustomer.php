<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'customer-form',

 ));?>
    <section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">

          
              <h4 class="text-uppercase mb-5">SignUp!</h4>
              <div class="line-bottom mb-20"></div>
              <form id="form" name="signup" class="donation-form">
                <div class="row">

                <div class="col-sm-12">
                
                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Name</label>
                      <?php echo $form->textField($model,'name',['class'=>'form-control','placeholder'=>'Enter Name', 'id'=>'name', 'maxlength'=>'200']); ?>
                      <?php echo $form->error($model, 'name'); ?>
                      <span id="name_err" style="color:red;"></span>
                    </div>
                  </div>
                  
				  
				  
				  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Username</label>
                      <?php echo $form->textField($model,'username',['class'=>'form-control','placeholder'=>'Enter Username', 'id'=>'username', 'maxlength'=>'100', 'onblur'=>"checkUserNameAJAX()"]); ?>
                      <span id="username_err" style="color:red;"></span>
                      <span id="available_username" style="color:green;"></span>
                    </div>
                  </div>
                  </div>
                  
                  <div class="col-sm-12">
                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Password</label>
                      <?php echo $form->passwordField($model,'password',['class'=>'form-control','placeholder'=>'Enter Password' , 'id'=>'password', 'maxlength'=>'100']); ?>
                      <span id="password_err" style="color:red;"></span>
                    </div>
                  </div>

                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Confirm Password</label>
                      <input type="password" class="form-control" id="confirmPassword" placeholder="Confirm Password" maxlength="100"/>
                      <span id="confirmpassword_err" style="color:red;"></span>
                    </div>
                  </div>
                  </div>

                  <div class="col-sm-12">

                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Email</label>
                      <?php echo $form->EmailField($model,'email',['class'=>'form-control','placeholder'=>'Enter Email' , 'id'=>'email', 'maxlength'=>'100']); ?>
                      <span id="email_err" style="color:red;"></span>
                    </div>
                  </div>
				  
				  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Contact</label>
                      <?php echo $form->textField($model,'contact',['class'=>'form-control','placeholder'=>'Enter Contact' , 'id'=>'contact', 'maxlength'=>'100']); ?>
                      <span id="contact_err" style="color:red;"></span>
                    </div>
                  </div>
                 
                 
                </div>
                
                 <div class="col-sm-12">
                 <div class="col-sm-6">
                 <div class="form-group">
                    <button data-loading-text="Please wait..." class="btn btn-colored btn-orange pl-30 pr-30" type="button" onclick="SignupAJAX()" id="add_customer" >Sign Up</button>
                  </div>
                  </div>
                  </div>



                </div>
              </form>
            </div>
          </div>
          
        </div>
      </div>
     
    </section>
    <?php $this->endWidget();?>
	
</div>

<script src="js/customerSignup.js"></script>
<script src="js/checkUserName.js"></script>