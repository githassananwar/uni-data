<?php
    session_start();

    $dbstatus = include "../functions/dbhandler.php";
    if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
        print "ERROR. Could not logout";
        die();
    }
    $username = $_SESSION['username'];
    $logout_time = date("Y-m-d H:i:s", strtotime('-6 hours'));

    if($_SESSION['user_status'] == "student"){
        unset_login_status_and_time_student($username,$logout_time);
    }
    else{
        
        if(isset($_SESSION['admin_type']))
        {
            unset_login_status_and_time_superAdmin($username,$logout_time);   
        }
        else
        {
            unset_login_status_and_time_admin($username,$logout_time);
        }
        
    }

    session_destroy();
    header("location: ../index.php");
?>