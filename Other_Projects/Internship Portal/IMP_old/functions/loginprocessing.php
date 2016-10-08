<?php
//***********************************************
//	For login with AJAX
//***********************************************
	
	session_start();
	//Verifying user input for security
	$username = validate_input($_POST['user']);
	$pass = validate_input($_POST['password']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(validate_superAdmin($username, $pass)!=null){
		
		$login_time = date("Y-m-d H:i:s", strtotime('-6 hours'));
		$res = set_login_status_and_time_superAdmin($username,$login_time);
		if($res) {
			$_SESSION['username'] = $username;
			$_SESSION['userid'] = validate_superAdmin($username, $pass);
			$_SESSION['login_status'] = "true";
			$_SESSION['user_status'] = "admin";
			$_SESSION['admin_type'] = "super";
		}
		else{
			return "Invalid";
		}
		print "admin";
	}

	else if(validate_admin($username, $pass)!=null){
		$login_time = date("Y-m-d H:i:s", strtotime('-6 hours'));
		$res = set_login_status_and_time_admin($username,$login_time);
		if($res) {
			$_SESSION['username'] = $username;
			$_SESSION['userid'] = validate_admin($username, $pass);
			$_SESSION['login_status'] = "true";
			$_SESSION['user_status'] = "admin";
		}
		else{
			return "Invalid";
		}
		print "admin";
	}
	else if(validate_student($username, $pass)!=null){
			$login_time = date("Y-m-d H:i:s", strtotime('-6 hours'));
			$res = set_login_status_and_time_student($username,$login_time);
			if($res) {
				$_SESSION['username'] = $username;
				$_SESSION['userid'] = validate_student($username, $pass);
				$_SESSION['login_status'] = "true";
				$_SESSION['user_status'] = "student";
			}
			else{
				return "Invalid";
			}
			print "student";
		}
	else{
			print "Invalid";
		}

	function validate_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
?>