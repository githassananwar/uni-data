 <div class="container">
    	
    	<div class="screen" id="screen">
    		
    		<div class="toolbar">
    		
    			<div class="buttons clearfix">
    				<span class="left red"></span>
    				<span class="left yellow"></span>
    				<span class="left green"></span>
    			</div>
    			
    			<div class="title" id="pageTitle">
    				<span>Manage Customers</span>
    			</div>
    			
    		</div>
    		
    		<div id="frameWrapper" class="frameWrapper empty" align="center">
    			<br/>
          <h3>All Customers</h3>

             <?php 

                $customers = Customer::model()->findAll();
                ?>

                <?php if($customers){?>
                <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Id</th>
                    <th>Name</th>
                    <th>Email</th>
                    <th>Contact</th>
                    <th>View Details</th>
                    <th>Update Customer</th>
                     <th>Delete Customer</th>
                  </tr>
                </thead>
                  <tbody>

                  <?php $rowno=1; foreach($customers as $customer):?>
                    <tr>
                      <th scope="row"><?=$rowno++?></th>
                      <td><?= $customer->id ?></td>
                      <td><?= $customer->name ?></td>
                      <td><?= $customer->email ?></td>
                      <td><?= $customer->contact ?></td>
                      <td><a href="index.php?r=customer/view&id=<?= $customer->id;?>">View</a></td>
                      <td><a href="index.php?r=customer/update&id=<?= $customer->id;?>">Update</a></td>
                      <td><a href="index.php?r=customer/deleteCustomer&id=<?= $customer->id;?>">Delete</td>
                    </tr>    

                    <?php endforeach;?>
                  </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No customers so far!</h5>";
                }

                ?>



				
    		</div>
    	
    	</div><!-- /.screen -->
    	
    </div><!-- /.container -->
	
	<div id="loader">
		<img src="images/loading.gif" alt="Loading...">
		Loading elements...
	</div>
	