<?php

namespace eTaqreeb;

/**
 * Created by Google on 5/29/2016.
 */
class vendorVariables {
    protected $vName;
	protected $cName;
	protected $cAddress;
	protected $landline;
	protected $mobileNum;
	protected $emaill;
	protected $userr;
	protected $pas;
	protected $objectId;


    public function getObjectId() {
        return $this -> objectId;
    }

    public function setObjectId( $objectId ) {
        $this -> objectId = $objectId;
    }
    public function getcName() {
        return $this -> cName;
    }

    public function setcName($cName) {
        $this -> cName = $cName;
    }

    public function getvName() {
        return $this -> vName;
    }

    public function setvName($vName) {
        $this -> vName = $vName;
    }

    public function getcAddress() {
        return $this -> cAddress;
    }

    public function setcAddress($cAddress) {
        $this -> cAddress = $cAddress;
    }

    public function getLandline() {
        return $this -> landline;
    }

    public function setLandline($landline) {
        $this -> landline = $landline;
    }

    public function getMobileNum() {
        return $this -> mobileNum;
    }

    public function setMobileNum($mobileNum) {
        $this -> mobileNum = $mobileNum;
    }

    public function getEmaill() {
        return $this -> emaill;
    }

    public function setEmaill($emaill) {
        $this -> emaill = $emaill;
    }

    public function getUserr() {
        return $this -> userr;
    }

    public function setUserr($userr) {
        $this -> userr = $userr;
    }

    public function getPas() {
        return $this -> pas;
    }

    public function setPas($pas) {
        $this -> pas = $pas;
    }
}
?>