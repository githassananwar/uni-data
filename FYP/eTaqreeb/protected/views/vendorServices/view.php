<?php
/* @var $this VendorServicesController */
/* @var $model VendorServices */

$this->breadcrumbs=array(
	'Vendor Services'=>array('index'),
	$model->name,
);

?>




<div class="main-content">

<section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Service Details</h3>
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
<td align="left"><h5 style="display:inline">Price:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->price?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Category:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->type?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Pricing:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->pricemode?></strong></h5></td>
</tr>

</table>
<br><br>

<?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
	

	if(isset($_SESSION['current_eventid']))
	{
		$isBook=EventServices::model()->findByAttributes(array('vendor_service_id'=>$model->id, 'event_id'=>$_SESSION['current_eventid']));	
		if($isBook)
		{?>
			<h4>You have already requested the Service for Booking</h4>
	<?php }
		else
		{
			$event=Event::model()->findByAttributes(array('id'=>$_SESSION['current_eventid']));
			global $amount;
			if($model->pricemode=='Per Head')
			{
				
				$amount=$event->numOfGuests*$model->price;
			}
			else
			{
				$amount=$model->price;
			}

			?>
			<h4><button type="button"  onclick="bookAJAX(<?=$amount?>, <?=$event->id?>, <?=$model->id?>)">Book</button></h4>
	<?php }

	}
	else if(isset($_SESSION['user-type']) && !strcmp($_SESSION['user-type'],"customer"))
	{?>
		<h4>Error! Select the event</h4>
	<?php } ?>


<?php }

 ?>

</div>
          </div>
      </div>
     </div>

    </section>

</div>


 

 <script src="js/book.js"></script>
