<?php
//***********************************************
//	For update Password with AJAX
//***********************************************

	//Verifying user input for security
	$oldpassword = validate_input($_POST['oldpass']);
	$newpassword = validate_input($_POST['newpass']);
	$confirmpassword = validate_input($_POST['confirmpass']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(!validate_oldPassword($oldpassword)){
		print "notmatched";
	}
	
	else if(update_password($newpassword)){
		print "updated";
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