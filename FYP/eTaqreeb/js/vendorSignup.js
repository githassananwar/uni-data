function validateSignup(){

	var name = document.getElementById("name").value;
	var companyname = document.getElementById("companyname").value;
	var address = document.getElementById("address").value;
	var contact1 = document.getElementById("contact1").value;
	var contact2 = document.getElementById("contact2").value;
	var email = document.getElementById("email").value;
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;
	var confirmPassword = document.getElementById("confirmpassword").value;
  
    var isValidForm = true;
	
	
	if($("#vendorImage").val() == ''){
        document.getElementById("vendorImage_err").innerHTML = "*Upload required";
        isValidForm = false;
    }
    else
    {
        document.getElementById("vendorImage_err").innerHTML = "";
    }
  
    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
    }
	
	if(companyname == ""){
        document.getElementById("companyname_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("companyname_err").innerHTML = "";
    }
	
	if(address == ""){
        document.getElementById("address_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("address_err").innerHTML = "";
    }
	
	if(contact1 == ""){
        document.getElementById("contact1_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isContact(contact1))
	{
		document.getElementById("contact1_err").innerHTML = "*Invalid Contact no";
        isValidForm = false;
	}
    else{
        document.getElementById("contact1_err").innerHTML = "";
    }
	
	if(contact2 == ""){
        document.getElementById("contact2_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isContact(contact2))
	{
		document.getElementById("contact2_err").innerHTML = "*Invalid Contact no";
        isValidForm = false;
	}
    else{
        document.getElementById("contact2_err").innerHTML = "";
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
 
  
    if(!isValidForm){
        return false;
    }
    return true;
}


function validateUpdate(){

	var name = document.getElementById("name").value;
	var companyname = document.getElementById("companyname").value;
	var address = document.getElementById("address").value;
	var contact1 = document.getElementById("contact1").value;
	var contact2 = document.getElementById("contact2").value;
	var email = document.getElementById("email").value;
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;
	var confirmPassword = document.getElementById("confirmpassword").value;
  
    var isValidForm = true;
	
	
    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
    }
	
	if(companyname == ""){
        document.getElementById("companyname_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("companyname_err").innerHTML = "";
    }
	
	if(address == ""){
        document.getElementById("address_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("address_err").innerHTML = "";
    }
	
	if(contact1 == ""){
        document.getElementById("contact1_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isContact(contact1))
	{
		document.getElementById("contact1_err").innerHTML = "*Invalid Contact no";
        isValidForm = false;
	}
    else{
        document.getElementById("contact1_err").innerHTML = "";
    }
	
	if(contact2 == ""){
        document.getElementById("contact2_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isContact(contact2))
	{
		document.getElementById("contact2_err").innerHTML = "*Invalid Contact no";
        isValidForm = false;
	}
    else{
        document.getElementById("contact2_err").innerHTML = "";
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
	  $("#add_vendor").attr('disabled','disabled');
      form = document.forms[0] //assuming only form.
      form.submit();	
	  alert("Sign up successfully! Please Login.");
	  
    }
}



function updateVendorAJAX()
{ 
    if(!validateUpdate())
    {
        return false;
    }
    else
    {
      form = document.forms[0] //assuming only form.
      form.submit();
	  alert("Profile Updated successfully!");
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

