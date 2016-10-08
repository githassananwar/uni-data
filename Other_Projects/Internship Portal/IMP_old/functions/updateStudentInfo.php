<?php
//***********************************************
//	For updation of Student Info with AJAX
//***********************************************

	session_start();
 
	$id = validate_input($_POST['id']);
	$agencyName = validate_input($_POST['agencyName']);
	$agencyAddress = validate_input($_POST['agencyAddress']);
	$agencyWebsite = validate_input($_POST['agencyWebsite']);
	$supervisorName = validate_input($_POST['supervisorName']);
	$supervisorphoneNo = validate_input($_POST['supervisorphoneNo']);
	$supervisorEmail = validate_input($_POST['supervisorEmail']);
	$term = validate_input($_POST['term']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	$_SESSION['registeredUserId']=$id;

	if(updateStudentInfo($id, $agencyName, $agencyAddress, $agencyWebsite, $supervisorName, $supervisorphoneNo, $supervisorEmail, $term) && updateRequest($id) ){
		$info=getStudentInfo($id);
		$result=getAllAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "Hello ".$row['username']."!\nA new Student Request for Internship has been received.\nStudent Name: ".$info['name']."\nNSU ID: ".$info['nsuid']."\nCompany Name: ".$info['agency']."\nKindly visit Shark Internship Portal for further details." ;
				
				mail($row['email'],"New Student Request",$msg);

	    }

	    $result=getAllSuperAdmins();
	    while ( $row = mysqli_fetch_assoc($result) ) {
	        	$msg = "Hello ".$row['username']."!\nA new Student Request for Internship has been received.\nStudent Name: ".$info['name']."\nNSU ID: ".$info['nsuid']."\nCompany Name: ".$info['agency_name']."\nKindly visit Shark Internship Portal for further details." ;
			
				mail($row['email'],"New Student Request",$msg);
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