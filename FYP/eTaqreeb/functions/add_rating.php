<?php

error_reporting(0);

//if(!empty($_POST["rating"]) && !empty($_POST["id"]) && !empty($_POST["noRate"])&& !empty($_POST["curr"])) 

require_once("dbcontroller.php");
$db_handle = new DBController();
$putIt = $_POST["rating"] + $_POST["curr"];
$query ="UPDATE rating SET rating=" . $putIt . ",noOfRatings=" . $_POST['noRate'] . " WHERE id=" . $_POST["id"] . "";
$result = $db_handle->updateQuery($query);

header('../protected/views/site/vendor.php');

print 'ok';

//
?>