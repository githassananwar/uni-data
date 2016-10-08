/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate Email Update Form
**************************************************/
function validateEmailUpdate(){
    var oldEmail = document.getElementById("oldEmail").value;
    var newEmail = document.getElementById("newEmail").value;
    var confirmEmail = document.getElementById("confirmEmail").value;
    
    var isValidForm = true;
    

    if(oldEmail == ""){
        document.getElementById("oldEmail_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else if(!isEmail(oldEmail)){
        document.getElementById("oldEmail_err").innerHTML = "*Incorrect Email Format";
        isValidForm = false;
    }
    else{
        document.getElementById("oldEmail_err").innerHTML = "";
    }

   
    if(newEmail == ""){
        document.getElementById("newEmail_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else if(!isEmail(newEmail)){
        document.getElementById("newEmail_err").innerHTML = "*Incorrect Email Format";
        isValidForm = false;
    }
    else{
        document.getElementById("newEmail_err").innerHTML = "";
    }

    if(confirmEmail == ""){
        document.getElementById("confirmEmail_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else if(confirmEmail!=newEmail)
    {
        document.getElementById("confirmEmail_err").innerHTML = "*Email not Matched";
        isValidForm = false;
    }
    else{
        document.getElementById("confirmEmail_err").innerHTML = "";
    }


    if(!isValidForm){
        return false;
    }

    return true;
}

function emailUpdateAJAX()
{
    if(!validateEmailUpdate())
    {
        return false;
    }
    else
    {

        var oldEmail = document.getElementById("oldEmail").value;
        var newEmail = document.getElementById("newEmail").value;
    
         $.ajax({
            type:"POST",
            url:"../functions/updateEmail.php",
            data:{oldEmail:oldEmail,newEmail:newEmail},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "notmatched"){
                    document.getElementById("oldEmail_err").innerHTML = "*Incorrect Old Email";
                }
                else if(result == "updated"){
                   document.getElementById("oldEmail").value = "";
                   document.getElementById("newEmail").value = "";
                   document.getElementById("confirmEmail").value = "";
                   document.getElementById("confirmEmail_err").innerHTML = "";
                   document.getElementById("oldEmail_err").innerHTML = "";
                   document.getElementById("newEmail_err").innerHTML = "";
                   alert('Email Updated Successfully!');
                }
                else
                {
                    alert('Error!');
                }
            }
            });

    }
    
}

function isEmail(email) {
  var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  return regex.test(email);
}