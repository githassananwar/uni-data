<?php
//***********************************************
//	For answer of Query with AJAX
//***********************************************

	
	$reply = validate_input($_POST['reply']);
	$id = validate_input($_POST['id']);
	$email = validate_input($_POST['email']);
	$name = validate_input($_POST['name']);

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	$queryMessage=getQueryMessage($id);
	$msg = "Hello ".$name."!\nHope your are doing well. Following is the response by Administration to your query:-\nQuery: ".$queryMessage."\nReply: ".$reply;
	
	// send email
	mail($email,"Reply from Admin",$msg);

	if(addReply($id) ){
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