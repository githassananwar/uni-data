function validateSignup(){

	var name = document.getElementById("name").value;
	var email = document.getElementById("email").value;
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;
	var contact = document.getElementById("contact").value;
	var confirmPassword = document.getElementById("confirmpassword").value;
  
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
        document.getElementById("email_err").innerHTML = "*Invalid Email Format";
        isValidForm = false;
    }
    else{
        document.getElementById("email_err").innerHTML = "";
    }
  
  if(username == ""){
        document.getElementById("username_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("username_err").innerHTML = "";
    }
  
  if(password == ""){
        document.getElementById("password_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("password_err").innerHTML = "";
    }
  
  
  if(confirmPassword == ""){
        document.getElementById("confirmpassword_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
  else if(confirmPassword!=password && password!="")
    {
        document.getElementById("confirmpassword_err").innerHTML = "*Password not Matched";
    isValidForm = false;
    }
    else{
        document.getElementById("confirmpassword_err").innerHTML = "";
    }
  
    if(contact == ""){
        document.getElementById("contact_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isContact(contact))
	{
		document.getElementById("contact_err").innerHTML = "*Invalid Contact no";
        isValidForm = false;
	}
    else{
        document.getElementById("contact_err").innerHTML = "";
    }
  
    if(!isValidForm){
        return false;
    }
    return true;
}

function SignupAJAX()
{ 
    if(!validateSignup())
    {
        return false;
    }
    else
    {
	  alert("Sign up successfully! Please login.");
      form = document.forms[0] //assuming only form.
      form.submit();
    }
}

function updateCustomerAJAX()
{ 
    if(!validateSignup())
    {
        return false;
    }
    else
    {
	  alert("Profile Updated successfully!");
      form = document.forms[0] //assuming only form.
      form.submit();
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

function isContact(contact) {
  if (!$.isNumeric(contact)) {
  //Check if phone is numeric
  return false;
}

return true;
}

