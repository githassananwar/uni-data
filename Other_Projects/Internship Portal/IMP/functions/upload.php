<?php
//***********************************************
//	For upload with AJAX
//***********************************************

	session_start();

	$dbstatus = include "dbhandler.php";
	if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
			print "ERROR.";
		}

	//if(!isset($_SESSION['userid']))
	$id=$_SESSION['registeredUserId'];
	
	$sourcePath1 = $_FILES['offerLetter']['tmp_name'];    
	$temp1 = explode(".", $_FILES["offerLetter"]["name"]);
	$newPath1 =  'offerLetter' . $id . '.' . end($temp1);
	addOfferLetter($newPath1,$id);
	$targetPath1 = "../offerLetter/".$newPath1;

	$sourcePath2 = $_FILES['jobDescription']['tmp_name'];    
	$temp2 = explode(".", $_FILES["jobDescription"]["name"]);
	$newPath2 =  'jobDescription' . $id . '.' . end($temp2);
	addJobDescription($newPath2,$id);
	$targetPath2 = "../jobDescription/".$newPath2;


	if(move_uploaded_file($sourcePath1,$targetPath1) && move_uploaded_file($sourcePath2,$targetPath2) ){
		print "upload";
	}
	else
	{
		print "fail";
	}

	
	
	
?>