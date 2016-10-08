/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate Update Form
**************************************************/
function validateUpdate(){
    var oldPassword = document.getElementById("oldPassword").value;
    var newPassword = document.getElementById("newPassword").value;
    var confirmPassword = document.getElementById("confirmPassword").value;
    
    var isValidForm = true;
    if(oldPassword == ""){
        document.getElementById("oldpassword_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("oldpassword_err").innerHTML = "";
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
    else if(confirmPassword!=newPassword){
        document.getElementById("mismatch_err").innerHTML = "*Password not Matched";
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

function UPAJAX()
{
    if(!validateUpdate())
    {
        return false;
    }
    else
    {

        var oldPassword = document.getElementById("oldPassword").value;
        var newPassword = document.getElementById("newPassword").value;
        var confirmPassword = document.getElementById("confirmPassword").value;
        
        $.ajax({
            type:"POST",
            url:"../functions/updatePassword.php",
            data:{oldpass:oldPassword,newpass:newPassword,confirmpass:confirmPassword},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "notmatched"){
                    document.getElementById("oldpassword_err").innerHTML = "*Incorrect Old Password";
                }
                else if(result == "updated"){
                   document.getElementById("oldPassword").value = "";
                   document.getElementById("newPassword").value = "";
                   document.getElementById("confirmPassword").value = "";
                   document.getElementById("mismatch_err").innerHTML = "";
                   document.getElementById("oldpassword_err").innerHTML = "";
                   document.getElementById("newpassword_err").innerHTML = "";
                   alert('Password Updated Successfully!');
                }
                else
                {
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