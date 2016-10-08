<?php

namespace eTaqreeb;

/**
 * Created by Google on 5/29/2016.
 */
class customerVariables {
    private $nam;
	private $userr;
	private $pas;
	private $maill;
	private $cont;
	private $objectId;



    public function getObjectId() {
        return $this -> objectId;
    }

    public function setObjectId( $objectId ) {
        $this -> objectId = $objectId;
    }

    public function getNam() {
        return $this -> nam;
    }

    public function setNam($nam) {
        $this -> nam = $nam;
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

    public function getMaill() {
        return $this -> maill;
    }

    public function setMaill($maill) {
        $this -> maill = $maill;
    }

    public function getCont() {
        return $this -> cont;
    }

    public function setCont($cont) {
        $this -> cont = $cont;
    }
}
?>