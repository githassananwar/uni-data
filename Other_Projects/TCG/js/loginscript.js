/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate Login Form
**************************************************/


function validateLoginForm(){
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    var isValidForm = true;
   
    if(email == ""){
        document.getElementById("email_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("email_err").innerHTML = "";
    }

    if(password == ""){
        document.getElementById("password_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("password_err").innerHTML = "";
    }

    if(!isValidForm){
        return false;
    }
    return true;
}



function login()
{
    if(!validateLoginForm())
    {
        return false;
    }
    else
    {
        var email = document.getElementById("email").value;
        var password = document.getElementById("password").value;
        $.ajax({
            type:"POST",
            url:"functions/loginprocessing.php",
            data:{username:email,password:password},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "login"){
                    window.location='Admin/adminpanel.php';
                }
                else{
                    $('#invalid_Err_Msg').show();
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