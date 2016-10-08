

<?php
/* @var $this VendorController */
/* @var $model Vendor */

$this->breadcrumbs=array(
	'Vendors'=>array('index'),
	$model->name,
);


?>

<div class="main-content">

<section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Vendor Details</h3>
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">


<h4>Details:-</h4>
<div class="line-bottom mb-20"></div> 

<table>

<tr>
<td align="left"><h5 style="display:inline">Name:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->companyname?></strong></h5></td>
</tr>

<tr>
<td align="left"><h5 style="display:inline">Owner:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->name?></strong></h5></td>
</tr>

<tr>
<td align="left"><h5 style="display:inline">Address:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->address?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Contact#1:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->contact1?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Contact#2:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->contact2?></strong></h5></td>
</tr>

<tr>
<td align="left"><h5 style="display:inline">Availability:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->availability?></strong></h5></td>
</tr>


</table>
<br><br>


<h4>Services Offered:-</h4>
<div class="line-bottom mb-20"></div> 

<form id="donation-main-form" class="donation-form">
<div class="row">

<?php if($model->availability=='Yes'){


	$vendorServices=vendorServices::model()->findAllByAttributes(array('vendor_id'=>$model->id));

?>
	<?php if($vendorServices){?>
		<table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Name</th>
                    <th>Price</th>
                    <?php if( isset($_SESSION["login_user"]) && !strcmp($_SESSION['user-type'],"customer")){?> 
                    <th>Book Service</th>
                    <?php }?>
                  </tr>
                
                  <?php $rowno=1; foreach($vendorServices as $service):?>

                  <tr>
                      <th scope="row"><?=$rowno++?></th>
                      <th><?= $service->name; ?></th>
                      <th>Rs. <?= $service->price; ?></th>
                      <?php if(isset($_SESSION["login_user"]) && !strcmp($_SESSION['user-type'],"customer")){?> 
                      <th><a href="index.php?r=vendorservices/view&id=<?=$service->id?>">Book</a></th>
                      <?php }?>
                    </tr>    
                        

                  <?php endforeach;?>
                  
                          </tbody>
                </table>    
                        
               <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No services registered so far!</h5>";
                }

              }
              else
              {
                  echo "<h5 style=\"text-align:center\">Currently vendor services are not available!</h5>";
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






?>
<br>