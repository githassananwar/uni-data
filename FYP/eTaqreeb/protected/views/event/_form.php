<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'event-form',


 ));?>
    <section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">

          
              <h4 class="text-uppercase mb-5">Update Event!</h4>
             
              <div class="line-bottom mb-20"></div>
              <form id="donation-main-form" class="donation-form">
                <div class="row">
                  
                   <div class="col-sm-12">
                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Name</label>
                      <?php echo $form->textField($model,'name',['class'=>'form-control','placeholder'=>'Enter Name', 'maxlength'=>'200', 'id'=>'name']); ?>
                       <span id="name_err" style="color:red;"></span>
                    </div>
                  </div>
                  

                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Type</label>
                      <?php echo $form->textField($model,'type',['class'=>'form-control','placeholder'=>'Enter Event Type', 'maxlength'=>'200', 'id'=>'etype']); ?>
                       <span id="type_err" style="color:red;"></span>
                    </div>
                  </div>
                   </div>


                    <div class="col-sm-12">
                   <div class="col-sm-6">
                    <div class="form-group">
                      <label>Date (MM/DD/YY)</label>
                      <?php echo $form->textField($model,'date',['class'=>'form-control','placeholder'=>'Enter Date', 'id'=>'date']); ?>
                       <span id="date_err" style="color:red;"></span>
                    </div>

                  </div>

                  <div class="col-sm-6">
                    <div class="form-group">
                      <label>Shift</label>
                     <?php
                          $types = array('---Select---','Morning'=>'Morning','Afternoon'=>'Afternoon','Night'=>'Night'); 
                          echo $form->dropDownList($model,'shift',$types,['id'=>'type', 'class'=>'form-control', 'onchange'=>'validateCreateEvent()']); ?>
                           <span id="shift_err" style="color:red;"></span>
                    </div>
                  </div>

                  </div>

 <div class="col-sm-12">
                   <div class="col-sm-6">
                    <div class="form-group">
                      <label>Budget (Rs.)</label>
                      <?php echo $form->textField($model,'budget',['class'=>'form-control','placeholder'=>'Enter Budget', 'maxlength'=>'9','id'=>'budget']); ?>
                       <span id="budget_err" style="color:red;"></span>
                    </div>
                  </div>

                

                   <div class="col-sm-6">
                    <div class="form-group">
                      <label>No. of Guests:</label>
                      <?php echo $form->textField($model,'numOfGuests',['class'=>'form-control','placeholder'=>'Enter guests', 'maxlength'=>'20','id'=>'numofguests']); ?>
                       <span id="numofguests_err" style="color:red;"></span>
                    </div>
                  </div>

                  </div>

                   </div>
        <div class="col-sm-12">
                   
                    <div class="form-group">
                
                <button data-loading-text="Please wait..." class="btn btn-colored btn-orange pl-30 pr-30" type="button" onclick="updateEventAJAX()" >Update</button>
                  
                </div> 

            </div>

            

                </div>
  
                </div>
               
              </form>
            </div>
          </div>
          <div class="col-md-5">
          </div>
        </div>
      </div>
     
    </section>
    <?php $this->endWidget();?>
  
</div>

<script src="js/createEvent.js"></script>