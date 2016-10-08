<?php
//***********************************************
//	For denial Request with AJAX
//***********************************************

	session_start();
	$id = validate_input($_POST['id']);
	$reason = validate_input($_POST['reason']);
	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(denyRequest($id,$reason)){

		if(isset($_SESSION['admin_type']))
		{
			$superAdminid=$_SESSION['userid'];
			if( strcmp($reason,'Did not meet site criteria') && strcmp($reason,'Did not meet academic criteria') && checkSuperAdminOtherReasons($superAdminid,$reason) )
			{
				addReasonSuperAdmin($superAdminid,$reason);
			}
			$email=getRequestEmail($id);
			$msg = "Your request for Internship has been denied by Administration.\nReason of Denial: ".$reason."\nKindly login to your Shark portal account and complete a new registration.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php";
		
			// send email
			mail($email,"Notification for Internship Request",$msg);
			print "updated";
		}
		else
		{
			$adminid=$_SESSION['userid'];
			if( strcmp($reason,'Did not meet site criteria') && strcmp($reason,'Did not meet academic criteria') && checkAdminOtherReasons($adminid,$reason) )
			{
				addReasonAdmin($adminid,$reason);
			}
			$email=getRequestEmail($id);
			$msg = "Your request for Internship has been denied by Administration.\nReason of Denial: ".$reason."\nKindly login to your Shark portal account and complete a new registration.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php";
		
			// send email
			mail($email,"Notification for Internship Request",$msg);
			print "updated";
		}
		
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