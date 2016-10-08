/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate Query Form
**************************************************/

function validateAddQuery(){
    var name = document.getElementById("name").value;
    var email = document.getElementById("email").value;
    var subject = document.getElementById("subject").value;
    var message = document.getElementById("message").value;
    var isValidForm = true;
    
    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
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

    if(subject == ""){
        document.getElementById("subject_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("subject_err").innerHTML = "";
    }

    if(message == ""){
        document.getElementById("message_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("message_err").innerHTML = "";
    }

    if(!isValidForm){
        return false;
    }
    return true;
}


function addQuery()
{
    if(!validateAddQuery())
    {
        return false;
    }
    else
    {

        var name = document.getElementById("name").value;
        var email = document.getElementById("email").value;
        var subject = document.getElementById("subject").value;
        var message = document.getElementById("message").value;
        $.ajax({
            type:"POST",
            url:"functions/addQuery.php",
            data:{name:name, email:email, subject:subject, message:message},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "add"){
                    alert('Message Sent Successfully');
                    document.getElementById("name").value="";
                    document.getElementById("subject").value="";
                    document.getElementById("email").value="";
                    document.getElementById("message").value="";
                }
                else{
                    alert('Error');
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