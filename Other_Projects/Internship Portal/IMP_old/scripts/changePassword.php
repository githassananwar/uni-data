<?php
/**
 * Created by Softenica Technologies Softenica.com
 */
session_start();

if(!isset($_SESSION['username']) ):?>

<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->

    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta id="request-method" name="request-method" content="GET">
    <meta name="author" content="Softenica">
    <meta name="keywords" content="Softenica">
    <link rel="shortcut icon" href="images/only-nsu.png" type="image/png" />
    <title>Shark Internship Portal</title>
    <link rel="stylesheet" type="text/css" href="../styles/bootstrap.min.css" />
    <link rel="stylesheet" type="text/css" href="../styles/master.css" />

</head>
<body>
    <header id="header" class="container col-md-12 col-lg-12 col-sm-12 col-xs-12">
            <div class="col-md-3 col-md-offset-1" id="logo"><a href="http://www.nova.edu/" target="_blank"><img src="../images/logo.png" width="239" height="61" border="0" alt="Nova Southeastern University"></a></div>
            <div class="col-md-4">
                <h3 class="nsu-title">Shark Internship Portal </h3>
            </div>
    </header>
    

    <div id="nova-background" class="container">
        <div class="from-container col-lg-4 col-lg-offset-4 col-sm-6 col-sm-offset-3 col-md-4 col-md-offset-4 col-xs-10 col-xs-offset-1">          
            <div class="row logo-container">               
                <div class="col-md-6 col-sm-6 col-xs-6 col-md-offset-3 col-sm-offset-3 col-xs-offset-3">
                    <img class="logo-img-shark" src="../images/shark-learn-logo.png">
                </div>
            </div>            
            <form class="form-horizontal register-form">
                <div id="invalid_Err_Msg">
                    The username you entered is incorrect. Please try again.
                </div><br />
                <div id="notification" style="color:green">
                   A code has been sent to your email. Please enter code below.
                </div><br />
                 <div class="form-group" id="usernamepart">
                            <label class="control-label col-sm-4" for="username">Enter Username:</label>
                            <div class="col-sm-7">
                                <input id="username" class="form-control" required autofocus>
                                 <span id="username_err" style="color:red;"></span>
                            </div>
                        </div>

                  
                    <div id="updatepart">
                        <div class="form-group">
                            <label class="control-label col-sm-4" for="code">Enter Code:</label>
                            <div class="col-sm-7">
                                <input id="code" class="form-control" required>
                                <span id="code_err" style="color:red;"></span>
                            </div>
                        </div>

                        <div class="form-group">
                            <label class="control-label col-sm-4" for="newPassword">New Password:</label>
                            <div class="col-sm-7">
                                <input type="password" id="newPassword" class="form-control" required>
                                <span id="newpassword_err" style="color:red;"></span>
                            </div>
                        </div>

                        <div class="form-group">
                            <label class="control-label col-sm-4" for="confirmPassword">Confirm New Password:</label>
                            <div class="col-sm-7">
                                <input type="password" id="confirmPassword" class="form-control" required autofocus>
                                <span id="mismatch_err" style="color:red;"></span>
                            </div>
                        </div>
                        </div>

                        <div class="form-group">
                        <div class="col-sm-offset-8 col-sm-3">
                         <button id="submitbutton" class="btn btn-primary btn-block" type="button" onclick="checkUserAJAX()">Submit</button>

                         <button id="updatebutton" class="btn btn-primary btn-block" type="button" onclick="UPAJAX()">Update</button>
                         </div>
                         </div>

            </form>

            <div class="shark-info" style="margin-top:10px;">
                <p>Welcome to <b>Shark Portal, Nova Southeastern University</b>'s Internship Management System! To access the system, enter your SharkLink ID and password and click the Login button. If you experience technical difficulties, please contact XXXXX at XXXXX or XXXXX@nova.edu. If this is your first time accessing the Internship Management System, please click the Register Here link. Note that this portal will only give access to graduate students of the Nova community and admin users with pre-approved accounts.</p>
            </div>
        </div> <!-- /container -->
    </div>

 <div id="footer">
        <p>©2016 Nova Southeastern University <span>|</span> 3301 College Avenue, Fort Lauderdale, Florida 33314-7796 <span>|</span> 800-541-6682</p>
    </div>

    <!--Scripts are placed at the end so that page loads faster-->
    <script src="../js/jquery-1.10.2.js"></script>
    <script src="../js/changePassword.js"></script>

    <script>
        $("#updatepart").hide();
        $("#notification").hide();
        $("#updatebutton").hide();
    </script>


    </body>
</html>

<?php else:
    
    if($_SESSION['user_status'] == "student")
    {
        header("Location: s_home.php");
        die();
    }
    else
    {
        header("Location: a_home.php");
        die();
    }
    
 endif; ?>