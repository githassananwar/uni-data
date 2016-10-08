 <div class="container">
    	
    	<div class="screen" id="screen">
    		
    		<div class="toolbar">
    		
    			<div class="buttons clearfix">
    				<span class="left red"></span>
    				<span class="left yellow"></span>
    				<span class="left green"></span>
    			</div>
    			
    			<div class="title" id="pageTitle">
    				<span>Manage Vendors</span>
    			</div>
    			
    		</div>
    		
    		<div id="frameWrapper" class="frameWrapper empty" align="center">
    			<br/>
          <h3>All Vendors</h3>

             <?php 

                $vendors = Vendor::model()->findAll();
                ?>

                <?php if($vendors){?>
                <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Id</th>
                    <th>Name</th>
                    <th>Company Name</th>
                    <th>Email</th>
                    <th>View Details</th>
                    <th>Update Vendor</th>
                    <th>Delete Vendor</th>
                  </tr>
                </thead>
                  <tbody>

                  <?php $rowno=1; foreach($vendors as $vendor):?>
                    <tr>
                      <th scope="row"><?=$rowno++?></th>
                      <td><?= $vendor->id ?></td>
                      <td><?= $vendor->name ?></td>
                      <td><?= $vendor->companyname ?></td>
                      <td><?= $vendor->email ?></td>
                      <td><a href="index.php?r=vendor/view&id=<?= $vendor->id;?>">View</a></td>
                      <td><a href="index.php?r=vendor/update&id=<?= $vendor->id;?>">Update</a></td>
                      <td><a href="index.php?r=vendor/deleteVendor&id=<?= $vendor->id;?>">Delete</td>
                    </tr>    

                    <?php endforeach;?>
                  </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No vendors so far!</h5>";
                }

                ?>

				
    		</div>
    	
    	</div><!-- /.screen -->
    	
    </div><!-- /.container -->
	
	<div id="loader">
		<img src="images/loading.gif" alt="Loading...">
		Loading elements...
	</div>
	