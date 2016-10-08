<?php
//***********************************************
//	For approve Request with AJAX
//***********************************************

	
	$id = validate_input($_POST['id']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(approveRequest($id)){
		//$email=getRequestEmail($id);
		//$msg = "Hi there!\nHope your are doing well.\nYour request for Internship has been approved by Administration.";
	
		// send email
		//mail($email,"Notification for Internship Request",$msg);

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