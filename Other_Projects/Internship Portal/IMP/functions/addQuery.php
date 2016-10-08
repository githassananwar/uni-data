<?php
//***********************************************
//	For addition of Query with AJAX
//***********************************************

	
	$name = validate_input($_POST['name']);
	$nsuid = validate_input($_POST['nsuid']);
	$email = validate_input($_POST['email']);
	$message = validate_input($_POST['message']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(addQuery($name, $nsuid, $email, $message) ){
		$result=getAllAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Question has been received.\nStudent Name: ".$name."\nEmail: ".$email."\n\nMessage: ".$message."\n\nKindly visit Shark Internship Portal.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php" ;
				
				mail($row['email'],"New Question",$msg);

	    }

	    $result=getAllSuperAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Question has been received.\nStudent Name: ".$name."\nEmail: ".$email."\n\nMessage: ".$message."\n\nKindly visit Shark Internship Portal.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php" ;
			
				mail($row['email'],"New Question",$msg);
	    }

	    $msg = "Your following question has been successfully received at Shark Internship portal.\n\nQuestion: ".$message."\n\nWe will get back to you shortly. You will be replied on same email address." ;	
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