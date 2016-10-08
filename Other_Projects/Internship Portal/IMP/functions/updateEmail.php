<?php
//***********************************************
//	For update Email with AJAX
//***********************************************

	//Verifying user input for security
	$oldEmail = validate_input($_POST['oldEmail']);
	$newEmail = validate_input($_POST['newEmail']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(!validate_oldEmail($oldEmail)){
		print "notmatched";
	}
	
	else if(update_email($newEmail)){
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