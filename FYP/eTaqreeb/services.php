<?php

namespace eTaqreeb;

/**
 * Created by Google on 5/29/2016.
 */
class services {
    private $objectId;
	private $typ;
	private $pric;
	private $nam;
	private $vObjectId;

    public function getvObjectId() {
        return $this -> vObjectId;
    }

    public function setvObjectId($vObjectId) {
        $this -> vObjectId = $vObjectId;
    }

    public function getObjectId() {

        return $this -> objectId;
    }

    public function setObjectId($objectId) {
        $this -> objectId = $objectId;
    }

    public function getTyp() {
        return $this -> typ;
    }

    public function setTyp($typ) {
        $this -> typ = $typ;
    }

    public function getPric() {
        return $this -> pric;
    }

    public function setPric($pric) {
        $this -> pric = $pric;
    }

    public function getNam() {
        return $this -> nam;
    }

    public function setNam($nam) {
        $this -> nam = $nam;
    }
}
?>
