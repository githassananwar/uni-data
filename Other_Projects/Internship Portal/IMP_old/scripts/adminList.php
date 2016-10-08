
<?php 
                      
                        $dbstatus = include "../functions/dbhandler.php";
                        if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
                        }
                        
                        $isEmpty=true;
                        $result=getAllAdmins();
                        while ( $row = mysqli_fetch_assoc($result) ) {
                        $isEmpty=false;
                        ?>
                            <table class="table table-hover">
                                <tbody>
                                    <tr>
                                        <td>Admin Name</td>
                                        <td><?=$row['username']?></td>
                                    </tr>
                                    <tr>
                                        <td>Admin Email</td>
                                        <td><?=$row['email']?></td>
                                    </tr>
                                    <tr>
                                        <td><a href="#"  style="text-decoration:underline" onclick="testfunc(<?=$row['id']?>)">Remove Admin</a></td>
                                        <td></td>
                                    </tr>
                                    
                                </tbody>

                            </table>
                            <div style="border-bottom: groove; margin-bottom:25px;"></div>  
<?php } 
?>
<?php
    if($isEmpty)
    { ?>
           <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>Currently there are no Admins</p>
<?php } ?>

<script src="../js/removeAdmin.js"></script>
