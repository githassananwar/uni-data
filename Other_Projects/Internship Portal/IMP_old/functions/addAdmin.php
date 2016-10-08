<?php
//***********************************************
//	For addition of Admin with AJAX
//***********************************************

	
	$username = validate_input($_POST['user']);
	$password = validate_input($_POST['password']);
	$email = validate_input($_POST['email']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(addAdmin($username, $password, $email)){
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