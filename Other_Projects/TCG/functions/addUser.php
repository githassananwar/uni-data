<?php
//***********************************************
//	For addition of User with AJAX
//***********************************************
	
	session_start();
	
	$jobid = validate_input($_POST['jobid']);
	$firstname = validate_input($_POST['firstname']);
	$lastname = validate_input($_POST['lastname']);
	$email = validate_input($_POST['email']);
	$phone = validate_input($_POST['phone']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
	}

	

	if(addUser($jobid, $firstname, $lastname, $email, $phone)){
		$_SESSION['registeredUserId'] = getUserId();

		$result=getAllAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Applicant Request has been received.\nApplicant Name: ".$firstname." ".$lastname."\nEmail: ".$email."\nPhone no: ".$phone."\nKindly visit TCG Admin portal for further details." ;
				
				mail($row['username'],"New Applicant Request",$msg);

	    }

	    $result=getAllSuperAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Applicant Request has been received.\nApplicant Name: ".$firstname." ".$lastname."\nEmail: ".$email."\nPhone no: ".$phone."\nKindly visit TCG Admin portal for further details." ;
			
				mail($row['username'],"New Applicant Request",$msg);
	    }

	    $msg = "Your application request for Technical Consultants Group has been submitted successfully.\nYou will be informed about your application status shortly.";
			
		mail($email,"Application Request Received",$msg);

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