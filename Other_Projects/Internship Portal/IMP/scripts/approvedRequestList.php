<?php 
                      
                        $dbstatus = include "../functions/dbhandler.php";
                        if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
                        }
                        
                        $isEmpty=true;
                        $result=getApprovedRequests();
                        while ( $row = mysqli_fetch_assoc($result) ) {
                        $isEmpty=false;
                        ?>
                            <table class="table table-hover">
                                <tbody>
                                    <?php $student=getStudent($row['studentid']);
                                    $info=getStudentInfo($row['studentid']); ?>
                                    <tr>
                                        <td>Date of Submission</td>
                                        <td><?=$student['registerdate']?></td>
                                    </tr>
                                    <tr>
                                        <td>Student Name</td>
                                        <td><?=$info['name']?></td>
                                    </tr>
                                    <tr>
                                        <td>Request Status</td>
                                        <td><?=$row['status']?></td>
                                    </tr>
                                    <tr>
                                        <td><a target="_blank"  href="review_app.php?id=<?=$row['studentid']?>" style="text-decoration:underline">Review Application</a></td>
                                        <td></td>
                                    </tr>
                                    
                                </tbody>

                            </table>
                            <div style="border-bottom: groove; margin-bottom:25px;"></div>  
                            

        <?php } 
        if($isEmpty)
            { ?>
                <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>Currently there are no Approved Requests</p>
        <?php } ?>