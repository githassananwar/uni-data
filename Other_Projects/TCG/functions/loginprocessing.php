<?php
//***********************************************
//	For login with AJAX
//***********************************************
	
	session_start();
	//Verifying user input for security
	$username = validate_input($_POST['username']);
	$password = validate_input($_POST['password']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(validate_superAdmin($username, $password)!=null){
		
		$_SESSION['username'] = $username;
		$_SESSION['userid'] = validate_superAdmin($username, $password);
		$_SESSION['admin_type'] = "super";
		
		print "login";
	}
	else if(validate_admin($username, $password)!=null){
		
		$_SESSION['username'] = $username;
		$_SESSION['userid'] = validate_admin($username, $password);
	
		print "login";
	}

	else
	{
		print "Invalid";
	}

	function validate_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
?>