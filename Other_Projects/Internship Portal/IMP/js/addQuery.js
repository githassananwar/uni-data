/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Validate Query Form
**************************************************/

function validateAddQuery(){
    var name = document.getElementById("name").value;
    var nsuid = document.getElementById("nsuId").value;
    var email = document.getElementById("email").value;
    var message = document.getElementById("message").value;
    var isValidForm = true;
    if(name == ""){
        document.getElementById("err_name").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("err_name").innerHTML = "";
    }

    if(nsuid == ""){
        document.getElementById("err_nsuid").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("err_nsuid").innerHTML = "";
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

    if(message == ""){
        document.getElementById("err_message").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("err_message").innerHTML = "";
    }

    if(!isValidForm){
        return false;
    }
    return true;
}


function addQueryAJAX()
{
    if(!validateAddQuery())
    {
        return false;
    }
    else
    {

        var name = document.getElementById("name").value;
        var nsuid = document.getElementById("nsuId").value;
        var email = document.getElementById("email").value;
        var message = document.getElementById("message").value;
        $.ajax({
            type:"POST",
            url:"../functions/addQuery.php",
            data:{name:name, nsuid:nsuid, email:email, message:message},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "add"){
                    document.getElementById("name").value="";
                    document.getElementById("nsuId").value="";
                    document.getElementById("email").value="";
                    document.getElementById("message").value="";
                    alert('Message Sent Successfully');
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