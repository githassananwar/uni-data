/**
 * Created by Asad Rehman 
 */

/**************************************************
//  Softenica Validate Career Form
**************************************************/

function validateRegister(){
    
    var jobid = document.getElementById("jobid").value;
    var firstname = document.getElementById("firstname").value;
    var lastname = document.getElementById("lastname").value;
    var email = document.getElementById("email").value;
    var phone = document.getElementById("phone").value;
   
    var isValidForm = true;

    if($("#resume").val() == ''){
        document.getElementById("resume_err").innerHTML = "*Upload required";
        isValidForm = false;
    }
    else
    {
        document.getElementById("resume_err").innerHTML = "";
    }

    if($("#coverletter").val() == ''){
        document.getElementById("coverletter_err").innerHTML = "*Upload required";
        isValidForm = false;
    }
    else
    {
        document.getElementById("coverletter_err").innerHTML = "";
    }


    if(jobid == "---Select---"){
        document.getElementById("jobid_err").innerHTML = "*Select Job Id";
        isValidForm = false;
    }
    else{
        document.getElementById("jobid_err").innerHTML = "";
    }


    if(firstname == ""){
        document.getElementById("firstname_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("firstname_err").innerHTML = "";
    }

    if(lastname == ""){
        document.getElementById("lastname_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("lastname_err").innerHTML = "";
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


    if(phone == ""){
        document.getElementById("phone_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("phone_err").innerHTML = "";
    }



    if(!isValidForm){
        return false;
    }
    return true;
}


function register()
{
    if(!validateRegister())
    {
        return false;
    }
    else
    {
        var jobid = document.getElementById("jobid").value;
        var firstname = document.getElementById("firstname").value;
        var lastname = document.getElementById("lastname").value;
        var email = document.getElementById("email").value;
        var phone = document.getElementById("phone").value;

   
        $.ajax({
        type:"POST",
                url:"functions/addUser.php",
                data:{jobid:jobid,firstname:firstname, lastname:lastname, email:email, phone:phone},
                cache:false,
                success: function(result){
                    var res = trimResult(result);
                    if(result == "add"){
                        $("#apply").attr('disabled','disabled');
                        $("#loader").show();
                        uploadAJAX();
                    }
                    else{
                        alert('Error');
                    }
                }
        });


    }
        
    
}


function uploadAJAX()
{
    var form = $('form')[0]; 
    var formData = new FormData(form); 
        
    $.ajax({
            type:"POST",             // Type of request to be send, called as method
            data:formData,
            url:"functions/upload.php",
            contentType: false,       // The content type used when sending data to the server.
            cache: false,             // To unable request pages to be cached
            processData:false,    
            success: function(result){
                var res = trimResult(result);
                if(result == "upload"){
                    $("#loader").hide();
                    alert('Application submitted successfully!');
                    window.location='career.html';
                }
                else{
                    alert('Error');
                }
            }
    });  
 
}


function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}

function isEmail(email) {
  var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  return regex.test(email);
}