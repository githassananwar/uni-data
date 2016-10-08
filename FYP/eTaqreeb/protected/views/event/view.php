<?php
/* @var $this EventController */
/* @var $model Event */

$this->breadcrumbs=array(
	'Events'=>array('index'),
);

?>

<?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
	
?>

<div class="main-content">

<section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Event Details</h3>
           <div style="float:right;">
<h4><strong>Total Cost: </strong>Rs.<?=$model->current_budget?></h4>
</div>
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">


<h4>Details:-</h4>
<div class="line-bottom mb-20"></div> 

<table>

<tr>
<td align="left"><h5 style="display:inline">Name:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->name?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Type:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->type?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Date:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->date?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Shift:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong>
<?=$model->shift?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Budget:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong>Rs. <?=$model->budget?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">No. of Guests:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->numOfGuests?></strong></h5></td>
</tr>


</table>
<br><br>

<h4>Services Booked:-</h4>
<div class="line-bottom mb-20"></div> 

              <form id="donation-main-form" class="donation-form">
              <div class="row">


               <?php  $eventServices=EventServices::model()->findAllByAttributes(array('event_id'=>$model->id));?>

				          
                  <?php if($eventServices){?>

                   <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Service Name</th>
                    <th>Service Price</th>
                    <th>Company Name</th>
                    <th>Service Status</th>
                    <th>Cancel Request</th>
                  </tr>
                </thead>
                  <tbody>

                  <?php $rowno=1; foreach($eventServices as $service):?>

                  	<?php $serviceid=$service->vendor_service_id; ?>
                    <?php  $vendorServices=VendorServices::model()->findByPk($serviceid); ?>
                    
                    <?php $vendorid= $vendorServices->vendor_id; ?>
                    <?php  $vendor=Vendor::model()->findByPk($vendorid);?>

					<tr>
                      <th scope="row"><?=$rowno++?></th>
                      <th><?= $vendorServices->name ?></th>
                      <th><?= $vendorServices->price ?></th>
                      <th><?= $vendor->companyname ?></th>
                      <th><?= $service->status ?></th>
                      <?php if($service->status == "Not confirm" || $service->status == "Cancelled")
                      {

                      ?>
                      <th><a href="index.php?r=eventServices/deleteEventService&id=<?= $service->id;?>&eventid=<?= $model->id;?>">Cancel</a></th>
                      <?php }
                      else
                      {

                        ?>
                        <th>N/A</th>

                      <?php } ?>

                    </tr>    
                         
                          
                      

                  <?php endforeach?>
                  </tbody>
                </table>    
                         
                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No services booked so far!</h5>";
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


 <?php }

else 
{
  $this->redirect(array('site/index'));
  die('Direct Access not permitted');
}

?>
