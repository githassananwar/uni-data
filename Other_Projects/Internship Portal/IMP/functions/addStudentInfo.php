<?php
//***********************************************
//	For addition of Student Info with AJAX
//***********************************************

	session_start();
 
	$name = validate_input($_POST['name']);
	$username = validate_input($_POST['username']);
	$nsuid = validate_input($_POST['nsuid']);
	$phoneno = validate_input($_POST['phoneno']);
	$major = validate_input($_POST['major']);
	$agencyName = validate_input($_POST['agencyName']);
	$agencyAddress = validate_input($_POST['agencyAddress']);
	$agencyWebsite = validate_input($_POST['agencyWebsite']);
	$supervisorName = validate_input($_POST['supervisorName']);
	$supervisorphoneNo = validate_input($_POST['supervisorphoneNo']);
	$supervisorEmail = validate_input($_POST['supervisorEmail']);
	$term = validate_input($_POST['term']);
	$email = validate_input($_POST['email']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	$id=$_SESSION['registeredUserId'];

	if(addStudentInfo($id, $name, $nsuid, $phoneno, $major, $agencyName, $agencyAddress, $agencyWebsite, $supervisorName, $supervisorphoneNo, $supervisorEmail, $term) && addRequest($id) ){
		session_destroy();
		$result=getAllAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Student Request for Internship has been received.\nStudent Name: ".$name."\nNSU ID: ".$nsuid."\nCompany Name: ".$agencyName."\nKindly visit Shark Internship Portal for further details.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php" ;
				
				mail($row['email'],"New Student Request",$msg);

	    }

	    $result=getAllSuperAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "A new Student Request for Internship has been received.\nStudent Name: ".$name."\nNSU ID: ".$nsuid."\nCompany Name: ".$agencyName."\nKindly visit Shark Internship Portal for further details.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php" ;
			
				mail($row['email'],"New Student Request",$msg);
	    }

	    $msg = "Your application request for internship at ".$agencyName." has been submitted with Shark Internship portal. It is under consideration and you can view the status by logging into your account with your username and password.\nUsername: ".$username."\nKindly visit Shark Internship Portal for further details.\nhttp://www.softenica.com/Nicky/IMP-3.2/index.php" ;
			
		mail($email,"Internship Request Received",$msg);



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