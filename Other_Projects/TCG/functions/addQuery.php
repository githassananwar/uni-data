<?php
//***********************************************
//	For addition of Query with AJAX
//***********************************************

	
	$name = validate_input($_POST['name']);
	$email = validate_input($_POST['email']);
	$subject = validate_input($_POST['subject']);
	$message = validate_input($_POST['message']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(addMessage($name, $email, $subject, $message) ){
		$result=getAllAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Question has been received.\nName: ".$name."\nEmail: ".$email."\n\nMessage: ".$message."\n\nKindly reply on the mentioned email address.";
				
				mail($row['username'],$subject,$msg);

	    }

	    $result=getAllSuperAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Question has been received.\nName: ".$name."\nEmail: ".$email."\n\nMessage: ".$message."\n\nKindly reply on the mentioned email address.";
			
				mail($row['username'],$subject,$msg);
	    }

	    $msg = "Your following question has been successfully received at Technical Consultants Group.\n\nQuestion: ".$message."\n\nWe will get back to you shortly. You will be replied on same email address." ;	
		mail($email,"Question received",$msg);

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