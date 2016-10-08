<?php /* @var $this Controller */ ?>
<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>

<!-- Meta Tags -->
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1.0"/>
<meta http-equiv="content-type" content="text/html; charset=UTF-8"/>
<meta name="description" content="CharityFund - Charity & Crowdfunding HTML Template" />
<meta name="keywords" content="building,business,construction,cleaning,transport,workshop" />
<meta name="author" content="ThemeMascot" />

<!-- Page Title -->
<title><?php echo CHtml::encode($this->pageTitle); ?></title>

<!-- Favicon and Touch Icons -->
<link href="images/favicon.png" rel="shortcut icon" type="image/png">
<link href="images/apple-touch-icon.png" rel="apple-touch-icon">
<link href="images/apple-touch-icon-72x72.png" rel="apple-touch-icon" sizes="72x72">
<link href="images/apple-touch-icon-114x114.png" rel="apple-touch-icon" sizes="114x114">
<link href="images/apple-touch-icon-144x144.png" rel="apple-touch-icon" sizes="144x144">

<!-- Stylesheet -->
<!-- CSS | Custom Margin Padding Collection -->
<link href="css/custom-bootstrap-margin-padding.css" rel="stylesheet" type="text/css">
<!-- CSS | Main style file -->
<link href="css/main-style.css" rel="stylesheet" type="text/css">

<link href="css/bootstrap.min.css" rel="stylesheet" type="text/css">
<link href="css/animate.css" rel="stylesheet" type="text/css">
<link href="css/css-plugin-collections.css" rel="stylesheet"/>
<link href="css/animate.min.css" rel="stylesheet">

    <link href="css/prettyPhoto.css" rel="stylesheet">
     <link href="css/responsive.css" rel="stylesheet">
     <script src="js/jquery-2.1.4.min.js"></script> 

<link href="js/jquery-ui.css" rel="stylesheet">
<script src="js/jquery-ui.js"></script> 


   
<!-- CSS | menuzord megamenu -->
<link href="css/menuzord-skins/menuzord-border-top.css" rel="stylesheet"/>

<!-- Revolution Slider -->
<link  href="js/revolution-slider/css/settings.css" rel="stylesheet" type="text/css"/>
<link  href="js/revolution-slider/css/layers.css" rel="stylesheet" type="text/css"/>
<link  href="js/revolution-slider/css/navigation.css" rel="stylesheet" type="text/css"/>

<!-- CSS | Custom Margin Padding Collection -->
<link href="css/custom-bootstrap-margin-padding.css" rel="stylesheet" type="text/css">
<!-- CSS | Main style file -->
<link href="css/main-style.css" rel="stylesheet" type="text/css">
<!-- CSS | Responsive media queries -->
<link href="css/responsive.css" rel="stylesheet" type="text/css">



<!-- CSS | Style css. This is the file where you can place your own custom css code. Just uncomment it and use it. -->
<!-- <link href="css/style.css" rel="stylesheet" type="text/css"> -->

<!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
<!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
  <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
