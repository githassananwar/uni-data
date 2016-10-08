<?php

session_start();

if(!isset($_SESSION['userid']) ):?>


<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
      <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Admin Login</title>
	<!-- BOOTSTRAP STYLES-->
    <link href="assets/css/bootstrap.css" rel="stylesheet" />
     <!-- FONTAWESOME STYLES-->
    <link href="assets/css/font-awesome.css" rel="stylesheet" />
        <!-- CUSTOM STYLES-->
    <link href="assets/css/custom.css" rel="stylesheet" />
     <!-- GOOGLE FONTS-->
    <link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css' />
    <script src='js/loginscript.js'></script>
</head>
<body>
     
           
          
    <div id="wrapper">
         <div class="navbar navbar-inverse navbar-fixed-top">
            <div class="adjust-nav">
                <div class="navbar-header">
                   
                    <a class="navbar-brand" href="#">
                        <img src="assets/img/logo.png" />

                    </a>
                    
                </div>
              
               <span class="logout-spn" >
                              
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
        
        <div id="page-wrapper2" >
            <div id="page-inner2">
                <div class="row col-xs-offset-3">
                    <div class="col-lg-12">
                     <h2>Admin Panel Login</h2>   
                    </div>
                </div>              
                 <!-- /. ROW  -->
                 
                  <!-- /. ROW  --> 
                            <div class="row text-center pad-top col-xs-offset-3">
                  <div class="col-lg-6 col-md-6 col-sm-6 col-xs-6">
                  <div id="invalid_Err_Msg" style="display:none; color:red" >
                    The username or password you entered is incorrect. Please try again.
                </div>
                 <div class="input-group">
  <span class="input-group-addon">@</span>
  <input type="text" id="email" class="form-control" placeholder="Email" />
</div>
<span id="email_err" style="color:red;"></span>
  <br />
                       <div class="input-group">
  <span class="input-group-addon">*</span>
  <input type="password" id="password" class="form-control" placeholder="Password" />
</div>
 <span id="password_err" style="color:red;"></span>
<br>

              <input type="button" onclick="login()" class="btn btn-primary"value="Login">     
                  </div>
              </div>
                     </div></div></div></div></div>
                 <!-- /. ROW  -->   
				  
                  <!-- /. ROW  --> 
    
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
    
   
</body>
</html>


<?php else:
    
    header("Location: Admin/adminpanel.php");
    die();
       


 endif; ?>