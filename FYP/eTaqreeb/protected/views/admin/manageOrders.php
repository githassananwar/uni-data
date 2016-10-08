 <div class="container">
    	
    	<div class="screen" id="screen">
    		
    		<div class="toolbar">
    		
    			<div class="buttons clearfix">
    				<span class="left red"></span>
    				<span class="left yellow"></span>
    				<span class="left green"></span>
    			</div>
    			
    			<div class="title" id="pageTitle">
    				<span>Manage Orders</span>
    			</div>
    			
    		</div>
    		
    		<div id="frameWrapper" class="frameWrapper empty" align="center">
    			<br/>
          <h3>All Customer Requests</h3>

             <?php 

                $eventservices = eventservices::model()->findAll();
                ?>

                <?php if($eventservices){?>
                <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Id</th>
                    <th>Service Name</th>
                    <th>Vendor Name</th>
                    <th>Customer Name</th>
                    <th>Event Name</th>
                    <th>Event Date</th>
                    <th>Status</th>
                    <th>Delete Request</th>
                  </tr>
                </thead>
                  <tbody>

                  <?php $rowno=1; foreach($eventservices as $service):?>
                    <tr>

                      <?php $event=Event::model()->findByPk($service->event_id);?>
                      <?php $customer=Customer::model()->findByPk($event->customer_id);?>
                      <?php $vendorservice=Vendorservices::model()->findByPk($service->vendor_service_id);?>
                      <?php $vendor=Vendor::model()->findByPk($vendorservice->vendor_id);?>
                      <th scope="row"><?=$rowno++?></th>
                      <td><?= $service->id ?></td>
                      <td><?= $vendorservice->name ?></td>
                      <td><?= $vendor->name ?></td>
                      <td><?= $customer->name ?></td>
                      <td><?= $event->name ?></td>
                      <td><?= $event->date ?></td>
                      <td><?= $service->status ?></td>
                      <td><a href="index.php?r=eventservices/deleteEventService&id=<?= $service->id;?>">Delete</td>
                    </tr>    

                    <?php endforeach;?>
                  </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No requests so far!</h5>";
                }

                ?>

				
    		</div>
    	
    	</div><!-- /.screen -->s
    	
    </div><!-- /.container -->
	
	<div id="loader">
		<img src="images/loading.gif" alt="Loading...">
		Loading elements...
	</div>
	