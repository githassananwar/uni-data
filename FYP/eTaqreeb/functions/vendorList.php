<?php 
 error_reporting(E_ERROR | E_PARSE);
 require_once("dbcontroller.php");
 
 $dbstatus = include "dbhandler.php";
                        if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
                        }
                        
                        $isEmpty=true;
						
						global $result;
			if(isset($_POST['query']))
			{
				$query = $_POST['query'];
				$searchby = $_POST['searchby'];
				
						if($searchby=="all")
						{
							$result=getAllVendors();
						}
						else if($searchby=="contact")
						{
							$result=getAllVendorsByContact($query);
						}
						else
						{
							$result=getAllVendorsBy($query,$searchby);
						}
						
						
                       
			}
			else
			{       
					$result=getAllVendors();	
					
			}
		
			 while ( $row = mysqli_fetch_assoc($result) ) 
			{
				$isEmpty=false;
				$db_handle = new DBController();
$query ="SELECT * FROM rating where vendor_id = " . $row['id'];
$resultt = $db_handle->runQuery($query);

$ext = explode(".", $row['image']);

                        ?>
						
		  
			  <div class="col-sm-6 col-md-4 col-lg-4">
                <div class="causes box-hover-effect effect1 maxwidth500 mb-30" style="background:rgb(245, 245, 245)" data-bg-color="#f5f5f5">
                  <div class="thumb">
                    <img class="img-fullwidth" style="width:265px; height:195px" alt="" src="images/vendor/vendor<?=$row['id']?>.<?=end($ext)?>">
                  </div>
                  
                  <div class="causes-details clearfix border-bottom p-15 pt-10">
                    <h5><a href="#"><?=$row['companyname']?></a></h5>
                    <p><?=$row['address']?></p>
                    <ul class="list-inline clearfix mt-20">
                      <li class="pull-left pr-0">Email: <?= $row['email']?></li><br>
                    </ul>
					<ul class="list-inline clearfix mt-20">
                      <li class="pull-left pr-0">Contact: <?= $row['contact1']?></li><br>
                    </ul>
					
					
					
					
					
					<?php
if(!empty($resultt)) {
$i=0;
foreach ($resultt as $tutorial) {
	
	$stars = 0;
	
	if($tutorial['noOfRatings'] != 0)
	{
		$stars = ($tutorial["rating"]/$tutorial['noOfRatings']);
	}
	$tutorial['noOfRatings']++;
?>
<table  class="demo-table">
<tbody>
<tr>
<td valign="top">
<div  id="tutorial-<?php echo $tutorial["id"]; ?>">
<input type="hidden" name="rating" id="rating" value="<?php echo $tutorial["rating"]; ?>" />
<ul>
  <?php
  for($i=1;$i<=5;$i++) {
  $selected = "";
  if(!empty($tutorial["rating"]) && $i<=$stars) {
	$selected = "selected";
  }
  ?>
  <li id = '<?php echo $row['username']; ?><?php echo $i; ?>' class='<?php echo $selected; ?>' onmouseover="highlightStar(this,<?php echo $tutorial["id"]; ?>);" onmouseout="removeHighlight('<?php echo $row['username']; ?>',<?php echo $tutorial["id"]; ?>,<?php echo $i; ?>,<?php echo $stars; ?>);" onClick="addRating(this,<?php echo $tutorial["id"]; ?>,<?php echo $tutorial['noOfRatings'];?>,<?php echo $tutorial['rating'];?>);">&#9733;</li>  
<?php }
  ?>
<ul>
</div>
</td>
</tr>
</tbody>
</table>
<?php		
}
}
?>
					
					
					
					
					
                    <div class="mt-10">
                     <a class="btn btn-colored btn-orange btn-sm pull-left" href="index.php?r=vendor/view&id=<?=$row['id']?>">Details</a>
                     
                    </div>
                  </div>
                </div>
              </div>
			  
			  
			   <?php ; } 
?>
<?php
    if($isEmpty)
    { ?>
           <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>No results found</p>
<?php  } ?>
<script type="text/javascript" src="js/rating.js"></script>