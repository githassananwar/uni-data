<?php

/**
 * UserIdentity represents the data needed to identity a user.
 * It contains the authentication method that checks if the provided
 * data can identity the user.
 */
class UserIdentity extends CUserIdentity
{
	/**
	 * Authenticates a user.
	 * The example implementation makes sure if the username and password
	 * are both 'demo'.
	 * In practical applications, this should be changed to authenticate
	 * against some persistent user identity storage (e.g. database).
	 * @return boolean whether authentication succeeds.
	 */
	public function authenticate()
	{

		$customers = Customer::model()->findAll();
		$vendors = Vendor::model()->findAll();

		$usersArray = array();
		if(is_array($customers) && is_array($vendors))
		{
			foreach ($customers as $key => $value) {
				// $data = $value->username. "=>" .$value->password;
				$data['username'] = $value->username;
				$data['password'] = $value->password;
				array_push($usersArray,$data);
			}
			foreach ($vendors as $key => $value) {
				//$data = $value->username. "=>" .$value->password;
				$data['username'] = $value->username;
				$data['password'] = $value->password;
				array_push($usersArray,$data);
			}
		} 

		print_r($usersArray);
		$users=$usersArray;


		if(!isset($users[$this->username]))
			$this->errorCode=self::ERROR_USERNAME_INVALID;
		elseif($users[$this->username]!==$this->password)
			$this->errorCode=self::ERROR_PASSWORD_INVALID;
		else
			$this->errorCode=self::ERROR_NONE;
		return !$this->errorCode;
	}
}