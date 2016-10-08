<?php  $vendorservices=VendorServices::model()->findAllByAttributes(array('vendor_id'=>$_SESSION["user-id"]));?>

				          
                  <?php if($vendorservices){?>

                  <?php foreach($vendorservices as $service):?>
      
                          <div class="mt-10">
                          <h5>Service Name: <?= $service->name ?></h5>
                          

                        <?php  $eventServices=EventServices::model()->findAllByAttributes(array('vendor_service_id'=>$service->id));?>
                        <?php if($eventServices){?>
                          <table class="table table-striped">
                          <thead>
                            <tr>
                              <th>#</th>
                              <th>Customer Name</th>
                              <th>Customer Email</th>
                              <th>Event Name</th>
                              <th>Event Date</th>
                              <th>Event Shift</th>
                              <th>Current Status</th>
                              <th>Choose Action</th>
                            </tr>
                          </thead>
                            <tbody>


                        <?php  $rowno=1; foreach($eventServices as $eventservice):?>
                         <?php  $event=Event::model()->findByPk($eventservice->event_id);?>
                        <?php  $customer=Customer::model()->findByPk($event->customer_id);?>
                         
                          <tr>
                          <th scope="row"><?=$rowno++?></th>
                          <td><?= $customer->name ?></td>
                          <td><?= $customer->email ?></td>
                           <td><?= $event->name ?></td>
                           <td><?= $event->date ?></td>
                           <td><?= $event->shift?></td>
                          <td><?=$eventservice->status?></td>
						  <td>
						  <select id="<?=$eventservice->id?>" onchange="actionEventService(<?=$eventservice->id?>)">
                                  <option>---Select---</option>
                                  <option>Confirm</option>
                                  <option>Cancel</option>
                          </select>
                           
						  </td>
                        </tr>    
    
                           
                        <?php endforeach;?>
                        </tbody>
                </table>

                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No requests so far!</h5>";
                }?>

                  <?php endforeach;?>
                <?php }
                else{
                 
                    echo "<h5 style=\"text-align:center\">No services so far!</h5>";
                }?>


<script src="js/eventService.js"></script>