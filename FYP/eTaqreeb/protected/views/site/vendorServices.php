<!DOCTYPE html>

<?php
/* @var $this SiteController */
/* @var $model ContactForm */
/* @var $form CActiveForm */




$this->pageTitle=Yii::app()->name . 'Vendor Services';

?>


<div class="main-content">

 <section class="inner-header divider layer-overlay overlay-dark" data-bg-img="images/abtslide2.jpg">
      <div class="container pt-30 pb-30">
        <!-- Section Content -->
        <div class="section-content text-center">
          <div class="row"> 
            <div class="col-md-6 col-md-offset-3 text-center">
              <h2 class="text-orange font-36">Vendor Services</h2>
              <ol class="breadcrumb text-center mt-10 white">
                <li><a href="#">Home</a></li>
                <li class="active">Services</li>
              </ol>
            </div>
          </div>
        </div>
      </div>      
    </section>

    <!-- Divider: Partners & Donors -->
    <section>
      <div class="container">
        <div class="row">
          <div class="col-sm-12 col-md-9">
            <div class="row" id="vendorServiceslist" >
             
                 
           
            </div>


            
          </div>

          <div class="col-sm-12 col-md-3">
            <div class="sidebar maxwidth400 mt-sm-30">
              <div class="sidebar-widget mb-20">
                <div class="search-form">
                  <form>
                    <div class="input-group">
                      <input type="text" id="query" class="form-control search-input" placeholder="Click to Search">
                      <span class="input-group-btn">
                      <button class="btn search-button"type="button"  onclick="searchVendorService()"><i class="fa fa-search"></i></button>
                      </span>
                    </div>
                    <span id="search_err" style="color:red; float:left"></span>
                  </form>
                </div>
              </div>
              <div class="sidebar-widget p-15 pt-10 bg-solid-color">
                <h5 class="widget-title mt-0 mb-10">Search by <span class="line-bottom"></span></h5>
                <div class="categories">
                  <ul class="list angle-right">
                    <li><input type="radio" name="search" value="all" checked> &nbsp Show All</li>
                    <li><input type="radio" name="search" value="name">&nbsp Service Name</li>
                    <li><input type="radio" name="search" value="vendorname">&nbsp Vendor Name</li>
                  </ul>
                </div>
              </div>
              
              <div class="sidebar-widget p-15 pt-10 bg-solid-color">
                <h5 class="widget-title mt-0 mb-10">Price Range(Rs)<span class="line-bottom"></span></h5>
                <div class="categories">
                  <select id="range"  class="form-control" style="width: 239px;" required>
                                                                        <option>---Select---</option>
                                                                        <option>Less than 1000</option>
                                                                        <option>1000 - 2000</option>
                                                                        <option>2000 - 5000</option>
                                                                        <option>More than 5000</option>
                 </select>
                  
                </div>
              </div>
              

              <div class="sidebar-widget p-15 pt-10 bg-solid-color">
                <h5 class="widget-title mt-0 mb-10">Category<span class="line-bottom"></span></h5>
                <div class="categories">
                  <ul class="list angle-right">
                   <li><input type="radio" name="type" value="all" checked> &nbsp Show All</li>
                    <li><input type="radio" name="type" value="Caterers" > &nbsp Caterers</li>
                    <li><input type="radio" name="type" value="Venue">&nbsp Venue</li>
                    <li><input type="radio" name="type" value="Decorators">&nbsp Decorators</li>
                    <li><input type="radio" name="type" value="Photography">&nbsp Photography</li>
                    <li><input type="radio" name="type" value="Sound & DJ">&nbsp Sound & DJ</li>
                    <li><input type="radio" name="type" value="Salon & Spa">&nbsp Salon & Spa</li>
                    <li><input type="radio" name="type" value="Event Managers">&nbsp Event Managers</li>
                    <li><input type="radio" name="type" value="Other">&nbsp Other</li>
                  </ul>
                </div>
              </div>
              

       
        </div>

        </div>

        </div>

        </div>
    
    </section>


  </div>
  <!-- end main-content -->
  


<script>
$(document).ready(function(){
            $("#vendorServiceslist").load('functions/vendorServicesList.php');
    
        });

</script>

<script src="js/searchService.js"></script>