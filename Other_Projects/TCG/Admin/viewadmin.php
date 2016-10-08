<?php

session_start();

if( isset($_SESSION['admin_type']) && isset($_SESSION['userid']) ) :?>


<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
      <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>View  Admin List</title>
	<!-- BOOTSTRAP STYLES-->
    <link href="assets/css/bootstrap.css" rel="stylesheet" />
     <!-- FONTAWESOME STYLES-->
    <link href="assets/css/font-awesome.css" rel="stylesheet" />
        <!-- CUSTOM STYLES-->
    <link href="assets/css/custom.css" rel="stylesheet" />
     <!-- GOOGLE FONTS-->
   <link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css' />
   <script src='../js/removeAdmin.js'></script>
</head>
<body>
     
           
          
    <div id="wrapper">
         <div class="navbar navbar-inverse navbar-fixed-top">
            <div class="adjust-nav">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".sidebar-collapse">
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="#">
                        <img src="../images/logo-1.jpg" />

                    </a>
                    
                </div>
              
               <span class="logout-spn" >
                              <span class="logout-spn" >
                  <a href="../functions/logout.php" style="color:#fff;">LOGOUT</a>
                </span>

                  <a href="#" style="color:#fff;">
                                        <i class="fa fa-envelope"></i>
                                        Info@tcgiit.com </a>

                </span>
                <span class="logout-spn" >
                  <a href="#" style="color:#fff;">  
<i class="fa fa-phone"></i>
                                    347-787-6030</a>
                </span>
            </div>
        </div>
        <!-- /. NAV TOP  -->
        <nav class="navbar-default navbar-side" role="navigation">
            <div class="sidebar-collapse">
                <ul class="nav" id="main-menu">
                 

  <li >
                   <a href="adminpanel.php" ><i class="fa fa-desktop "></i>Dashboard </a>

                    </li>
                   

                    <li>
                        <a href="viewapplicantlist.php"><i class="fa fa-table "></i>View Applicants </a>
                    </li>

<?php if(isset($_SESSION['admin_type'])){ ?>

                    <li class="active-link">
                        <a href="viewadmin.php"><i class="fa fa-table "></i>View Admin List</a>
                    </li>
                    <li>
                     <a href="addadmin.php"><i class="fa fa-edit "></i>Add New Admin </a>
                    </li>

                    <?php } ?>
                  
                    
                </ul>
                            </div>

        </nav>
        <!-- /. NAV SIDE  -->
        <div id="page-wrapper" >
            <div id="page-inner">
                <div class="row">
                    <div class="col-lg-12">
                     <h2>View Admin List</h2>   
                    </div>
                </div>              
                 <!-- /. ROW  -->
                  <hr />
                <div class="row">
                    <div class="col-lg-12 ">
                        
                       
                    </div>
                    </div>
                  <!-- /. ROW  --> 
                            <div class="row text-center pad-top" id="admin-list">
                  
              </div>
                 <!-- /. ROW  -->   
				  
                  <!-- /. ROW  --> 
    </div>
             <!-- /. PAGE INNER  -->
            </div>
         <!-- /. PAGE WRAPPER  -->
        </div>
    <div class="footer">
      
    
            <div class="row">
                <div class="col-lg-12" >
                    <a style="color:#fff;" target="_blank">Copyright © Technical Consultants Group Inc.</a>
                </div>
            </div>
        </div>


     <!-- /. WRAPPER  -->
    <!-- SCRIPTS -AT THE BOTOM TO REDUCE THE LOAD TIME-->
    <!-- JQUERY SCRIPTS -->
    <script src="assets/js/jquery-1.10.2.js"></script>
      <!-- BOOTSTRAP SCRIPTS -->
    <script src="assets/js/bootstrap.min.js"></script>
      <!-- CUSTOM SCRIPTS -->
    <script src="assets/js/custom.js"></script>

    <script>
       $(document).ready(function(){
            $("#admin-list").load('adminList.php');
        });
    </script>
          
    
   
</body>
</html>

<?php else:
    
    header("Location: ../admin.php");
    die();
    
 endif; ?>