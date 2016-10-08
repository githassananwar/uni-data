/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate Change Form
**************************************************/
function validateUsername(){
    var username = document.getElementById("username").value;
   
    var isValidForm = true;
    if(username == ""){
        document.getElementById("username_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("username_err").innerHTML = "";
    }

    if(!isValidForm){
        return false;
    }

    return true;
}



function validateUpdate(){
    var code = document.getElementById("code").value;
    var newPassword = document.getElementById("newPassword").value;
    var confirmPassword = document.getElementById("confirmPassword").value;
    
    var isValidForm = true;
    if(code == ""){
        document.getElementById("code_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("code_err").innerHTML = "";
    }

    if(newPassword == ""){
        document.getElementById("newpassword_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("newpassword_err").innerHTML = "";
    }

    if(confirmPassword == ""){
        document.getElementById("mismatch_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("mismatch_err").innerHTML = "";
    }


    if(!isValidForm){
        return false;
    }

    return true;
}


function checkUserAJAX()
{
    if(!validateUsername())
    {
        return false;
    }
    else
    {

            var username = document.getElementById("username").value;
            $.ajax({
            type:"POST",
            url:"../functions/checkUserName.php",
            data:{name:username},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "fail"){
                    generateCodeAJAX();
                }
                else
                {
                     $('#invalid_Err_Msg').show();
                }
            }
            });
        }


    }


    function generateCodeAJAX()
    {
        var username = document.getElementById("username").value;
        $.ajax({
            type:"POST",
            url:"../functions/generateChangeCode.php",
            data:{name:username},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "generated"){
                    $('#invalid_Err_Msg').hide();
                    $("#notification").show();
                    $("#usernamepart").hide();
                    $("#updatepart").show();
                    $("#submitbutton").hide();
                    $("#updatebutton").show();
                }
                else
                {
                     alert("Error!");
                }
            }
        });
               
    }



function UPAJAX()
{
    if(!validateUpdate())
    {
        return false;
    }
    else
    {

        var code = document.getElementById("code").value;
        var newPassword = document.getElementById("newPassword").value;
        var confirmPassword = document.getElementById("confirmPassword").value;
        if(confirmPassword!=newPassword)
        {
            document.getElementById("mismatch_err").innerHTML = "Password not Matched";
        }
        else
        {
            document.getElementById("mismatch_err").innerHTML = "";
            $.ajax({
            type:"POST",
            url:"../functions/changePassword.php",
            data:{code:code,newpass:newPassword,confirmpass:confirmPassword},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "updated"){
                   document.getElementById("mismatch_err").innerHTML = "";
                   document.getElementById("code_err").innerHTML = "";
                   alert('Password Changed Successfully!'); 
                   window.location='../index.php';
                }
                else{
                  document.getElementById("code_err").innerHTML = "Incorrect Code Entered";
                }
            
            }
            });
        }


    }
    
}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}