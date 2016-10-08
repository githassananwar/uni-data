<?php
//***********************************************
//	For generate Code with AJAX
//***********************************************

	
	$username = validate_input($_POST['name']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	$code=rand(10000,100000);

	$email=getEmail($username);
	//email functionality
	$msg = "Your password change request has been received. \nEnter this code: ".$code;

	// send email
	mail($email,"Reply from Admin",$msg);

	if(generateCodeAdmin($username, $code) && generateCodeSuper($username, $code) && generateCodeStudent($username, $code) ){
		print "generated";
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