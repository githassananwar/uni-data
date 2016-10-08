<?php
//***********************************************
//	For upload with AJAX
//***********************************************

	session_start();

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}
	
	
	$id=$_SESSION['upload_id'];
	$role=$_SESSION['create_role'];
	
	print_r($id);
	
	die();
	
	

	
	
	
?>