<?php
/**
 * Created by Softenica Technologies Softenica.com
 */

session_start();

if(isset($_SESSION['username']) && isset($_SESSION['login_status']) && isset($_SESSION['user_status']) && $_SESSION['user_status'] == "student") :?>

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
    <link rel="stylesheet" type="text/css" href="../styles/s_home.css" />
    <script src="../js/jquery-1.10.2.js"></script>
    <script src="../js/bootstrap.min.js"></script>
    <script src="../js/fileinput.min.js"></script>
    <script src="../js/updatePassword.js"></script>
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
                    <a id="help" style="margin-left:15px;" href="help.php"><i class="fa fa-question-circle" style="padding-right: 3px;"></i>Help</a>
                </div>
                <div id="date"
                 class="row">
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
                            <a href="#tab_home" id="home-tab" role="tab" data-toggle="tab" aria-expanded="true">Home</a>
                        </li>
                        <li role="presentation" class="">
                            <a href="#tab_resources" role="tab" id="resource-tab" data-toggle="tab" aria-expanded="false">Career Quick Resources</a>
                        </li>
                        <li role="presentation" class="">
                            <a href="#tab_internships" role="tab" id="intership-tab" data-toggle="tab" aria-expanded="false"> Internships</a>
                        </li>
                    </ul>
                </div>
            </div>
        </div>
        <div id="menuTabsContent" class="tab-content col-lg-8 col-md-8 col-sm-10 col-sm-offset-1 col-xs-12 col-md-offset-2 col-lg-offset-2">
            <div role="tabpanel" class="tab-pane fade active in panel panel-primary" id="tab_home" aria-labelledby="home-tab">
                <div class="panel-heading">
                    Application Status
                </div>
                <div class="panel-body">
                
                    <table class="table table-hover">
                        <tbody>
                             <?php 
                          
                            $dbstatus = include "../functions/dbhandler.php";
                            if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                    print "ERROR.";
                            }
                            

                            $result=getStudent($_SESSION['userid']);
                            if ( $result ) {
                        
                            ?>

                            <tr>
                                <th>Date of Submission</th>
                                <th><?= $result['registerdate'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <?php $info=getStudentInfo($_SESSION['userid']); ?>
                            <tr>
                                <th>Name</th>
                                <th><?= $info['name'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>NSU ID</th>
                                <th><?= $info['nsuid'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Email</th>
                                <th><?= $result['email'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Phone no</th>
                                <th><?= $info['phoneno'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Term</th>
                                <th><?= $info['term'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Major</th>
                                <th><?= $info['major'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Company Name</th>
                                <th><?= $info['agency'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr> 
                            <tr>
                                <th>Company Address</th>
                                <th><?= $info['agency_address'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr> 
                            <tr>
                                <th>Company Website</th>
                                <th><?= $info['agency_website'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr> 
                            <tr>
                                <th>Supervisor</th>
                                <th><?= $info['supervisor_name'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Supervisor Email</th>
                                <th><?= $info['supervisor_email'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th>Supervisor PhoneNo</th>
                                <th><?= $info['supervisor_phoneno'] ?></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            
                            <?php $request=getStudentRequest($_SESSION['userid']); ?>
                            <tr>
                                <th>Application Status</th>
                                <th><i><?= $request['status'] ?></i></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <?php if ( $request['status']=='Denied' ) { ?>
                            <tr>
                                <th>Reason</th>
                                <th><i><?= $request['reason'] ?></i></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>
                            <tr>
                                <th><a href="register.php" style="text-decoration:underline">Submit a New Request</a></th>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>

                             <?php } ?>
                            <tr>
                                <td></td>
                                <td></td>
                                <td></td>
                                <td></td>
                                <td></td>
                            </tr>

                         <?php } ?>
                        </tbody>
                    </table>
                </div>
            </div>
            <div role="tabpanel" class="tab-pane fade panel panel-primary" id="tab_resources" aria-labelledby="resource-tab">
                <div class="panel-heading">
                    Career Quick Resources
                </div>
                <div class="panel-body">
                    <div class="panel-group" id="accordion_1">
                        <div class="panel panel-default">
                            <div class="panel-heading">
                                <h4 class="panel-title">
                                    <a data-toggle="collapse" data-parent="#accordion_1" href="#collapseOne_1">
                                        Career Resource Guides<span class="fa fa-minus-square"></span>
                                    </a>
                                </h4>
                            </div>
                            <div id="collapseOne_1" class="panel-collapse collapse in">
                                <div class="panel-body">
                                    <ul>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/cover_letter_guide.pdf" target="_blank">Cover Letter</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/curriculum_vita_guide.pdf" target="_blank">Curriculum Vita</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/4year_career_planning_guide.pdf" target="_blank">Four-Year Career Plan</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/internship_guide.pdf" target="_blank">Internship</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/interviewing_guide.pdf" target="_blank">Interviewing</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/job_search_guide.pdf" target="_blank">Job Search</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/networking_information_interviewing_guide.pdf" target="_blank">Networking and Informational Interviewing</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/par_star.pdf" target="_blank">PAR Statements and STAR Format</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/personal_statement_guide.pdf" target="_blank">Personal Statement</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/preparing_for_graduate_school_guide.pdf" target="_blank">Preparing for Graduate School</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/resume_basics_guide.pdf" target="_blank">Resume Basics</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/resume_writing_guide.pdf" target="_blank">Resume Writing</a>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                        <div class="panel panel-default ">
                            <div class="panel-heading">
                                <h4 class="panel-title">
                                    <a data-toggle="collapse" data-parent="#accordion_1" href="#collapseTwo_1">
                                        Overview of Services for <span class="fa fa-plus-square"></span>
                                    </a>
                                </h4>
                            </div>
                            <div id="collapseTwo_1" class="panel-collapse collapse">
                                <div class="panel-body">
                                    <ul>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/overview_services_main_campus.pdf" target="_blank">Students (Main Campus)</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/forms/overview_services_student_educational_centers.pdf" target="_blank">SEC Students</a>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div role="tabpanel" class="tab-pane fade panel panel-primary" id="tab_internships" aria-labelledby="intership-tab">
                <div class="panel-heading">
                    Internships
                </div>
                <div class="panel-body">
                    <div class="panel-group" id="accordion_2">
                        <div class="panel panel-default">
                            <div class="panel-heading">
                                <h4 class="panel-title">
                                    <a href="http://www.nova.edu/career/resources/letter_to_students.html" target="_blank">
                                        Letter to Students
                                    </a>
                                </h4>
                            </div>
                        </div>

                        <div class="panel panel-default">
                            <div class="panel-heading">
                                <h4 class="panel-title">
                                    <a data-toggle="collapse" data-parent="#accordion_2" href="#collapseOne_2">
                                        Internship Tools<span class="fa fa-minus-square"></span>
                                    </a>
                                </h4>
                            </div>
                            <div id="collapseOne_2" class="panel-collapse collapse in">
                                <div class="panel-body">
                                    <ul>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/internship_faqs.html" target="_blank">Internship FAQ's</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/tips_successful_internship.html" target="_blank">Tips for a successful Internship</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/converting_your_internship.html" target="_blank">Converting Your Internship</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/after_your_internship.html" target="_blank">After Your Internship</a>
                                        </li>                             
                                    </ul>
                                </div>
                            </div>
                        </div>

                        <div class="panel panel-default ">
                            <div class="panel-heading">
                                <h4 class="panel-title">
                                    <a data-toggle="collapse" data-parent="#accordion_2" href="#collapseTwo_2">
                                        Student Information <span class="fa fa-plus-square"></span>
                                    </a>
                                </h4>
                            </div>
                            <div id="collapseTwo_2" class="panel-collapse collapse">
                                <div class="panel-body">
                                    <ul>

                                        <li>
                                            <a href="http://www.nova.edu/career/resources/student_participation_requirements.html" target="_blank">Student Participation Requirements</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/forms/internship_preparation_checklist.pdf" target="_blank">Internship Preparation Checklist </a>
                                        </li>
                                        <li>
                                            <a href="#" target="_blank">Non-Academic Credit Syllabus</a>
                                        </li>
                                        <li>
                                            <a href="#" target="_blank">Sample Academic Credit Syllabus</a>
                                        </li>
                                        <li>
                                            <a href="#" target="_blank">Student Internship Agreement</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/forms/student_internship_reqmts_receive_academic_credit.pdf" target="_blank">Student Internship Requirements to Receive Academic Credit</a>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>

                        <div class="panel panel-default ">
                            <div class="panel-heading">
                                <h4 class="panel-title">
                                    <a data-toggle="collapse" data-parent="#accordion_2" href="#collapseThree_2">
                                        Internship Listing & Web Resources <span class="fa fa-plus-square"></span>
                                    </a>
                                </h4>
                            </div>
                            <div id="collapseThree_2" class="panel-collapse collapse">
                                <div class="panel-body">
                                    <ul>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/fortune_500_internship_listings.html" target="_blank">Fortune 500 Internship Listings</a>
                                        </li>
                                        <li>
                                            <a href="http://www.nova.edu/career/resources/internship_websites.html" target="_blank">Internship Web Resources </a>
                                        </li>                         
                                    </ul>
                                </div>
                            </div>
                        </div>

                    </div>
                </div>
            </div>

            <div role="tabpanel" class="tab-pane fade panel panel-primary" id="tab_account" aria-labelledby="account-tab">
                <div class="panel-heading">
                    Change Password
                </div>
                <div class="panel-body">
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
                                <button class="btn btn-primary btn-block" type="button" onclick="UPAJAX()">Update</button>
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

    </script>
   

</body>
</html>


<?php else:
    
    header("Location: ../index.php");
    die();
    
 endif; ?>
