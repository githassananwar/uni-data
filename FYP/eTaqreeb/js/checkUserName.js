

function checkUserNameAJAX()
{
    var username = document.getElementById("username").value;

    if(username!="")
    {
	 $.ajax({
            type:"POST",
            url:"functions/checkUserName.php",
            data:{name:username},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "available"){
                    document.getElementById("available_username").innerHTML = "Available";
                    document.getElementById("username_err").innerHTML = "";
                     $("#add_customer").removeAttr('disabled');
					 $("#add_vendor").removeAttr('disabled');
                   
                }
                else
                {
                    document.getElementById("available_username").innerHTML = "";
                    document.getElementById("username_err").innerHTML = "Not Available";
                    $("#add_customer").attr('disabled','disabled');
					$("#add_vendor").attr('disabled','disabled');
                }
            }
            });
    }
    else
    {
        document.getElementById("available_username").innerHTML = "";
        document.getElementById("username_err").innerHTML = "";
        $("#add_customer").removeAttr('disabled');
		$("#add_vendor").removeAttr('disabled');
    }



}


function updateUserNameAJAX($id, $role)
{
    var username = document.getElementById("username").value;

    if(username!="")
    {
	 $.ajax({
            type:"POST",
            url:"functions/updateUserName.php",
            data:{name:username, role:$role,id:$id},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "available"){
                    document.getElementById("available_username").innerHTML = "Available";
                    document.getElementById("username_err").innerHTML = "";
                     $("#add_customer").removeAttr('disabled');
					 $("#add_vendor").removeAttr('disabled');
                   
                }
                else
                {
                    document.getElementById("available_username").innerHTML = "";
                    document.getElementById("username_err").innerHTML = "Not Available";
                    $("#add_customer").attr('disabled','disabled');
					$("#add_vendor").attr('disabled','disabled');
                }
            }
            });
    }
    else
    {
        document.getElementById("available_username").innerHTML = "";
        document.getElementById("username_err").innerHTML = "";
        $("#add_customer").removeAttr('disabled');
		$("#add_vendor").removeAttr('disabled');
    }



}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}
