<div class="main-content">
    <!-- Section: home -->
   
 <!-- divider: Donate Now -->
 <?php $form=$this->beginWidget('CActiveForm',array(
  'id'=>'customer-form',


 ));?>

 <?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
  
?>
 
<section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Your Events</h3>
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">

           
              <h4>Select Your Event!</h4>
             
              <div class="line-bottom mb-20"></div>
              <form id="donation-main-form" class="donation-form">
                <div class="row">
  
               <?php  $events=Event::model()->findAllByAttributes(array('customer_id'=>$_SESSION['user-id']));?>

                
				          
                <?php if($events){?>
                
                <table class="table table-striped">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Event Name</th>
                    <th>Event Date</th>
                    <th>Show Details</th>
                    <th>Edit Event</th>
                     <th>Select Event</th>
                  </tr>
                </thead>
                  <tbody>
                    
                  
                  <?php $rowno=1; foreach($events as $event):?>

                    <tr>
                      <th scope="row"><?=$rowno++?></th>
                      <td><?= $event->name ?></td>
                      <td><?= $event->date ?></td>
                      <td><a href="index.php?r=event/view&id=<?= $event->id;?>">Show</a></td>
                      <td><a href="index.php?r=event/update&id=<?= $event->id;?>">Edit</td>
                      <td><a href="index.php?r=event/selectEvent&id=<?= $event->id;?>">Select</td>
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
	
