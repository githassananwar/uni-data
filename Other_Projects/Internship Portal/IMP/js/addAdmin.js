/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate add Admin Form
**************************************************/

function validateAddAdmin(){
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;
    var email = document.getElementById("email").value;
    var isValidForm = true;
    if(username == ""){
        document.getElementById("err_username").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("err_username").innerHTML = "";
    }

    if(password == ""){
        document.getElementById("err_password").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("err_password").innerHTML = "";
    }

    if(email == ""){
        document.getElementById("err_email").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else if(!isEmail(email)){
        document.getElementById("err_email").innerHTML = "*Incorrect Email Format";
        isValidForm = false;
    }
    else{
        document.getElementById("err_email").innerHTML = "";
    }


    if(!isValidForm){
        return false;
    }
    return true;
}


function addAdminAJAX()
{
    if(!validateAddAdmin())
    {
        return false;
    }
    else
    {

        var username = document.getElementById("username").value;
        var password = document.getElementById("password").value;
        var email = document.getElementById("email").value;
        
        $.ajax({
            type:"POST",
            url:"../functions/addAdmin.php",
            data:{user:username,password:password, email:email},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "add"){
                    document.getElementById("username").value = "";
                    document.getElementById("password").value = "";
                    document.getElementById("email").value = "";
                    document.getElementById("available_username").innerHTML = "";
                    document.getElementById("err_username").innerHTML = "";
                    document.getElementById("err_email").innerHTML = "";
                    event.preventDefault();
                    alert('Admin added successfully!');
                    $("#tab_admin-list").load('adminList.php');
                    document.getElementById('admin-list-tab').click();
                    

                }
                else{
                    alert('Error!');
                }
            }
        });
        

    }
    
}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}

function isEmail(email) {
  var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  return regex.test(email);
}