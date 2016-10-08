

<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Admin eTaqreeb</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <!-- Loading Bootstrap -->
    <link href="css/admin/bootstrap/css/bootstrap.css" rel="stylesheet">

    <!-- Loading Flat UI -->
    <link href="css/admin/flat-ui.css" rel="stylesheet">
    
    <link href="css/admin/style.css" rel="stylesheet">
     <link href="css/signin.css" rel="stylesheet" />
     <script src="js/ie-emulation-modes-warning.js"></script>

    
    
    <!-- Font Awesome -->
    

    <!-- HTML5 shim, for IE6-8 support of HTML5 elements. All other JS at the end of file. -->
    <!--[if lt IE 9]>
      <script src="js/html5shiv.js"></script>
      <script src="js/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>
  
  <?php if(isset($_SESSION["login_admin"]))
  {?>
  	<div class="menu" id = "menu">
		
  		<div class="main">
			  		  			
  			<h3><span class="fui-dashboard"></span> Dashboard</h3>
  			
  			<ul id="elements">
				<li><a href="index.php?r=admin/home" id="all">Home</a></li>
  				<li><a href="?r=admin/managecustomers" id="all">Manage Customers</a></li>
          <li><a href="?r=admin/managevendors" id="all">Manage Vendors</a></li>
           <li><a href="?r=admin/manageevents" id="all">Manage Events</a></li>
           <li><a href="?r=admin/managevendorservices" id="all">Manage Vendor Services</a></li>
				<li><a href="?r=admin/manageorders" id="all">Manage Orders</a></li>
  			</ul>
  			
			<a href="#" class="toggle"><span class="fui-gear"></span></a>
			
  			<hr>
  			
  			<div class="sideButtons clearfix">
  				<a href="index.php?r=admin/logout" class="btn btn-danger btn-sm btn-embossed"><span class="fui-power"></span> Logout</a>
  			</div>
  	
  		</div><!-- /.main -->
  	
  		
  	
  	</div><!-- /.menu -->

    <?php }

    echo $content; ?>



     <!-- Load JS here for greater good =============================-->
    <script src="js/admin/jquery-1.8.3.min.js"></script>
    <script src="js/admin/jquery-ui.min.js"></script>
    <script src="js/admin/jquery.ui.touch-punch.min.js"></script>
    <script src="js/admin/bootstrap.min.js"></script>
    <script src="js/admin/bootstrap-select.js"></script>
    
    <script src="js/admin/flatui-checkbox.js"></script>
    <script src="js/admin/flatui-radio.js"></script>
    
    <script src="js/admin/flatui-fileinput.js"></script>
    
    <script src="js/admin/chosen.jquery.min.js"></script>
     <script src="js/ie10-viewport-bug-workaround.js"></script>
    
    <script src="js/admin/elements.json"></script>
    <script src="js/admin/builder.js"></script>
    <script>
    
    $(function(){
    
      var ua = window.navigator.userAgent;
      var msie = ua.indexOf("MSIE ");
      
      
    })    
    
    </script>
  </body>
</html>


