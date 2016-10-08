<?php

	$db = mysqli_connect('mysql.softenica.com','asad','asad@1365');

	if(!$db){
		return "ERROR! Connection could not be made.";
		}
	$dbname = 'sharkimp';
	$dbtest = mysqli_select_db($db,$dbname);
	if(!$dbtest){
		return "ERROR! Database could not be opened.";
		}
		
	//**************************************************
	//	Various Functions 
	//**************************************************


	function validate_superAdmin($username, $password){
		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		$query = "select id from super_admin_$$ where username = '$username' AND password = '$password'";
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

	function validate_student($username, $password){
		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		$query = "select id from userlogin where username = '$username' AND password = '$password'";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['id'];

	}


	function getPendingRequests(){
		global $db;
		$query = "select * from requests where status = 'Pending' ";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function getApprovedRequests(){
		global $db;
		$query = "select * from requests where status = 'Approved' ";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function getDeniedRequests(){
		global $db;
		$query = "select * from requests where status = 'Denied' ";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function getStudentName($id){
		global $db;
		$query = "select username from userlogin where id = '$id' ";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['username'];

	}


	function getQueryMessage($id){
		global $db;
		$query = "select message from query where id = '$id' ";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['message'];

	}

	function getEmail($username){
		global $db;
		$query = "select email from userlogin where username = '$username' ";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			$value = mysqli_fetch_array($result);
			return $value['email'];
		}

		$query = "select email from admin where username = '$username' ";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			$value = mysqli_fetch_array($result);
			return $value['email'];
		}

		$query = "select email from super_admin_$$ where username = '$username' ";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			$value = mysqli_fetch_array($result);
			return $value['email'];
		}
	
		return null;

	}

	function getStudentRequest($id){
		global $db;
		$query = "select * from requests where studentid = '$id' ";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value;

	}


	function getStudent($id){
		global $db;
		$query = "select * from userlogin where id = '$id' ";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value;

	}

	function getStudentInfo($id){
		global $db;
		$query = "select * from student_info where studentid = '$id' ";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value;

	}


	function approveRequest($id){
		global $db;
		$query = "update requests set status='Approved' where id = '$id'";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function updateStudentInfo($id, $agencyName, $agencyAddress, $agencyWebsite, $supervisorName, $supervisorphoneNo, $supervisorEmail, $term){
		global $db;
		$query = "update student_info set agency='$agencyName', agency_address='$agencyAddress', agency_website='$agencyWebsite', supervisor_name='$supervisorName', supervisor_phoneno='$supervisorphoneNo', supervisor_email='$supervisorEmail', term='$term'  where studentid = $id";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function updateRequest($id){
		global $db;
		$query = "update requests set status='Pending' where studentid = $id";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function getRequestEmail($id){
		global $db;
		$query = "select email from userlogin where id = (select studentid from requests where id='$id')";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['email'];
	}

	function addReply($id){
		global $db;
		$query = "update query set reply='yes' where id = '$id'";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function denyRequest($id,$reason){
		global $db;
		$query = "update requests set status='Denied', reason='$reason' where id = '$id'";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function addReasonAdmin($id,$reason){
		global $db;
		$query = "insert into other_reason(reason, admin_id) values('$reason','$id')";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function addReasonSuperAdmin($id,$reason){
		global $db;
		$query = "insert into other_reason(reason, super_admin_id) values('$reason','$id')";
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
		$query = "select * from super_admin_$$ where username = '$username'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}

	function check_student_username($username){
		global $db;
		
		$username = mysqli_real_escape_string($db,$username);
		$query = "select * from userlogin where username = '$username'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;

	}

	function validate_oldpassword($oldpassword){
		global $db;
		//to avoid sql injection
		$oldpassword = mysqli_real_escape_string($db,$oldpassword);
		$oldpassword = md5($oldpassword);
		session_start();
		$id = $_SESSION['userid'];
		if( isset($_SESSION['user_status']) &&  $_SESSION['user_status'] == "admin" ) 
		{
			if(isset($_SESSION['admin_type']))
			{
				$query = "select * from super_admin_$$ where id = '$id' AND password='$oldpassword'";
			}
			else
			{
				$query = "select * from admin where id = '$id' AND password='$oldpassword'";
			}

		}
		else
		{
			$query = "select * from userlogin where id = '$id' AND password='$oldpassword'";
		}
		
		$result = mysqli_query($db,$query);

		if(mysqli_num_rows($result) > 0)
		{
				return true;
		}
		
		return false;

	}

	function validate_oldEmail($oldEmail){
		global $db;
		
		session_start();
		$id = $_SESSION['userid'];
		if( isset($_SESSION['user_status']) &&  $_SESSION['user_status'] == "admin" ) 
		{
			if(isset($_SESSION['admin_type']))
			{
				$query = "select * from super_admin_$$ where id = '$id' AND email='$oldEmail'";
			}
			else
			{
				$query = "select * from admin where id = '$id' AND email='$oldEmail'";
			}

		}
		
		$result = mysqli_query($db,$query);

		if(mysqli_num_rows($result) > 0)
		{
				return true;
		}
		
		return false;

	}


	function validateAndUpdateCode($code, $newpassword){
		global $db;
		$newpassword = mysqli_real_escape_string($db,$newpassword);
		$newpassword = md5($newpassword);
		$query = "select * from userlogin where changecode = '$code' ";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			$query = "update userlogin set password='$newpassword' where changecode = '$code'";
			mysqli_query($db,$query);
			return true;
		}

		$query = "select * from admin where changecode = '$code' ";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			$query = "update admin set password='$newpassword' where changecode = '$code'";
			mysqli_query($db,$query);
			return true;
		}

		$query = "select * from super_admin_$$ where changecode = '$code' ";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			$query = "update super_admin_$$ set password='$newpassword' where changecode = '$code'";
			mysqli_query($db,$query);
			return true;
		}

		return false;

		
	}

	function addOfferLetter($path, $id){
		global $db;

		$query="update userlogin set offer_extension='$path' where id = $id";
		$result=mysqli_query($db,$query);

		return $result;

	}

	function addJobDescription($path, $id){
		global $db;

		$query="update userlogin set job_extension='$path' where id = $id";
		$result=mysqli_query($db,$query);

		return $result;

	}

	function generateCodeAdmin($username, $code){
		global $db;

		$query="update admin set changecode='$code' where username = '$username'";
		$result=mysqli_query($db,$query);

		return $result;

	}

	function generateCodeSuper($username, $code){
		global $db;

		$query="update super_admin_$$ set changecode='$code' where username = '$username'";
		$result=mysqli_query($db,$query);

		return $result;

	}

	function generateCodeStudent($username, $code){
		global $db;

		$query="update userlogin set changecode='$code' where username = '$username'";
		$result=mysqli_query($db,$query);

		return $result;
	}



	function update_password($newpassword){

		global $db;
		//to avoid sql injection
		$newpassword = mysqli_real_escape_string($db,$newpassword);
		$newpassword = md5($newpassword);
		$id = $_SESSION['userid'];
		if( isset($_SESSION['user_status']) &&  $_SESSION['user_status'] == "admin" ) 
		{
			if(isset($_SESSION['admin_type']))
			{
				$query = "update super_admin_$$ set password='$newpassword' where id = '$id'";
			}
			else
			{
				$query = "update admin set password='$newpassword' where id = '$id'";
			}
		}
		else
		{
			$query = "update userlogin set password='$newpassword' where id = '$id'";
		}
		
		$result = mysqli_query($db,$query);
		

		return $result;

	}


	function update_email($newEmail){

		global $db;
		
		$id = $_SESSION['userid'];
		if( isset($_SESSION['user_status']) &&  $_SESSION['user_status'] == "admin" ) 
		{
			if(isset($_SESSION['admin_type']))
			{
				$query = "update super_admin_$$ set email='$newEmail' where id = '$id'";
			}
			else
			{
				$query = "update admin set email='$newEmail' where id = '$id'";
			}
		}
		
		$result = mysqli_query($db,$query);
		

		return $result;

	}


	function addAdmin($username, $password, $email){

		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		
		$query = "insert into admin(username, password, email, login_status) values('$username','$password','$email',0)";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function addStudentInfo($id, $name, $nsuid, $phoneno, $major, $agencyName, $agencyAddress, $agencyWebsite, $supervisorName, $supervisorphoneNo, $supervisorEmail, $term){
		global $db;
		$query = "insert into student_info(name, nsuid, phoneno, major, agency, agency_address, agency_website, supervisor_name, supervisor_phoneno, supervisor_email, term, studentid) values('$name', '$nsuid', '$phoneno', '$major', '$agencyName', '$agencyAddress', '$agencyWebsite', '$supervisorName', '$supervisorphoneNo', '$supervisorEmail', '$term', $id)";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function addUser($username, $password, $email){

		global $db;
		//to avoid sql injection
		$username = mysqli_real_escape_string($db,$username);
		$password = mysqli_real_escape_string($db,$password);
		$password = md5($password);
		
		$query = "insert into userlogin(username, password, email, login_status) values('$username','$password','$email',0)";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function addQuery($name, $nsuid, $email, $message){

		global $db;
		$query = "insert into query(name, nsuid, email, message, reply) values('$name','$nsuid','$email','$message','no')";
		$result = mysqli_query($db,$query);
		
		return $result;

	}

	function addRequest($id){

		global $db;
		$query = "insert into requests(status, studentid) values('Pending', $id)";
		$result = mysqli_query($db,$query);
		
		return $result;

	}
	
	function removeAdmin($id){

		global $db;
		//to avoid sql injection
		$id = mysqli_real_escape_string($db,$id);

		$query1 = "delete from other_reason where admin_id=$id";
		$result = mysqli_query($db,$query1);

		$query = "delete from admin where id=$id";
		$result = mysqli_query($db,$query);

		return $result;

	}

	function getUserId($username){
		global $db;
		$username = mysqli_real_escape_string($db,$username);
		$query = "select id from userlogin where username = '$username'";
		$result = mysqli_query($db,$query);
		$value = mysqli_fetch_array($result);

		return $value['id'];
	}


	function getAllAdmins(){
		global $db;
		$query = "select * from admin";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function getAllSuperAdmins(){
		global $db;
		$query = "select * from super_admin_$$";
		$result = mysqli_query($db,$query);
		return $result;
	}


	function getAllQueries(){
		global $db;
		$query = "select * from query where reply='no'";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function getAdminOtherReasons($id){
		global $db;
		$query = "select * from other_reason where admin_id='$id'";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function getSuperAdminOtherReasons($id){
		global $db;
		$query = "select * from other_reason where super_admin_id='$id'";
		$result = mysqli_query($db,$query);
		return $result;
	}

	function checkAdminOtherReasons($id, $reason){
		global $db;
		$query = "select * from other_reason where admin_id='$id' and reason='$reason'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;
	}

	function checkSuperAdminOtherReasons($id, $reason){
		global $db;
		$query = "select * from other_reason where super_admin_id='$id' and reason='$reason'";
		$result = mysqli_query($db,$query);
		if(mysqli_num_rows($result) > 0){
			return false;
		}
		return true;
	}


	function set_login_status_and_time_superAdmin($username, $login_time){
		global $db;
		$query = "update super_admin_$$ set login_status = TRUE, last_login_time = '$login_time' where username = '$username'";
		$result = mysqli_query($db,$query);
		if($result){
			return true;
		}
		return false;
	}

	function set_login_status_and_time_admin($username, $login_time){
		global $db;
		$query = "update admin set login_status = TRUE, last_login_time = '$login_time' where username = '$username'";
		$result = mysqli_query($db,$query);
		if($result){
			return true;
		}
		return false;
	}

	function set_login_status_and_time_student($username, $login_time){
		global $db;
		$query = "update userlogin set login_status = TRUE, last_login_time = '$login_time' where username = '$username'";
		$result = mysqli_query($db,$query);
		if($result){
			return true;
		}
		return false;
	}

	function unset_login_status_and_time_superAdmin($username, $logout_time){
		global $db;
		$query = "update super_admin_$$ set login_status = FALSE, last_logout_time = '$logout_time' where username = '$username'";
		$result = mysqli_query($db,$query);
		if($result){
			return true;
		}
		return false;
	}

	function unset_login_status_and_time_admin($username, $logout_time){
		global $db;
		$query = "update admin set login_status = FALSE, last_logout_time = '$logout_time' where username = '$username'";
		$result = mysqli_query($db,$query);
		if($result){
			return true;
		}
		return false;
	}

	function unset_login_status_and_time_student($username, $logout_time){
		global $db;
		$query = "update userlogin set login_status = FALSE, last_logout_time = '$logout_time' where username = '$username'";
		$result = mysqli_query($db,$query);
		if($result){
			return true;
		}
		return false;
	}
?>