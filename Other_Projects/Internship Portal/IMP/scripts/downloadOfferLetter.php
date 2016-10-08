<?php
//***********************************************
//	For download of Offer Letter
//***********************************************

session_start();

if(isset($_SESSION['username']) && isset($_SESSION['login_status']) && isset($_SESSION['user_status']) && $_SESSION['user_status'] == "admin") { 

echo "Code to be replaced to download ".$_GET['id'].".pdf from offerLetter folder";


//Possible Code but not working ...

// connect and login to FTP server /////softenica.com/Nicky/IMP-3.2/jobDescription
// $ftp_server = "ftp.softenica.com";
// $ftp_conn = ftp_connect($ftp_server) or die("Could not connect to $ftp_server");
// $login = ftp_login($ftp_conn, "asad126", "XEJ-vT9E");

// $local_file = fopen('Desktop');
// $server_file = $_GET['id'].".pdf";

// // download server file
// if (ftp_get($ftp_conn, $local_file, $server_file, FTP_ASCII))
//   {
//   echo "Successfully written to $local_file.";
//   }
// else
//   {
//   echo "Error downloading $server_file.";
//   }

// // close connection
// ftp_close($ftp_conn);

} 

else
{
   header("Location: ../index.php");
   die();
}



?>