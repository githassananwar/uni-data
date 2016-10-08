/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//  Softenica Validate Register Form
**************************************************/

function validateRegisterAgain(){
    
    
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


function registerAgainAJAX($id)
{
    if(!validateRegisterAgain())
    {
        return false;
    }
    else
    {
    
        var id = $id;
        var agencyName = document.getElementById("agencyName").value;
        var agencyAddress = document.getElementById("agencyAddress").value;
        var agencyWebsite = document.getElementById("agencyWebsite").value;
        var supervisorName = document.getElementById("supervisorName").value;
        var supervisorphoneNo = document.getElementById("supervisorphoneNo").value;
        var supervisorEmail = document.getElementById("supervisorEmail").value;

        var terms = document.getElementsByName('term');
        var term;
        for(var i = 0; i < terms.length; i++){
            if(terms[i].checked){
                term = terms[i].value;
            }
        }
            
        $.ajax({
                type:"POST",
                url:"../functions/updateStudentInfo.php",
                data:{id:id, agencyName:agencyName, agencyAddress:agencyAddress, agencyWebsite:agencyWebsite, supervisorName:supervisorName, supervisorEmail:supervisorEmail, supervisorphoneNo:supervisorphoneNo, term:term},
                cache:false,
                success: function(result){
                    var res = trimResult(result);
                    if(result == "add"){
                        $("#register").attr('disabled','disabled');
                        reUploadAJAX();
                    }
                    else{
                        alert('Error');
                    }
                }
        });  
       
       
    }
    
}


function reUploadAJAX()
{
     var form = $('form')[0]; 
        var formData = new FormData(form);
            
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
                        alert('Request Submitted Successfully!'); 
                        window.location='s_home.php';
                    }
                    else{
                        alert('Error');
                    }
                }
        });  
 
}


function addInfoAJAX()
{

   
 
}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}