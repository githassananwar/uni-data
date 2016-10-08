<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'customer-form',


 ));?>

<div class="main-content">
    <!-- Section: home -->
   
 

 <?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
  
?>

  <section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Customer Requests</h3>
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">

           
              <h4>Details</h4>
              <div class="line-bottom mb-20"></div>
              <form id="donation-main-form" class="donation-form">
                <div class="row" id="customerRequests">
                  
               </div>
        
              </form>
            </div>
          </div>
      </div>
     </div>

    </section>

    </div>
<script src="js/jquery-2.1.4.min.js"></script> 
<script>

 $(document).ready(function(){
            $("#customerRequests").load('?r=eventServices/customerRequests');
    
        });


</script>
  

    <?php $this->endWidget();?>

    <?php }

else 
{
  $this->redirect(array('site/index'));
  die('Direct Access not permitted');
}

?>

