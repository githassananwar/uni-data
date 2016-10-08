/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Remove Admim
**************************************************/

function testfunc($e){
    var select;
    var r = confirm("Are you sure you want to delete the admin?");
    if (r == true) {
      removeAdminAJAX($e);
    } 
}

function removeAdminAJAX($id)
{
	var submit_id=$id;
	 $.ajax({
            type:"POST",
            url:"../functions/removeAdmin.php",
            data:{id:submit_id},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "removed"){
                   $("#tab_admin-list").load('adminList.php');
                }
                else
                {
                    alert('Error!');
                }
            }
            });



}