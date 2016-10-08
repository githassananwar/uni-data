<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'vendorServices-form',


 ));?>
<?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
  
?>
 
<section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Your Services</h3>
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">

           
              <h4>Manage Services!</h4>

              <div class="line-bottom mb-20"></div>
              <form id="donation-main-form" class="donation-form">
                <div class="row">
                  
               <?php  $vendorServices=VendorServices::model()->findAllByAttributes(array('vendor_id'=>$_SESSION['user-id']));?>

                  
                  <?php if($vendorServices){?>
                  <table class="table table-striped">
                  <thead>
                    <tr>
                      <th>#</th>
                      <th>Name</th>
                      <th>Price/Head</th>
                      <th>Show Details</th>
                      <th>Update Service </th>
                      <th>Delete Service</th>
                       
                    </tr>
                  </thead>
                    <tbody>


                  <?php $rowno=1; foreach($vendorServices as $service):?>
                    <tr>
                      <th scope="row"><?=$rowno++?></th>
                      <th><?= $service->name ?>&nbsp &nbsp</th>
                      <th>Rs. <?= $service->price ?>&nbsp &nbsp</th>
                      <th><a href="index.php?r=vendorServices/view&id=<?= $service->id;?>">Show</a></th>
                      <th><a href="index.php?r=vendorServices/update&id=<?= $service->id;?>">Update</a></th>
                      <th><a href="index.php?r=vendorServices/deleteVendorService&id=<?= $service->id;?>">Delete</a></th>
                  </tr>   
                        
                      

                  <?php endforeach;?>


                </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">You have no services so far!</h5>";
                }

                ?>

                </div>    
        
              </form>
            </div>
          </div>
      </div>
     </div>

    </section>

    </div>
    <?php $this->endWidget();?>

    <?php }

else 
{
  $this->redirect(array('site/index'));
  die('Direct Access not permitted');
}

?>


                