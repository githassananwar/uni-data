 <div class="container">
    	
    	<div class="screen" id="screen">
    		
    		<div class="toolbar">
    		
    			<div class="buttons clearfix">
    				<span class="left red"></span>
    				<span class="left yellow"></span>
    				<span class="left green"></span>
    			</div>
    			
    			<div class="title" id="pageTitle">
    				<span>Manage Vendor Services</span>
    			</div>
    			
    		</div>
    		
    		<div id="frameWrapper" class="frameWrapper empty" align="center">
    			<br/>
          <h3>All Services</h3>

             <?php 

                $vendorservices = VendorServices::model()->findAll();
                ?>

                <?php if($vendorservices){?>
                <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Id</th>
                    <th>Name</th>
                    <th>Price</th>
                    <th>Vendor Details</th>
                    <th>View Details</th>
                    <th>Update Service</th>
                    <th>Delete Service</th>
                  </tr>
                </thead>
                  <tbody>

                  <?php $rowno=1; foreach($vendorservices as $service):?>
                    <tr>

                      <?php $vendor=Vendor::model()->findByPk($service->vendor_id);?>
                      <th scope="row"><?=$rowno++?></th>
                      <td><?= $service->id ?></td>
                      <td><?= $service->name ?></td>
                      <td><?= $service->price ?></td>
                      <td><a href="index.php?r=vendor/view&id=<?= $vendor->id;?>"><?=$vendor->name?></a></td>
                      <td><a href="index.php?r=vendorservices/view&id=<?= $service->id;?>">View</a></td>
                      <td><a href="index.php?r=vendorservices/update&id=<?= $service->id;?>">Update</a></td>
                      <td><a href="index.php?r=vendorservices/deleteVendorService&id=<?= $service->id;?>">Delete</td>
                    </tr>    

                    <?php endforeach;?>
                  </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No services so far!</h5>";
                }

                ?>

				
    		</div>
    	
    	</div><!-- /.screen -->
    	
    </div><!-- /.container -->
	
	<div id="loader">
		<img src="images/loading.gif" alt="Loading...">
		Loading elements...
	</div>
	