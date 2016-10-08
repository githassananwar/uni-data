<!DOCTYPE html>

<?php
/* @var $this SiteController */
/* @var $model ContactForm */
/* @var $form CActiveForm */




$this->pageTitle=Yii::app()->name . 'Vendors';

?>


<div class="main-content">

 <section class="inner-header divider layer-overlay overlay-dark" data-bg-img="images/abtslide2.jpg">
      <div class="container pt-30 pb-30">
        <!-- Section Content -->
        <div class="section-content text-center">
          <div class="row"> 
            <div class="col-md-6 col-md-offset-3 text-center">
              <h2 class="text-orange font-36">Vendors</h2>
              <ol class="breadcrumb text-center mt-10 white">
                <li><a href="#">Home</a></li>
                <li class="active">Vendors</li>
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
            <div class="row" id="vendorlist">
              
                 
               
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
                      <button class="btn search-button"type="button"  onclick="searchVendor()"><i class="fa fa-search"></i></button>
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
                    <li><input type="radio" name="search" value="companyname">&nbsp Company Name</li>
                    <li><input type="radio" name="search" value="name">&nbsp Owner Name</li>
                    <li><input type="radio" name="search" value="email">&nbsp Email</li>
                    <li><input type="radio" name="search" value="contact">&nbsp Contact</li>
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
            $("#vendorlist").load('functions/vendorlist.php');
    
        });

</script>

<script src="js/searchVendor.js"></script>
<script src="js/rating.js"></script>