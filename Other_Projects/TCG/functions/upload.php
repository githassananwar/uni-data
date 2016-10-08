<?php
//***********************************************
//	For upload with AJAX
//***********************************************

	session_start();

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	$id=$_SESSION['registeredUserId'];
	
	$sourcePath1 = $_FILES['resume']['tmp_name'];    
	$temp1 = explode(".", $_FILES["resume"]["name"]);
	$newPath1 =  'resume' . $id . '.' . end($temp1);
	addResume($newPath1,$id);
	$targetPath1 = "../resume/".$newPath1;

	$sourcePath2 = $_FILES['coverletter']['tmp_name'];    
	$temp2 = explode(".", $_FILES["coverletter"]["name"]);
	$newPath2 =  'coverLetter' . $id . '.' . end($temp2);
	addCoverLetter($newPath2,$id);
	$targetPath2 = "../coverLetter/".$newPath2;


	if(move_uploaded_file($sourcePath1,$targetPath1) && move_uploaded_file($sourcePath2,$targetPath2) ){
		print "upload";
	}
	else
	{
		print "fail";
	}

	
	
	
?>