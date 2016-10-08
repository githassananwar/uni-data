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
		$email=getRequestEmail($id);
		$msg = "Congratulations!\nYour internship request has been approved. If you have any questions or need more information, please login to your account via the Shark Internship Portal.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php";
	
		// send email
		mail($email,"Notification for Internship Request",$msg);

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