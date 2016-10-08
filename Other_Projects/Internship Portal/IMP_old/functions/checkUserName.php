<?php
//***********************************************
//	For check Username with AJAX
//***********************************************

	
	$username = validate_input($_POST['name']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(check_admin_username($username) && check_superAdmin_username($username) && check_student_username($username)){
		print "available";
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