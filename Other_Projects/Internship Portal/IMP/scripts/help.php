<?php
/**
 * Created by Softenica Technologies Softenica.com
 */
session_start();
?>

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
    <link rel="shortcut icon" href="../images/only-nsu.png" type="image/png" />
    <title>Shark Internship Portal</title>
    <link rel="stylesheet" type="text/css" href="../styles/bootstrap.css" />
    <link href="../styles/fileinput.min.css" media="all" rel="stylesheet" type="text/css" />
    <link rel="stylesheet" type="text/css" href="../styles/help.css" />
    <script src="../js/jquery-1.10.2.js"></script>
    <script src="../js/bootstrap.min.js"></script>
    <script src="../js/fileinput.min.js"></script>
    <script src="../js/addQuery.js"></script>
</head>
<body>
    <header id="header" class="container">
        <div class="row">
            <div class="col-md-3 col-md-offset-1 col-sm-4 col-sm-offset-0" id="logo"><a href="http://www.nova.edu/" target="_blank"><img src="../images/logo.png" width="239" height="61" border="0" alt="Nova Southeastern University"></a></div>
            <div class="col-md-4 col-md-offset-2 col-sm-5 col-sm-offset-1">
                <h3 class="nsu-title">Shark Internship Portal</h3>
            </div>
        </div>
    </header>
    <div class="well">

        <div class="row">
            <div class="col-lg-3 col-md-3 col-sm-4 col-xs-10 col-lg-offset-1 col-md-offset-1 col-sm-offset-0 col-xs-offset-1  panel panel-primary menu-panel">
                <div class="panel-body">
                    <ul class="nav nav-pills nav-stacked filter wow bounceIn" data-wow-delay="500ms">
                        <li class="active"><a data-toggle="pill" href="#general-help">General Help</a></li>
                        <li><a data-toggle="pill" href="#purpose">Purpose</a></li>
                        <li><a data-toggle="pill" href="#responsibilities">Responsibilities</a></li>
                        <li><a data-toggle="pill" href="#support">Support</a></li>
                        <?php if(isset($_SESSION['username']) ){ ?>
                        <li><a href="../functions/logout.php">Logout</a></li>
                        <li><a href="s_home.php">Back to Home</a></li>
                        <?php } else { ?>
                        <li><a href="s_home.php">Back</a></li> <?php } ?>
                    </ul>
                </div>
            </div>

            <div class="tab-content  col-lg-6 col-md-6 col-sm-7 col-sm-offset-1 col-xs-12 col-md-offset-1 col-lg-offset-1">
                <!-- General help content -->
                <div id="general-help" class="tab-pane fade in active panel panel-primary">
                    <div class="panel-heading">
                        General Help
                    </div>
                    <div class="panel-body">
                       <p>
                           We strive to make your online experience as enjoyable as possilble.To get general help information about system or it's basic
                           functionality, click any of the topics on menu.
                       </p>
                    </div>
                </div>

                <!-- Purpose content -->
                <div id="purpose" class="tab-pane fade panel panel-primary">
                    <div class="panel-heading">
                        Purpose
                    </div>
                    <div class="panel-body">
                        <p>
                            Nova Southeastern University’s (NSU) College of Engineering Internship Program provides an educational strategy whereby students complement their academic preparation with direct practical experience.
                            The effort to combine a productive work experience with an intentional learning component is
                            a proven method for promoting the academic, personal, and career development of students.
                            Your participation exhibits your interest and commitment to this educational strategy and to the growth and development
                            of students as future professionals. We look forward to collaborating with you in this work/learning endeavor.
                        </p>
                    </div>
                </div>

                <!-- Responsibilities content -->
                <div id="responsibilities" class="tab-pane fade panel panel-primary">
                    <div class="panel-heading">
                        Responsibilities
                    </div>
                    <div class="panel-body">
                        <p>
                            To help ensure the interests and promote the benefits of an internship arrangement for all parties involved,
                            NSU has developed this agreement of understanding to describe the mutual responsibilities between NSU and your
                            organization.
                        </p>
                    </div>
                </div>

                <!-- Support content -->
                <div id="support" class="tab-pane fade panel panel-primary">
                    <div class="panel-heading">
                        Support
                    </div>
                    <div class="panel-body">

                        <div class="support-title-area" style="text-align:center">
                            <h3>Have any Questions?</h3>
                            <p style="text-align:center;">Our support team is always there to answer your questions. Feel free to contact us.</p>
                            <br/>
                        </div>

                        <form role="form" class="form-horizontal support-form">

                            <div class="form-group">
                                <label class="control-label col-sm-4" for="name">Name:</label>
                                <div class="col-sm-7">
                                    <input type="text" id="name" class="form-control" required autofocus>
                                    <span id="err_name" style="color:red;"></span>
                                </div>
                            </div>

                            <div class="form-group">
                                <label class="control-label col-sm-4" for="NsuId">NSU ID:</label>
                                <div class="col-sm-7">
                                    <input type="text" id="nsuId" class="form-control" required>
                                    <span id="err_nsuid" style="color:red;"></span>
                                </div>
                            </div>

                            <div class="form-group">
                                <label class="control-label col-sm-4" for="email">Email:</label>
                                <div class="col-sm-7">
                                    <input type="text" id="email" class="form-control" required>
                                    <span id="err_email" style="color:red;"></span>
                                </div>
                            </div>

                            <div class="form-group">
                                <label class="control-label col-sm-4" for="message">Your Message:</label>
                                <div class="col-sm-7">
                                    <textarea id="message" rows="3" class="form-control" required autofocus style="resize:vertical"></textarea>
                                    <span id="err_message" style="color:red;"></span>
                                </div>
                            </div>                          

                            <div class="form-group">
                                <div class="col-sm-offset-8 col-sm-3">
                                    <button class="btn btn-primary btn-block" type="button" onclick="addQueryAJAX()">SUBMIT</button>
                                </div>
                            </div>

                        </form>
                    </div>
                </div>
            </div>

        </div>
    </div>
    <div id="footer">
        <p>©2016 Nova Southeastern University <span>|</span> 3301 College Avenue, Fort Lauderdale, Florida 33314-7796 <span>|</span> 800-541-6682</p>
    </div>
</body>
</html>