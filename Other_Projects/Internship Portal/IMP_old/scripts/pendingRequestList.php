<?php 
                        session_start();                         
                        $dbstatus = include "../functions/dbhandler.php";
                        if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
                        }
                        
                        $isEmpty=true;
                        $result=getPendingRequests();
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
                                        <td><a target="_blank"  href="review_app.php?id=<?=$row['studentid']?>" style="text-decoration:underline">Review Application</a></td>
                                        <td></td>
                                    </tr>
                                    <tr>
                                        <td colspan="2">
                                            <form role="form" class="form-horizontal">
                                                <div class="form-group">
                                                    <label class="control-label col-sm-4" for="status">Application Status</label>
                                                    <div class="col-sm-7">
                                                        <select id="<?=$row['id']?>" class="form-control" required autofocus>
                                                            <option>PENDING</option>
                                                            <option>APPROVED</option>
                                                            <option>DENIED</option>
                                                        </select>
                                                    </div>
                                                </div>

                                                <div class="form-group" id="reasonbar<?=$row['id']?>">
                                                    <label class="control-label col-sm-4" for="reason">Reason of Denial</label>
                                                    <div class="col-sm-7">
                                                        <select id="reason<?=$row['id']?>" class="form-control" required autofocus>
                                                            <option>Did not meet site criteria</option>
                                                            <option>Did not meet academic criteria</option> 
                                                            <?php
                                                            $userid=$_SESSION['userid'];

                                                            if(isset($_SESSION['admin_type']))
                                                            {
                                                                 $reasons=getSuperAdminOtherReasons($userid);
                                                            }
                                                            else
                                                            {
                                                                $reasons=getAdminOtherReasons($userid);
                                                            }
                                                           
                                                            while ( $reason = mysqli_fetch_assoc($reasons) ) {
                                                        
                                                            ?>
                                                            <option><?=$reason['reason']?></option>

                                                            <?php } ?>
                                                            <option>Other</option>
                                                        </select>
                                                    </div>
                                                </div>

                                                <div class="form-group" id="other-reason<?=$row['id']?>">
                                                    <label class="control-label col-sm-4" for="other-reason">Please Specify other reason</label>
                                                    <div class="col-sm-7">
                                                        <input id="other<?=$row['id']?>" class="form-control" required autofocus />
                                                        <span id="other_err<?=$row['id']?>" style="color:red;"></span>
                                                    </div>
                                                </div>

                                                <div class="form-group">
                                                    <div class="col-sm-offset-8 col-sm-3">
                                                        <button id="submit<?=$row['id']?>" class="btn btn-primary btn-block" type="button" onclick="RequestAJAX(<?=$row['id']?>)" disabled >Submit</button>
                                                    </div>
                                                </div>

                                            </form>
                                        </td>
                                    </tr>

                                </tbody>

                            </table>
                           
                            <div style="border-bottom: groove; margin-bottom:25px;"></div>  
                            <script>

                            $("#reasonbar<?=$row['id']?>").hide();  
                            $("#other-reason<?=$row['id']?>").hide();     
                            </script>



            <?php }
            if($isEmpty)
            { ?>
                <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>Currently there are no Pending Requests</p>
            <?php } ?>


<script src="../js/jquery-1.10.2.js"></script>
<script src="../js/handleRequest.js"></script>
<script>

$('select').click(function(){
            var val = this.value;
            var selectid=this.id;  
            
            if(val=='APPROVED')
            {
                $("button[id^='submit"+selectid+"']").removeAttr('disabled');
            }
            else
            {
                $("button[id^='submit"+selectid+"']").attr('disabled','disabled');
            }            

            if(val=='DENIED')
            {
                 $("div[id^='reasonbar"+selectid+"']").show();
                 $("button[id^='submit"+selectid+"']").removeAttr('disabled');
            }
            else
            {
                $("div[id^='reasonbar"+selectid+"']").hide();
            }

            if(val=='Other')
            {
                $("div[id^='other-"+selectid+"']").show();
            }
            else
            {
               $("div[id^='other-"+selectid+"']").hide();
            }

        });
</script>