<?php 
if(isset($_SESSION["login_user"]) || isset($_SESSION["login_admin"])) 
{
	
?>

<?php
/* @var $this CustomerController */
/* @var $model Customer */

?>

<div class="main-content">

<section class="divider" style="background-image:none">
      <div class="container pt-0 pb-0" >
        <div class="row">
         <h3 class="page-header" style="text-align:center">Customer Details</h3>
          <div class="col-md-7">
            <div class="p-40" data-bg-color="rgba(255,255,255,0.8)">


<h4>Details:-</h4>
<div class="line-bottom mb-20"></div> 

<table>


<tr>
<td align="left"><h5 style="display:inline">Name:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->name?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Email:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->email?></strong></h5></td>
</tr>
<tr>
<td align="left"><h5 style="display:inline">Username:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->username?></strong></h5></td>
</tr>

<tr>
<td align="left"><h5 style="display:inline">Contact:&nbsp&nbsp&nbsp</h5></td> 
<td align="left"><h5 style="display:inline"><strong><?=$model->contact?></strong></h5></td>
</tr>


</table>

<br><br>


 </div>
          </div>
      </div>
     </div>

    </section>

    <?php }

else 
{
  $this->redirect(array('site/index'));
  die('Direct Access not permitted');
}

?>

