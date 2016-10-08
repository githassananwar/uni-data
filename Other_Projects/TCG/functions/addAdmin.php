<?php
//***********************************************
//	For addition of Admin with AJAX
//***********************************************

	
	$username = validate_input($_POST['user']);
	$password = validate_input($_POST['password']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if( !(check_admin_username($username) && check_superAdmin_username($username)) ){
		print "unavailable";
	}
	else if(addAdmin($username, $password)){
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