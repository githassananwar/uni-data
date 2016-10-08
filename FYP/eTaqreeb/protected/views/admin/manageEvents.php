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
          <h3>All Events</h3>

             <?php 

                $events = Event::model()->findAll();
                ?>

                <?php if($events){?>
                <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Id</th>
                    <th>Name</th>
                    <th>Type</th>
                    <th>Date</th>
                    <th>Customer Details</th>
                    <th>View Details</th>
                    <th>Update Event</th>
                    <th>Delete Event</th>
                  </tr>
                </thead>
                  <tbody>

                  <?php $rowno=1; foreach($events as $event):?>
                    <tr>

                      <?php $customer=Customer::model()->findByPk($event->customer_id);?>
                      <th scope="row"><?=$rowno++?></th>
                      <td><?= $event->id ?></td>
                      <td><?= $event->name ?></td>
                      <td><?= $event->type ?></td>
                      <td><?= $event->date ?></td>
                      <td><a href="index.php?r=customer/view&id=<?= $customer->id;?>"><?=$customer->name?></a></td>
                      <td><a href="index.php?r=event/view&id=<?= $event->id;?>">View</a></td>
                      <td><a href="index.php?r=event/update&id=<?= $event->id;?>">Update</a></td>
                      <td><a href="index.php?r=event/deleteEvent&id=<?= $event->id;?>">Delete</td>
                    </tr>    

                    <?php endforeach;?>
                  </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No events so far!</h5>";
                }

                ?>

				
    		</div>
    	
    	</div><!-- /.screen -->
    	
    </div><!-- /.container -->
	
	<div id="loader">
		<img src="images/loading.gif" alt="Loading...">
		Loading elements...
	</div>
	