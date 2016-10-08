/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Remove Admim
**************************************************/


function checkUserNameAJAX()
{
    var username = document.getElementById("username").value;

    if(username!="")
    {
	 $.ajax({
            type:"POST",
            url:"../functions/checkUserName.php",
            data:{name:username},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "available"){
                    document.getElementById("available_username").innerHTML = "Available";
                    document.getElementById("err_username").innerHTML = "";
                     $("#add_admin").removeAttr('disabled');
                     $("#register").removeAttr('disabled');
                }
                else
                {
                    document.getElementById("available_username").innerHTML = "";
                    document.getElementById("err_username").innerHTML = "Not Available";
                    $("#add_admin").attr('disabled','disabled');
                    $("#register").attr('disabled','disabled');
                }
            }
            });
    }
    else
    {
        document.getElementById("available_username").innerHTML = "";
        document.getElementById("err_username").innerHTML = "";
        $("#add_admin").removeAttr('disabled');
        $("#register").removeAttr('disabled');
    }



}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}
