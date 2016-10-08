<div class="col-lg-12 col-md-12 col-sm-12 col-xs-6" >
                 <table class="table">
  <thead class="thead-inverse">
    <tr>
      <th>#</th>
      <th>Admin Email</th>
      <th>Remove Admin</th>
    </tr>
  </thead>
 

  <tbody>
<?php 

 $dbstatus = include "../functions/dbhandler.php";
 if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
  }
                        
  $isEmpty=true;
  $rowno=1;
  $result=getAllAdmins();
  while ( $row = mysqli_fetch_assoc($result) ) {
  $isEmpty=false;
  ?>                    

    <tr>
      <th scope="row"><?= $rowno++ ?></th>
      <th><?= $row['username'] ?></th> 
       <th><a href="#"  style="text-decoration:underline" onclick="testfunc(<?=$row['id']?>)">Remove</a></th>  
    </tr>

    <?php } ?>

  </tbody>

</table>

 <?php  
        if($isEmpty)
            { ?>
                <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>Currently there are no Admins</p>
        <?php } ?>
                     
                  </div>