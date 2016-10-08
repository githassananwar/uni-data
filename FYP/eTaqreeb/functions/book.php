<?php


	$amount = $_POST['amount'];
	$id = $_POST['id'];
	
	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	if(check_book($amount, $id)){
		print "ok";
	}
	else
	{
		print "alert";
	}


	
	function validate_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
	
?>