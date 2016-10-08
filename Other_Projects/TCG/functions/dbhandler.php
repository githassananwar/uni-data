<?php

	$db = mysqli_connect('MYSQL','tcgiit@yahoo.com','Ca1c!@1425');

	if(!$db){
		return "ERROR! Connection could not be made.";
		}
	$dbname = 'tcgiit';
	$dbtest = mysqli_select_db($db,$dbname);
	if(!$dbtest){
		return "ERROR! Database could not be opened.";
		}
		
	//**************************************************
	//	Various Functions 
	//**************************************************

	function addUser($jobid, $firstname, $lastname, $email, $phone){

		global $db;
		
		$query = "insert into user(job_id, first_name, last_name, email, phone) values('$jobid','$firstname','$lastname','$email', '$phone')";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function getUserId()
	{
		global $db;

		$query = "select max(id) from user";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['max(id)'];

	}

	function addResume($path, $id){
		global $db;

		$query="update user set resume='$path' where id = $id";
		$result=mysqli_query($db,$query);

		return $result;

	}

	function addCoverLetter($path, $id){
		global $db;

		$query="update user set cover_letter='$path' where id = $id";
		$result=mysqli_query($db,$query);

		return $result;

	}

	function addMessage($name, $email, $subject, $message){

		global $db;
		$query = "insert into contact(name, email, subject, message, reply) values('$name','$email','$subject','$message','no')";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function validate_superAdmin($username, $password){
		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		$query = "select id from super_admin where username = '$username' AND password = '$password'";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['id'];
	}

	function validate_admin($username, $password){
		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		$query = "select id from admin where username = '$username' AND password = '$password'";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['id'];
	}

	function getAllRequests(){
		global $db;
		$query = "select * from user ";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function getAllAdmins(){
		global $db;
		$query = "select * from admin ";
		$result = mysqli_query($db,$query);
		
		return $result;

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

	function check_superAdmin_username($username){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from super_admin where username = '$username'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}


	function addAdmin($username, $password){

		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		
		$query = "insert into admin(username, password) values('$username','$password')";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function removeAdmin($id){

		global $db;

		$query = "delete from admin where id=$id";
		$result = mysqli_query($db,$query);

		return $result;

	}


	function getAllSuperAdmins(){
		global $db;
		$query = "select * from super_admin";
		$result = mysqli_query($db,$query);
		return $result;
	}


?>