/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//  Softenica Validate Register Form
**************************************************/

function validateRegister(){
    
    var name = document.getElementById("name").value;
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;
    var confirmPassword = document.getElementById("confirmPassword").value;
    var email = document.getElementById("email").value;
    var nsuid = document.getElementById("nsuid").value;
    var phoneno = document.getElementById("phoneno").value;
    var major = document.getElementById("major").value;
    var agencyName = document.getElementById("agencyName").value;
    var agencyAddress = document.getElementById("agencyAddress").value;
    var agencyWebsite = document.getElementById("agencyWebsite").value;
    var supervisorName = document.getElementById("supervisorName").value;
    var supervisorphoneNo = document.getElementById("supervisorphoneNo").value;
    var supervisorEmail = document.getElementById("supervisorEmail").value;

    var isValidForm = true;

    if($("#offerLetter").val() == ''){
        document.getElementById("offerLetter_err").innerHTML = "*Upload required";
        isValidForm = false;
    }
    else
    {
        document.getElementById("offerLetter_err").innerHTML = "";
    }

    if($("#jobDescription").val() == ''){
        document.getElementById("jobDescription_err").innerHTML = "*Upload required";
        isValidForm = false;
    }
    else
    {
        document.getElementById("jobDescription_err").innerHTML = "";
    }

    if (!document.getElementById('agree').checked) {
        document.getElementById("agree_err").innerHTML = "*Check required";
        isValidForm = false;
    }
    else
    {
         document.getElementById("agree_err").innerHTML = "";
    }

    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
    }


    if(username == ""){
        document.getElementById("err_username").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("err_username").innerHTML = "";
    }

    if(password == ""){
        document.getElementById("password_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("password_err").innerHTML = "";
    }

    if(confirmPassword == ""){
        document.getElementById("confirmPassword_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else if(confirmPassword!=password)
    {
        document.getElementById("confirmPassword_err").innerHTML = "*Password not Matched";
        isValidForm = false;
    }
    else{
        document.getElementById("confirmPassword_err").innerHTML = "";
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


    if(nsuid == ""){
        document.getElementById("nsuid_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("nsuid_err").innerHTML = "";
    }

    if(phoneno == ""){
        document.getElementById("phoneno_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("phoneno_err").innerHTML = "";
    }

    if(major == ""){
        document.getElementById("major_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("major_err").innerHTML = "";
    }

    if(agencyName == ""){
        document.getElementById("agencyName_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("agencyName_err").innerHTML = "";
    }

    if(agencyAddress == ""){
        document.getElementById("agencyAddress_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("agencyAddress_err").innerHTML = "";
    }

    if(agencyWebsite == ""){
        document.getElementById("agencyWebsite_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("agencyWebsite_err").innerHTML = "";
    }

    if(supervisorName == ""){
        document.getElementById("supervisorName_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("supervisorName_err").innerHTML = "";
    }

    if(supervisorEmail == ""){
        document.getElementById("supervisorEmail_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("supervisorEmail_err").innerHTML = "";
    }

    if(supervisorphoneNo == ""){
        document.getElementById("supervisorphoneNo_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("supervisorphoneNo_err").innerHTML = "";
    }



    if(!isValidForm){
        return false;
    }
    return true;
}


function registerAJAX()
{
    if(!validateRegister())
    {
        return false;
    }
    else
    {

        var username = document.getElementById("username").value;
        var password = document.getElementById("password").value;
        var confirmPassword = document.getElementById("confirmPassword").value;
        var email = document.getElementById("email").value;
        
        $.ajax({
        type:"POST",
                url:"../functions/addUser.php",
                data:{username:username,password:password, email:email},
                cache:false,
                success: function(result){
                    var res = trimResult(result);
                    if(result == "add"){
                        $("#register").attr('disabled','disabled');
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
    var username = document.getElementById("username").value;
        
    $.ajax({
            type:"POST",             // Type of request to be send, called as method
            data:formData,
            url:"../functions/upload.php",
            contentType: false,       // The content type used when sending data to the server.
            cache: false,             // To unable request pages to be cached
            processData:false,    
            success: function(result){
                var res = trimResult(result);
                if(result == "upload"){
                    addInfoAJAX();
                }
                else{
                    alert('Error');
                }
            }
    });  
 
}


function addInfoAJAX()
{

    var name = document.getElementById("name").value;
    var username = document.getElementById("username").value;
    var nsuid = document.getElementById("nsuid").value;
    var phoneno = document.getElementById("phoneno").value;
    var major = document.getElementById("major").value;
    var agencyName = document.getElementById("agencyName").value;
    var agencyAddress = document.getElementById("agencyAddress").value;
    var agencyWebsite = document.getElementById("agencyWebsite").value;
    var supervisorName = document.getElementById("supervisorName").value;
    var supervisorphoneNo = document.getElementById("supervisorphoneNo").value;
    var supervisorEmail = document.getElementById("supervisorEmail").value;
    var email = document.getElementById("email").value;

    var terms = document.getElementsByName('term');
    var term;
    for(var i = 0; i < terms.length; i++){
        if(terms[i].checked){
            term = terms[i].value;
        }
    }
        
    $.ajax({
            type:"POST",
            url:"../functions/addStudentInfo.php",
            data:{name:name, email:email, username:username, nsuid:nsuid, phoneno:phoneno, major:major, agencyName:agencyName, agencyAddress:agencyAddress, agencyWebsite:agencyWebsite, supervisorName:supervisorName, supervisorEmail:supervisorEmail, supervisorphoneNo:supervisorphoneNo, term:term},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "add"){
                    alert('Registered Successfully!'); 
                    window.location='../index.php';
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