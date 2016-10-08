<?php

	$db = mysqli_connect('localhost','root','');

	if(!$db){
		return "ERROR! Connection could not be made.";
		}
	$dbname = 'etaqreeb';
	$dbtest = mysqli_select_db($db,$dbname);
	if(!$dbtest){
		return "ERROR! Database could not be opened.";
		}
		
	//**************************************************
	//	Various Functions 
	//**************************************************


	function check_customer_username($username){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from customer where username = '$username'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}
	
	function check_vendor_username($username){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from vendor where username = '$username'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}
	
	function check_admin_username($username){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from admin where username = '$username'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}
	
	
	function check_custUpdate_username($username, $id){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from customer where username = '$username' AND id!=$id";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}
	
	function check_vendUpdate_username($username, $id){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from vendor where username = '$username' AND id!=$id";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}
	
	function check_admUpdate_username($username, $id){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from admin where username = '$username' AND id!=$id";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}
	
	function check_book($amount, $id){
		global $db;
		
		$query = "select * from event where id=$id AND ($amount+current_budget) <= budget";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return true;
		}
		return false;

	}
	
	function getAllVendors(){
		global $db;
		$query = "select * from vendor";
		$result = mysqli_query($db,$query);
		return $result;
	}
	
	function getAllServices($query){
		global $db;
		$result = mysqli_query($db,$query);
		return $result;
	}
	
	function getVendorName($id){
		global $db;
		$query = "select * from vendor where id = $id";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['companyname'];
	}
	
	function getVendorAvailability($id){
		global $db;
		$query = "select * from vendor where id = $id";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['availability'];
	}
	
	
	function getAllVendorsBy($query,$searchby){
		global $db;
		
		$query = "select * from vendor where $searchby='$query'";
		$result = mysqli_query($db,$query);
		return $result;
	}
	
	function getAllVendorsByContact($query){
		global $db;
		$query = "select * from vendor where contact1='$query' OR contact2='$query'";
		$result = mysqli_query($db,$query);
		return $result;
	}
	
	