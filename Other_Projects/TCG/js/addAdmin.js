/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate add Admin Form
**************************************************/

function validateAddAdmin(){
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;

    var isValidForm = true;

    if(password == ""){
        document.getElementById("password_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("password_err").innerHTML = "";
    }

    if(email == ""){
        document.getElementById("email_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else if(!isEmail(email)){
        document.getElementById("email_err").innerHTML = "*Incorrect Email Format";
        isValidForm = false;
    }
    else{
        document.getElementById("email_err").innerHTML = "";
    }


    if(!isValidForm){
        return false;
    }
    return true;
}


function addAdmin()
{
    if(!validateAddAdmin())
    {
        return false;
    }
    else
    {

        var username = document.getElementById("email").value;
        var password = document.getElementById("password").value;
        
        $.ajax({
            type:"POST",
            url:"../functions/addAdmin.php",
            data:{user:username,password:password},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "add"){
                    document.getElementById("email").value = "";
                    document.getElementById("password").value = "";
                    alert('Admin added successfully!');
                    window.location='viewadmin.php';
                }
                else if(result == "unavailable"){
                    document.getElementById("email_err").innerHTML = "Not Available";

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