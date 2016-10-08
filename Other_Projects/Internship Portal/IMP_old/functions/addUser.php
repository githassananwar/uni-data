<?php
//***********************************************
//	For addition of User with AJAX
//***********************************************
	
	session_start();
	
	$username = validate_input($_POST['username']);
	$password = validate_input($_POST['password']);
	$email = validate_input($_POST['email']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
	}

	

	if(addUser($username, $password, $email)){
		$_SESSION['registeredUserId'] = getUserId($username);
		print "add";
	}
	else
	{
		print "fail";
	}

	
	function validate_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
	
?>