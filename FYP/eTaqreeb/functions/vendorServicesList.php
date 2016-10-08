 <?php 
 
 
 $dbstatus = include "dbhandler.php";
                        if($dbstatus == "ERROR! Connection could not be made." || $dbstatus == "ERROR! Database could not be opened."){
                                print "ERROR.";
                        }
                        
                        $isEmpty=true;
						
						global $result;

			if(isset($_POST['query']))
			{
				$sQuery = $_POST['query'];
				$searchby = $_POST['searchby'];
				$category = $_POST['category'];
				$range = $_POST['range'];
				
				if($searchby=="all" && $category=="all" && $range=="---Select---")
				{
					$query = "select * from vendor_services";
					$result=getAllServices($query);
				}
				else if($searchby=="all" && $category!="all" && $range=="---Select---")
				{
					$query = "select * from vendor_services where type='$category'";
					$result=getAllServices($query);
				}
				else if($searchby=="all" && $category=="all" && $range!="---Select---")
				{
					if($range=="Less than 1000")
					{
						$query = "select * from vendor_services where price<1000";
					}	
					else if($range=="1000 - 2000")
					{
						$query = "select * from vendor_services where price>=1000 AND price<=2000";
					}	
					else if($range=="2000 - 5000")
					{
						$query = "select * from vendor_services where price>=2000 AND price<=5000";
					}
					else if($range=="More than 5000")
					{
						$query = "select * from vendor_services where price>5000";	
					}
					
					$result=getAllServices($query);
						
				}
				else if($searchby=="all" && $category!="all" && $range!="---Select---")
				{
					if($range=="Less than 1000")
					{
						$query = "select * from vendor_services where price<1000 AND type='$category'";
					}	
					else if($range=="1000 - 2000")
					{
						$query = "select * from vendor_services where price>=1000 AND price<=2000 AND type='$category'";
					}	
					else if($range=="2000 - 5000")
					{
						$query = "select * from vendor_services where price>=2000 AND price<=5000 AND type='$category'";
					}
					else if($range=="More than 5000")
					{
						$query = "select * from vendor_services where price>5000 AND type='$category'";		
					}
					$result=getAllServices($query);	
				}
				
				//------------------------------------------------------------------------------------------------------------------------
				
				else if($searchby!="all" && $category=="all" && $range=="---Select---")
				{
					
					if($searchby=="name")
					{
						$query = "select * from vendor_services where name='$sQuery'";
					}
					else
					{
						$query = "select * from vendor_services where vendor_id=(select id from vendor where companyname='$sQuery')";
					}
					
					$result=getAllServices($query);
				
				}
				
				else if($searchby!="all" && $category!="all" && $range=="---Select---")
				{
					if($searchby=="name")
					{
						$query = "select * from vendor_services where type='$category' AND name='$sQuery'";
					}
					else
					{
						$query = "select * from vendor_services where type='$category' AND vendor_id=(select id from vendor where companyname='$sQuery')";
					}
					$result=getAllServices($query);
				}
				else if($searchby!="all" && $category=="all" && $range!="---Select---")
				{
					if($searchby=="name")
					{
						if($range=="Less than 1000")
						{
							$query = "select * from vendor_services where price<1000 AND name='$sQuery'";
						}	
						else if($range=="1000 - 2000")
						{
							$query = "select * from vendor_services where price>=1000 AND price<=2000 AND name='$sQuery'";	
						}	
						else if($range=="2000 - 5000")
						{
							$query = "select * from vendor_services where price>=2000 AND price<=5000 AND name='$sQuery'";
						}
						else if($range=="More than 5000")
						{
							$query = "select * from vendor_services where price>5000 AND name='$sQuery'";
						}
						
					}
					else
					{
						if($range=="Less than 1000")
						{
							$query = "select * from vendor_services where price<1000 AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}	
						else if($range=="1000 - 2000")
						{
							$query = "select * from vendor_services where price>=1000 AND price<=2000 AND vendor_id=(select id from vendor where companyname='$sQuery')";	
						}	
						else if($range=="2000 - 5000")
						{
							$query = "select * from vendor_services where price>=2000 AND price<=5000 AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}
						else if($range=="More than 5000")
						{
							$query = "select * from vendor_services where price>5000 AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}
						
					}
					$result=getAllServices($query);
						
				}
				else if($searchby!="all" && $category!="all" && $range!="---Select---")
				{
					if($searchby=="name")
					{
						if($range=="Less than 1000")
						{
							$query = "select * from vendor_services where price<1000 AND type='$category' AND name='$sQuery'";
						}	
						else if($range=="1000 - 2000")
						{
							$query = "select * from vendor_services where price>=1000 AND price<=2000 AND type='$category' AND name='$sQuery'";
						}	
						else if($range=="2000 - 5000")
						{
							$query = "select * from vendor_services where price>=2000 AND price<=5000 AND type='$category' AND name='$sQuery'";
						}
						else if($range=="More than 5000")
						{
							$query = "select * from vendor_services where price>5000 AND type='$category' AND name='$sQuery'";
						}
					}
					else
					{
						if($range=="Less than 1000")
						{
							$query = "select * from vendor_services where price<1000 AND type='$category' AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}	
						else if($range=="1000 - 2000")
						{
							$query = "select * from vendor_services where price>=1000 AND price<=2000 AND type='$category' AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}	
						else if($range=="2000 - 5000")
						{
							$query = "select * from vendor_services where price>=2000 AND price<=5000 AND type='$category' AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}
						else if($range=="More than 5000")
						{
							$query = "select * from vendor_services where price>5000 AND type='$category'	AND vendor_id=(select id from vendor where companyname='$sQuery')";
						}
					}
					
					$result=getAllServices($query);
						
				}				
                       
			}
			else
			{   
					$query = "select * from vendor_services";
					$result=getAllServices($query);
			}
		
			 while ( $row = mysqli_fetch_assoc($result) ) 
			{
				$isEmpty=false;
				
				if(getVendorAvailability($row['vendor_id'])=="Yes")
				{
					$ext = explode(".", $row['simage']);
                        ?>

						  
			 <div  class="upcoming-events box-hover-effect effect1 media maxwidth400 mb-20" style="background:rgb(245, 245, 245)" data-bg-color="#f5f5f5">
              <div class="row equal-height">
                <div class="col-sm-4 pr-0 pr-sm-15">
                  <div class="thumb p-15">
                    <img class="img-fullwidth" style="width:265px; height:170px" alt="" src="images/services/service<?=$row['id']?>.<?=end($ext)?>" alt="...">
                  </div>
                </div>
                <div class="col-sm-4 border-right pl-0 pl-sm-15">
                  <div class="event-details p-15 mt-20">
                    <h4 class="media-heading text-uppercase font-weight-500"><?=$row['name']?></h4>
                    <p><?=getVendorName($row['vendor_id'])?></p>
                    <a href="index.php?r=vendor/view&id=<?=$row['vendor_id']?>" class="text-orange">Other Services<i class="fa fa-angle-double-right"></i></a>
                  </div>
                </div>
                <div class="col-sm-4">
                  <div class="event-count p-15 mt-15">
                    
                      <h4>Rs. <?=$row['price']?></h4>
                 
                    <ul class="list-inline clearfix mt-20">
                      <li class="pull-left pr-0"><strong>Pricing: </strong><?= $row['pricemode']?></li><br>
                    </ul>
					<ul class="list-inline clearfix mt-20">
                      <li class="pull-left pr-0"><strong>Category: </strong><?= $row['type']?></li><br>
                    </ul>
                    <div class="mt-3">
					  <a href="?r=vendorservices/view&id=<?=$row['id']?>" class="btn btn-colored  btn-sm pull-right">Details</a>  
                    </div>
                  </div>
                </div>
              </div>
			  </div>
        
			  
			   <?php 
				}
				

			   } 
?>
<?php
    if($isEmpty)
    { ?>
           <br/><br/><p style='font-style: italic; text-align: center; font-size: 25px'>No results found</p>
<?php  } ?>