<![endif]-->
<style>
body{width:610;}
.demo-table {width: 100%;border-spacing: initial;margin: 20px 0px;word-break: break-word;table-layout: auto;line-height:1.8em;color:#333;}
.demo-table th {background: #999;padding: 5px;text-align: left;color:#FFF;}
.demo-table td {border-bottom: #f0f0f0 1px solid;background-color: #ffffff;padding: 5px;}
.demo-table td div.feed_title{text-decoration: none;color:#00d4ff;font-weight:bold;}
.demo-table ul{margin:0;padding:0;}
.demo-table li{cursor:pointer;list-style-type: none;display: inline-block;color: #F0F0F0;text-shadow: 0 0 1px #666666;font-size:20px;}
.demo-table .highlight, .demo-table .selected {color:#F4B30A;text-shadow: 0 0 1px #F48F0A;}
</style>

</head>
<body class="">
<div id="wrapper"> 
  <!-- preloader -->
  <!--<div id="preloader">
    <div id="spinner">
      <div class="cssload-container">
        <ul class="cssload-flex-container">
          <li>
            <span class="cssload-loading cssload-one"></span>
            <span class="cssload-loading cssload-two"></span>
            <span class="cssload-loading-center"></span>
          </li>
        </ul>
      </div>
    </div>
  </div>-->
  
  <!-- Header -->
  <header class="header">
    <div class="header-top bg-orange sm-text-center">
      <div class="container">
        <div class="row">
          <div class="col-md-9">
            <nav>
              <ul class="list-inline sm-text-center text-left mt-5">
               <li>
                  <a class="text-white" href="http://localhost/etaqreeb/index.php?r=admin">Admin</a>
                </li>
 <li class="text-white">|</li>

                <li>
                  <a class="text-white" href="#">FAQ</a>
                </li>
                <li class="text-white">|</li>
                
                <li>
                  <a class="text-white" href="#">Support</a>
                </li>
              </ul>
            </nav>
          </div>
          <div class="col-md-3">
            <ul class="social-icons small flat m-0 mt-sm-15 sm-text-center text-right">
              <li><a href="#"><i class="fa fa-facebook text-white"></i></a></li>
              <li><a href="#"><i class="fa fa-twitter text-white"></i></a></li>
              <li><a href="#"><i class="fa fa-google-plus text-white"></i></a></li>
              <li><a href="#"><i class="fa fa-instagram text-white"></i></a></li>
              <li><a href="#"><i class="fa fa-linkedin text-white"></i></a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>



    <div class="header-middle sm-text-center">
      <div class="container pt-15 pb-15">
        <div class="row">

          <div class="col-md-3 pt-10">
            <a class="header-logo" href="javascript:void(0)"><img width="200" height="100" alt="" src="images/logo.png"></a>
          </div>

          <div class="col-md-3">
          </div>
          <div class="col-md-3">
            <div class="mt-15 mt-sm-30 text-right sm-text-center">
              <div class="font-20 text-black text-uppercase mb-5 font-weight-600"><i class="fa fa-phone-square text-orange font-24"></i> +(92) 3244563233 </div>
              <a class="font-12 text-gray" href="#">Call us for more details!</a>
            </div>
          </div>
          <div class="col-md-3">
            <div class="mt-15 mt-sm-30 text-right sm-text-center">
              <div class="font-20 text-black text-uppercase mb-5 font-weight-600"><i class="fa fa-envelope text-orange font-24"></i> Mail us today</div>
              <a class="font-12 text-gray" href="#"> eTaqreeb@gmail.com</a>
            </div>
          </div>
        </div>
      </div>
    </div>
    
	<!--<div id="mainmenu">
		 <?php// $this->widget('zii.widgets.CMenu',array(
			// 'items'=>array(
				// array('label'=>'Home', 'url'=>array('/site/index')),
				// array('label'=>'About', 'url'=>array('/site/page', 'view'=>'about')),
				// array('label'=>'Contact', 'url'=>array('/site/contact')),
				// array('label'=>'Login', 'url'=>array('/site/login'), 'visible'=>Yii::app()->user->isGuest),
				// array('label'=>'Logout ('.Yii::app()->user->name.')', 'url'=>array('/site/logout'), 'visible'=>!Yii::app()->user->isGuest)
			// ),
		// )); ?>-->
	
    <div class="header-nav">
      <div class="header-nav-wrapper navbar-scrolltofixed" data-bg-color="#f5f5f5">
        <div class="container">
          <nav id="menuzord" class="menuzord orange" data-bg-color="#f5f5f5">
            

		<ul class="menuzord-menu">
      
              <li><a href="index.php">Home</a>
              <li><a href="index.php?r=site/about">About</a></li>
              <li><a href="index.php?r=site/vendor">Vendors</a></li>
              <li><a href="index.php?r=site/vendorServices">Services</a></li>
              <li><a href="index.php?r=site/gallery">Gallery</a></li>
              <li><a href="index.php?r=site/contact">Contact</a></li>

<?php
              if(isset($_SESSION["current_event"]))
              {
                echo "<li  class=\"pull-right hidden-sm hidden-xs menuzord-menu\"> Selected Event <a href=index.php?r=event/view&id=".$_SESSION["current_eventid"].">". $_SESSION["current_event"]."</a></li>";
              }
              
                ?>

            </ul>



            <ul class="pull-right hidden-sm hidden-xs menuzord-menu">
            <?php 
            //$session = Yii::$app->'session';
              
             if(isset($_SESSION["login_user"]))
             {
              echo "<li><a id=\"dropdown\" class=\"btn btn-colored btn-orange mt-0 p-20\" style=\"height:70px\"><i class=\"fa fa-user\"></i>Welcome " . $_SESSION['login_user'] ." </a>
              <ul class=\"dropdown\">";
                if(!strcmp($_SESSION['user-type'],"vendor"))
                {
                    echo "<li><a href=\"index.php?r=vendorServices/addService\"><i class=\"fa fa-edit\"></i>&nbspAdd Service</a></li>
                    <li><a id=\"manageServices\" href=\"http://localhost/etaqreeb/index.php?r=vendorservices/manageServices\"><i class=\"fa fa-th\"></i>&nbspManage Services</a></li>
                    <li><a id=\"viewCustomerRequests\" href=\"http://localhost/etaqreeb/index.php?r=eventservices/viewCustomerRequests\"><i class=\"fa fa-list\"></i>&nbspView Customer Requests</a></li>
                    <li><a id=\"updateVendor\" href=\"index.php?r=vendor/update&id=". $_SESSION['user-id'] ."\"><i class=\"fa fa-fw fa-gear\"></i>&nbspUpdate Profile</a></li>
          <li><a id=\"logoutVendor\" href=\"index.php?r=vendor/logout\"><i class=\"fa fa-fw fa-power-off\"></i>&nbspLogout</a></li>
                  
                </ul>";
                }
                else
                {

                  echo "<li><a id=\"createEvent\" href=\"http://localhost/etaqreeb/index.php?r=event/create\"><i class=\"fa fa-edit\"></i>&nbspCreate Event</a></li>
                  <li><a id=\"viewMyEvents\" href=\"http://localhost/etaqreeb/index.php?r=event/viewmyevents\"><i class=\"fa fa-list\"></i>&nbspManage My Events</a></li>
                  <li><a id=\"updateCustomer\" href=\"index.php?r=customer/update&id=". $_SESSION['user-id'] ."\"><i class=\"fa fa-fw fa-gear\"></i>&nbspUpdate Profile</a></li>
                  <li><a id=\"logoutCustomer\" href=\"index.php?r=customer/logout\"><i class=\"fa fa-fw fa-power-off\"></i>&nbspLogout</a></li>
                  
                  </ul></li></li>";
             }  

           }
             else
             {
                
            ?>
              <li><a class="btn btn-colored btn-orange mt-0  mt-0 p-20\" style="height:70px" data-toggle="modal" href="#modal-donate-now" onclick="clickLogin()">Login | Signup</a>
              
              <?php }?>
            </ul>
	
			
            


          </nav>
        </div>
      </div>
    </div>
  </header>

	<?php echo $content; ?>


	<!-- Footer -->
  <footer class="footer pb-0" data-bg-img="images/footer-bg.png" data-bg-color="#25272e">
    <div class="container pb-30">
      <div class="row">
        <div class="col-sm-6 col-md-3">
          <div class="footer-widget"> <img class="mt-0" alt="" src="images/logo.png">
            <p class="font-12 mt-20">eTaqreeb is an online web-based system for users to organize different kind of events and providing a facility<br> to plan their events according to their budget.</p>
            <a href="#" class="text-gray font-12"><i class="fa fa-angle-double-right text-orange"></i> Read more</a>
            <ul class="social-icons small square list-inline mt-10">
              <li><a href="#" data-bg-color="#3A5795"><i class="fa fa-facebook text-white"></i></a></li>
              <li><a href="#" data-bg-color="#55ACEE"><i class="fa fa-twitter text-white"></i></a></li>
              <li><a href="#" data-bg-color="#05A7E3"><i class="fa fa-skype text-white"></i></a></li>
              <li><a href="#" data-bg-color="#A11312"><i class="fa fa-google-plus text-white"></i></a></li>
              <li><a href="#" data-bg-color="#C22E2A"><i class="fa fa-youtube text-white"></i></a></li>
            </ul>
          </div>
        </div>
        <div class="col-sm-6 col-md-3">
          <div class="footer-widget">
            <h5 class="widget-title text-white">Pages<span class="line-bottom"></span></h5>
            <nav>
              <ul class="list angle-double-right">
                <li><a href="#">Home</a></li>
                <li><a href="#">About</a></li>
                <li><a href="#">Vendors</a></li>
                <li><a href="#">Gallery</a></li>
                <li><a href="#">Contact</a></li>
              </ul>
            </nav>
          </div>
        </div>
        <div class="col-sm-6 col-md-3">
          <div class="footer-widget">
            <h5 class="widget-title text-white pb-10">Quick Links<span class="line-bottom"></span></h5>
            <nav>
              <ul class="list angle-double-right">
                <li><a href="#">Privacy Policy</a></li>
                <li><a href="#">Disclaimer</a></li>
                <li><a href="#">Terms of Use</a></li>
                <li><a href="#">Copyright Notice</a></li>
                <li><a href="#">Media Center</a></li>
              </ul>
            </nav>
          </div>
        </div>
        <div class="col-sm-6 col-md-3">
          <div class="footer-widget">
            <h5 class="widget-title text-white">Quick Contact<span class="line-bottom"></span></h5>
            <ul>
              <li><a href="#">+(92) 3244563233</a></li>
              <li><a href="#">contact@eTaqreeb.com</a></li>
              <li><a class="lineheight-20" href="#">Tricon Corporate Centre, Jail Road, Lahore</a></li>
            </ul>
            <p class="text-white">Subscribe Our Newsletter</p>
            <form id="footer-mailchimp-subscription-form" class="newsletter-form">
              <div class="input-group">
                <input type="email" class="form-control" value="" name="EMAIL" placeholder="Your Email"  class="form-control input-lg" data-height="43px" id="mce-EMAIL">
                <span class="input-group-btn">
                    <button class="btn btn-colored btn-orange btn-lg m-0" type="submit"><i class="fa fa-paper-plane-o text-white"></i></button>
                </span>
              </div>
            </form>
          </div>
        </div>
      </div>
    </div>
    <div class="container-fluid p-20" data-bg-color="#fe9322">
      <div class="row text-center">
        <div class="col-md-12">
          <p class="font-11 text-white m-0">Copyright &copy;2015 eTaqreeb. All Rights Reserved</p>
        </div>
      </div>
    </div>
  </footer>
  <a class="scrollToTop" href="#"><i class="fa fa-angle-up"></i></a>
</div>
<!-- end wrapper --> 

<!-- Modal: Login -->
<div class="modal fade" id="modal-donate-now" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header bg-orange pl-40 pt-20 pb-20">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title text-white" id="myModalLabel">Login</h4>
      </div>
      <div class="modal-body pl-40 pr-40">
        <form id="donation-form" class="donation-form" method="POST">
          <div class="row">
          
            <div id="invalid_Err_Msg" style="text-align:center">
                    Incorrect Username or Password. Please try again.
                </div><br />
              
            <div class="col-sm-6">
              <div class="form-group">
                <label><strong>Username</strong></label>
                <input type="text" placeholder="Username" id="loginUsername" name="name" required="" class="form-control">
                <span id="loginUsername_err" style="color:red;"></span>
              </div>
            </div>
            <div class="col-sm-6">
              <div class="form-group">
                <label><strong>Password</strong></label>
                <input type="password" placeholder="Password" id="loginPassword" name="password" class="form-control" required="">
                <span id="loginPassword_err" style="color:red;"></span>
              </div>
            </div>
            
            <div class="col-sm-12">
              <div class="form-group">
                <label><strong>Login as</strong></label>
                <select id = "select-val" class="form-control" name="role">
				   <!-- <option>--Select--</option> -->
                  <option value="customer" id="customer">Customer</option>
                  <option value="vendor" id="vendor">Vendor</option>
                </select>
              </div>
            </div>
			
			</div> <!-- -->
          
		  <div class="form-group" style="display:inline">
		  
           <label style="align:left"><br>New to eTaqreeb? <strong><a data-toggle="modal" href="#modal-signup-role" id="signup">SignUp here!</a></strong></label>
            <button style="float:right" data-loading-text="Please wait..." class="btn btn-colored btn-rounded btn-orange pl-30 pr-30" type="button" onclick="LoginAJAX()" id="go-login" >Login</button>
		  
		 </div>
        
		
		</form>
      </div>
    </div>
  </div>
</div>



<!--SignUp Role-->
<div class="modal fade" id="modal-signup-role" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" >
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header bg-orange pl-40 pt-20 pb-20">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title text-white" id="myModalLabel">Select Your Role</h4>
      </div>
      <div class="modal-body pl-40 pr-40">
        <form id="donation-form" class="donation-form">
          <div  class="form-group text-center">
           
            <div >
			  <a class="btn btn-colored btn-orange pl-30 pr-30" href="?r=customer/signup" style="color:#fff" id="customer">Customer</a>
			  </div>
			  
			  <div >
			  <a class="btn btn-colored btn-orange pl-30 pr-30" href="?r=vendor/signup" style="color:#fff" id="vendor">Vendor</a>
			  </div>
			
			</div> <!-- -->
         
        
		
		</form>
      </div>
    </div>
  </div>
</div>





<!-- jQuery scripts -->


<script src="js/bootstrap.min.js"></script> 
<!-- Revolution Slider -->
<script src="js/revolution-slider/js/jquery.themepunch.tools.min.js"></script>
<script src="js/revolution-slider/js/jquery.themepunch.revolution.min.js"></script>
<script src="js/custom-rev-slider.js"></script> 
<!-- JS | google map -->
<script src="http://maps.google.com/maps/api/js?sensor=false"></script> 
<!-- JS | Necessary jQuery Collection for this theme --> 
<script src="js/jquery-plugin-collection.js"></script> 
<!-- JS | Custom script for all pages --> 
<script src="js/custom.js"></script>

<script src="js/login.js"></script>






<!-- SLIDER REVOLUTION 5.0 EXTENSIONS  
      (Load Extensions only on Local File Systems ! 
       The following part can be removed on Server for On Demand Loading) -->
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.actions.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.carousel.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.kenburn.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.layeranimation.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.migration.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.navigation.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.parallax.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.slideanims.min.js"></script>
<script type="text/javascript" src="js/revolution-slider/js/extensions/revolution.extension.video.min.js"></script>
</body>
</html>

<style>

#invalid_Err_Msg{
    background-color: #bc0b0b;
     display:none; 
     color:white; 
     padding: 10px;
}

</style>

<script>
$(document).ready(function(){
  $("#signup").click(function() {
  $('#modal-donate-now').modal('hide');
  })
});

</script>

