<?php 
                      
                        $dbstatus = include "../functions/dbhandler.php";
                        if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
                        }
                        
                        $isEmpty=true;
                        $result=getAllQueries();
                        while ( $row = mysqli_fetch_assoc($result) ) {
                        $isEmpty=false;
                        ?>
                        <table class="table table-hover">
                        <tbody>

                            <tr>
                                <td>Student Name</td>
                                <td><?=$row['name']?></td>
                            </tr>
                            <tr>
                                <td>Date of Query</td>
                                <td><?=$row['submitdate']?></td>
                            </tr>                           
                            <tr>
                                <td class="col-md-3 col-sm-3 col-xs-4">
                                    Message
                                </td>
                                <td class="col-md-9 col-sm-9 col-xs-8">
                                    <?=$row['message']?>
                                </td>
                            </tr>
                            <tr>
                                <td colspan="2">
                                    <form role="form" class="form-horizontal">
                                        <div class="form-group">
                                            <label class="control-label col-sm-4" for="reply">Reply:</label>
                                            <div class="col-sm-7">
                                                <textarea id="reply<?=$row['id']?>" rows="3" class="form-control" required autofocus style="resize:vertical"></textarea>
                                                <span id="reply_err<?=$row['id']?>" style="color:red;"></span>
                                            </div>
                                            
                                        </div>
                                        <div class="form-group">
                                            <div class="col-sm-offset-8 col-sm-3 col-xs-offset-6 col-xs-5">
                                                <button class="btn btn-primary btn-block" type="button" onclick="answerQueryAJAX(<?=$row['id']?>, '<?=$row['email']?>', '<?=$row['name']?>')">Submit</button>
                                            </div>
                                        </div>
                                    </form>
                                </td>
                            </tr>
                        </tbody>
                    </table>
                    <div style="border-bottom: groove; margin-bottom:25px;"></div>
                    
<?php } 
?>
<?php
    if($isEmpty)
    { ?>
           <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>Currently there are no Messages</p>
<?php } ?>
