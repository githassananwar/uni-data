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
	        	$msg = "Hello ".$row['username']."!\nA new Query has been received.\nStudent Name: ".$name."\nEmail: ".$email."\nMessage: ".$message."\nKindly visit Shark Internship Portal." ;
				
				mail($row['email'],"New Query",$msg);

	    }

	    $result=getAllSuperAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "Hello ".$row['username']."!\nA new Query has been received.\nStudent Name: ".$name."\nEmail: ".$email."\nMessage: ".$message."\nKindly visit Shark Internship Portal." ;
			
				mail($row['email'],"New Query",$msg);
	    }

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