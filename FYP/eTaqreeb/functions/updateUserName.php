<?php
//***********************************************
//	For check Username with AJAX
//***********************************************

	
	$username = validate_input($_POST['name']);
	$id = validate_input($_POST['id']);
	$role = validate_input($_POST['role']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if($role=='customer')
	{
		if(check_custUpdate_username($username, $id) && check_vendor_username($username) && check_admin_username($username)){
			print "available";
		}
		else
		{
			print "fail";
		}
	}
	else if($role=='vendor')
	{
		if(check_customer_username($username) && check_vendUpdate_username($username, $id) && check_admin_username($username)){
			print "available";
		}
		else
		{
			print "fail";
		}
	}
	else if($role=='admin')
	{
		if(check_customer_username($username) && check_vendor_username($username) && check_admUpdate_username($username, $id)){
			print "available";
		}
		else
		{
			print "fail";
		}
	}
	


	
	function validate_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
	
?>