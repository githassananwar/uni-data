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
    <link rel="stylesheet" type="text/css" href="styles/bootstrap.min.css" />
    <link rel="stylesheet" type="text/css" href="styles/master.css" />

</head>
<body>
    <header id="header" class="container col-md-12 col-lg-12 col-sm-12 col-xs-12">
            <div class="col-md-3 col-md-offset-1" id="logo"><a href="http://www.nova.edu/" target="_blank"><img src="images/logo.png" width="239" height="61" border="0" alt="Nova Southeastern University"></a></div>
            <div class="col-md-4">
                <h3 class="nsu-title">Shark Internship Portal </h3>
            </div>
    </header>
    <div id="nova-background" class="container">
        <div class="from-container col-lg-4 col-lg-offset-4 col-sm-6 col-sm-offset-3 col-md-4 col-md-offset-4 col-xs-10 col-xs-offset-1">          
            <div class="row logo-container">               
                <div class="col-md-6 col-sm-6 col-xs-6 col-md-offset-3 col-sm-offset-3 col-xs-offset-3">
                    <img class="logo-img-shark" src="images/shark-learn-logo.png">
                </div>
            </div>            
            <form class="form-signin login-form">
                <div id="invalid_Err_Msg">
                    The username or password you entered is incorrect. Please try again.
                </div><br />
                <label for="username">Username:</label>
                <span id="username_err" style="color:red;"></span>
                <div id="username_input_div">
                    <input type="text" id="username" class="form-control input-lg has-error" required autofocus><br />
                </div>
                <label for="password">Password:</label>
                <span id="password_err" style="color:red;"></span>
                <div id="password_input_div">
                    <input type="password" id="password" class="form-control input-lg" required><br />
                </div>
                <button class="btn btn-lg btn-primary btn-block" type="button" onclick="LoginAJAX()">Login</button>
            </form>
            <div class="row" style="margin-top:10px;">
                <div class="col-md-8" style="margin-top: 10px;">Don't have an account? <a href="scripts/register.php">Register Here</a></div>
                <div class="col-md-4" style="margin-top: 10px; "><a href="scripts/changePassword.php">Forgot password?</a></div>
                <div class="col-md-4" style="margin-top: 10px; "><a href="scripts/help.php">Support</a></div>
            </div>
            <div class="shark-info" style="margin-top:10px;">
                <p>Welcome to <b>Shark Portal, Nova Southeastern University</b>'s Internship Management System! To access the system, enter your SharkLink ID and password and click the Login button. If you experience technical difficulties, please contact XXXXX at XXXXX or XXXXX@nova.edu. If this is your first time accessing the Internship Management System, please click the Register Here link. Note that this portal will only give access to graduate students of the Nova community and admin users with pre-approved accounts.</p>
            </div>
        </div> <!-- /container -->
    </div>
    <div id="middle-background" class="container">
        <div class="panel-container">
            <div id="whynsu" class="col-xs-12 col-sm-12 col-md-10 col-lg-10 col-xs-offset-0 col-sm-offset-0 col-md-offset-1 col-lg-offset-1">
                <p class="row darkgrey"><strong>NSU's College of Engineering and Computing supports niche specializations and enjoys a stellar national reputation.</strong></p>
                <div class="row">
                    <div id="whyleft" class="col-xs-12 col-sm-5 col-md-4 col-lg-4">
                        <ul>
                            <li class="one">The <strong>College of Engineering and Computing prepares leaders</strong> for the challenges of the 21st century.</li>
                            <li class="two"><strong>Working professionals appreciate flexible formats</strong> to complete degree programs without career interruption.</li>
                            <li class="three">NSU serves the nation as a <strong>National Center of Academic Exellence in Information Assurance & Cyber Defense Education</strong>.</li>
                            <li class="four">Our multimillion dollar <strong>supercomputer</strong>, Megaladon, will propel research within a new Centre for Collaborative Research.</li>
                            <li class="five">Since 1975, NSU has been a regional <strong>pioneer of computing research and education</strong>.</li>
                        </ul>
                    </div>
                    <div id="whynsu_bg" class=" col-sm-2 col-md-4 col-lg-4">                     
                        <img class="img-responsive" src="images/whynsu_bg.png" />
                    </div>
                    
                    <div id="whyright" class="col-xs-12 col-sm-5 col-md-4 col-lg-4">
                        <ul>
                            <li class="six"><strong>Distinguished faculty research and teach</strong> a range of systems and emerging technologies.</li>
                            <li class="seven">Updated curricula make our <strong>undergraduate and graduate programs</strong> truly current.</li>
                            <li class="eight">The College was online in 1983 and created the <strong>first electronic classroom</strong> in 1985.</li>
                            <li class="nine">Graduate certificates cover <strong>fields of urgent need</strong>, such as cyber security and analytics.</li>
                            <li class="ten"><strong>Alumni work</strong> at Fortune 500 organizations, various federal and government agencies, and universities <strong>around the globe</strong>.</li>
                        </ul>
                    </div>
                </div>

            </div>
        </div>
    </div>
    <div id="footer">
        <p>©2016 Nova Southeastern University <span>|</span> 3301 College Avenue, Fort Lauderdale, Florida 33314-7796 <span>|</span> 800-541-6682</p>
    </div>

    <!--Scripts are placed at the end so that page loads faster-->
    <script src="js/jquery-1.10.2.js"></script>
    <script src="js/loginscript.js"></script>
</body>
</html>



<?php else:
    
    if($_SESSION['user_status'] == "student")
    {
        header("Location: scripts/s_home.php");
        die();
    }
    else
    {
        header("Location: scripts/a_home.php");
        die();
    }
    
 endif; ?>

