<?php
/**
 * Created by Softenica Technologies Softenica.com
 */
session_start();

if(isset($_SESSION['username']) && isset($_SESSION['login_status']) && isset($_SESSION['user_status']) && $_SESSION['user_status'] == "admin") :?>
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
    <link href="../fonts/css/font-awesome.min.css" rel="stylesheet">
    <link href="../styles/fileinput.min.css" media="all" rel="stylesheet" type="text/css" />
    <link rel="stylesheet" type="text/css" href="../styles/a_home.css" />
    <script src="../js/jquery-1.10.2.js"></script>
    <script src="../js/bootstrap.min.js"></script>
    <script src="../js/fileinput.min.js"></script>
    <script src="../js/updatePassword.js"></script>
    <script src="../js/updateEmail.js"></script>
    <script src="../js/addAdmin.js"></script>
    <script src="../js/checkUserName.js"></script>
    <script src="../js/answerQuery.js"></script>
</head>
<body>
    <header id="header" class="container">
        <div class="row">
            <div class="col-md-3 col-md-offset-1 col-sm-4 col-sm-offset-0" id="logo"><a href="http://www.nova.edu/" target="_blank"><img src="../images/logo.png" width="239" height="61" border="0" alt="Nova Southeastern University"></a></div>
            <div class="col-md-4 col-md-offset-1 col-sm-5 col-sm-offset-0" >
                <h3 class="nsu-title">Shark Internship Portal</h3>
            </div>
        </div>            
    </header>
    <div class="well">
        <div id="menu" class="row">
            <div class="col-md-5 col-sm-6 col-xs-8">
                <div id="account" class="col-sm-3 col-xs-4 padding-zero active" role="presentation">
                    <a href="#tab_account" role="tab" id="account-tab" data-toggle="tab" aria-expanded="false"><i class="fa fa-user" style="padding-right: 3px;"></i>My Account</a>
                </div>
                <div class="col-sm-9 col-xs-8 padding-zero">
                    <img id="separator" src="../images/separator.png"/>
                    <div id="welcome">
                        <b>Welcome, </b><?=
                        $bar = ucfirst($_SESSION['username']);
                        $bar = ucfirst(strtolower($bar)); 
                        ?>
                        <br />
                        <span id="log-span">You are currently logged in.</span>
                    </div>                                 
                </div>               
            </div> 
            <div class="col-md-2 col-md-offset-5 col-sm-3 col-sm-offset-3 col-xs-4 col-xs-offset-0 padding-zero">
                <img id="separator2" src="../images/separator.png" />
                <div style="margin-top:6px;">
                    <a href="../functions/logout.php"><i class="fa fa-sign-out" style="padding-right: 3px;"></i>Logout</a>
                </div>
                <div id="date" class="row">
                    <div class="">
                        <?=date("F d, Y")?>
                    </div>
                </div>
            </div>         
        </div>      
        <div id="tabs" class="row">
            <div class="x_content">

                <div class="" role="tabpanel" data-example-id="togglable-tabs">
                    <ul id="menuTabs" class="nav nav-tabs bar_tabs" role="tablist">
                        <li role="presentation" class="active">
                            <a href="#tab_home" id="home-tab" role="tab" data-toggle="tab" aria-expanded="true">Applications</a>
                        </li>
                        <li role="presentation" class="">
                            <a href="#tab_queries" role="tab" id="queries-tab" data-toggle="tab" aria-expanded="false"> Questions</a>
                        </li>
                        <?php if(isset($_SESSION['admin_type'])){ ?>
                        <li role="presentation" class="">
                            <a href="#tab_settings" role="tab" id="settings-tab" data-toggle="tab" aria-expanded="false">Settings</a>
                        </li>
                        <?php } ?>

                    </ul>
                </div>
            </div>
        </div>
        <div id="menuTabsContent" class="tab-content col-lg-8 col-md-8 col-sm-10 col-sm-offset-1 col-xs-12 col-md-offset-2 col-lg-offset-2">
            <div role="tabpanel" class="tab-pane fade active in panel" id="tab_home" aria-labelledby="home-tab">
                <div class="panel-heading">
                    <nav class="navbar navbar-inverse">
                        <div class="">
                            <div class="navbar-header">
                                <button type="button" class="navbar-toggle" data-toggle="collapse"
                                        data-target="#appNavbar">
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                </button>
                                <a class="navbar-brand">Applications</a>
                            </div>
                            <div>
                                <div class="collapse navbar-collapse" id="appNavbar">
                                    <ul id="appTabs" class="nav navbar-nav" role="tablist">
                                        <li role="presentation" class="active">
                                            <a href="#tab_pending" id="pending-tab" role="tab" data-toggle="tab" aria-expanded="true">Pending</a>
                                        </li>
                                        <li class="dropdown">
                                            <a class="dropdown-toggle" data-toggle="dropdown" href="#">Processed<span class="caret"></span></a>
                                            <ul class="dropdown-menu">
                                                <li role="presentation" class="">
                                                    <a href="#tab_accepted" role="tab" id="accepted-tab" data-toggle="tab" aria-expanded="false">Accepted</a>
                                                </li>
                                                <li role="presentation" class="">
                                                    <a href="#tab_rejected" role="tab" id="rejected-tab" data-toggle="tab" aria-expanded="false"> Denied</a>
                                                </li>
                                            </ul>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                    </nav>
                </div>
                <div class="panel-body" style="overflow-y: auto; max-height: 400px; min-height: 370px;">
                    <div class="tab-content">

                        <div role="tabpanel" class="tab-pane fade active in" id="tab_pending" aria-labelledby="pending-tab">
                        <!--Load data from requestList -->                   
                        </div>

                        <div role="tabpanel" class="tab-pane fade" id="tab_accepted" aria-labelledby="accepted-tab">
                         <!--Load data from requestList --> 
                        </div>

                        <div role="tabpanel" class="tab-pane fade" id="tab_rejected" aria-labelledby="rejected-tab">
                        <!--Load data from requestList --> 
                        </div>

                    </div>
                   
                </div>
            </div>


            <div role="tabpanel" class="tab-pane fade panel" id="tab_settings" aria-labelledby="settings-tab">
                <div class="panel-heading">
                    <nav class="navbar navbar-inverse">
                        <div class="">
                            <div class="navbar-header">
                                <button type="button" class="navbar-toggle" data-toggle="collapse"
                                        data-target="#settingsNavbar">
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                </button>
                                <a class="navbar-brand">Settings</a>
                            </div>
                            <div>
                                <div class="collapse navbar-collapse" id="settingsNavbar">
                                    <ul id="appTabs" class="nav navbar-nav" role="tablist">
                                        <li role="presentation" class="active">
                                            <a href="#tab_admin-list" id="admin-list-tab" role="tab" data-toggle="tab" aria-expanded="true">Admin List</a>
                                        </li>
                                        <li role="presentation" class="">
                                            <a href="#tab_add-admin" id="add-admin-tab" role="tab" data-toggle="tab" aria-expanded="false">Add Admin</a>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                    </nav>
                </div>
                <div class="panel-body" style="overflow-y: auto; max-height: 400px; min-height: 370px;">
                    <div class="tab-content">

                        <div role="tabpanel" class="tab-pane fade active in" id="tab_admin-list" aria-labelledby="admin-list-tab">
                        <!-- Loader -->
                        </div>

                        <div role="tabpanel" class="tab-pane fade" id="tab_add-admin" aria-labelledby="add-admin-tab">
                            <form role="form" class="form-horizontal register-form">

                                <div class="form-group">
                                    <label class="control-label col-sm-3" for="name">Username:</label>
                                    <div class="col-sm-7">
                                        <input type="text" id="username" class="form-control" onblur="checkUserNameAJAX()" required autofocus>
                                        <span id="err_username" style="color:red;"></span>
                                        <span id="available_username" style="color:green;"></span>
                                    </div>
                                </div>

                                <div class="form-group">
                                    <label class="control-label col-sm-3" for="password">Password:</label>
                                    <div class="col-sm-7">
                                        <input type="password" id="password" class="form-control" required>
                                        <span id="err_password" style="color:red;"></span>
                                    </div>
                                </div>

                                <div class="form-group">
                                    <label class="control-label col-sm-3" for="email">Email:</label>
                                    <div class="col-sm-7">
                                        <input type="text" id="email" class="form-control" required>
                                        <span id="err_email" style="color:red;"></span>
                                    </div>
                                </div>                             

                                <div class="form-group">
                                    <div class="col-sm-offset-8 col-sm-2">
                                        <button id="add_admin" class="btn btn-primary btn-block" type="button" onclick="addAdminAJAX()">Add</button>
                                    </div>
                                </div>

                            </form>
                        </div>

                    </div>

                </div>
            </div>


            <div role="tabpanel" class="tab-pane fade panel panel-primary" id="tab_queries" aria-labelledby="queries-tab">
                <div class="panel-heading">
                    Questions
                </div>
                <div id="query" class="panel-body" style="overflow-y: auto; max-height: 400px; min-height: 370px;">
                <!--Load Queries--> 
                </div>
            </div>

            <div role="tabpanel" class="tab-pane fade panel panel-primary" id="tab_account" aria-labelledby="account-tab">
                <div class="panel-heading">
                    My Account
                </div>
                <div class="panel-body">    
                     <h4>Change Password</h4>
                    <form role="form" class="form-horizontal register-form">
                        <div class="form-group">
                            <label class="control-label col-sm-4" for="oldPassword">Old Password:</label>
                            <div class="col-sm-7">
                                <input type="password" id="oldPassword" class="form-control" required autofocus>
                                 <span id="oldpassword_err" style="color:red;"></span>
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
                        <div class="form-group">
                            <div class="col-sm-offset-8 col-sm-3">
                                <button class="btn btn-primary btn-block" type="button" onclick="UPAJAX()">Update Password</button>
                            </div>
                        </div>
                    </form>

                     <div style="border-bottom: groove; margin-bottom:25px;"></div>  

                     <h4>Change Email</h4>
                    <form role="form" class="form-horizontal register-form">
                        <div class="form-group">
                            <label class="control-label col-sm-4" for="oldPassword">Old Email:</label>
                            <div class="col-sm-7">
                                <input type="text" id="oldEmail" class="form-control" required autofocus>
                                 <span id="oldEmail_err" style="color:red;"></span>
                            </div>
                        </div>

                        <div class="form-group">
                            <label class="control-label col-sm-4" for="newPassword">New Email:</label>
                            <div class="col-sm-7">
                                <input type="text" id="newEmail" class="form-control" required>
                                <span id="newEmail_err" style="color:red;"></span>
                            </div>
                        </div>

                        <div class="form-group">
                            <label class="control-label col-sm-4" for="confirmPassword">Confirm New Email:</label>
                            <div class="col-sm-7">
                                <input type="text" id="confirmEmail" class="form-control" required autofocus>
                                <span id="confirmEmail_err" style="color:red;"></span>
                            </div>
                        </div>
                        <div class="form-group">
                            <div class="col-sm-offset-8 col-sm-3">
                                <button class="btn btn-primary btn-block" type="button" onclick="emailUpdateAJAX()">Update Email</button>
                            </div>
                        </div>
                    </form>

                </div>
            </div>

        </div>
    </div>

   <div id="footer">
        <p>© 2016 Nova Southeastern University <span>|</span> 3301 College Avenue, Fort Lauderdale, Florida 33314-7796 <span>|</span> 800-541-6682</p>
    </div>

    <script>

        $("#account-tab").on('click', function () {
            $('#menuTabs li').removeClass('active');
        });

        /* ----------------------------------------------------------- */
        /*  BOOTSTRAP ACCORDION-1
        /* ----------------------------------------------------------- */

        $('#accordion_1 .panel-collapse').on('shown.bs.collapse', function () {
            $(this).prev().find(".fa").removeClass("fa-plus-square").addClass("fa-minus-square");
        });

        //The reverse of the above on hidden event:

        $('#accordion_1 .panel-collapse').on('hidden.bs.collapse', function () {
            $(this).prev().find(".fa").removeClass("fa-minus-square").addClass("fa-plus-square");
        });

        /* ----------------------------------------------------------- */
        /*  BOOTSTRAP ACCORDION-2
        /* ----------------------------------------------------------- */

        $('#accordion_2 .panel-collapse').on('shown.bs.collapse', function () {
            $(this).prev().find(".fa").removeClass("fa-plus-square").addClass("fa-minus-square");
        });

        //The reverse of the above on hidden event:

        $('#accordion_2 .panel-collapse').on('hidden.bs.collapse', function () {
            $(this).prev().find(".fa").removeClass("fa-minus-square").addClass("fa-plus-square");
        }); 

        //div Loader
        $(document).ready(function(){
            $("#tab_pending").load('pendingRequestList.php');
            $("#tab_accepted").load('approvedRequestList.php');
            $("#tab_rejected").load('deniedRequestList.php');
            $("#tab_admin-list").load('adminList.php');
            $("#query").load('queryList.php');
        });

       
</script>

</body>
</html>

<?php else:
    header("Location: ../index.php");
    die();

 endif; ?>
