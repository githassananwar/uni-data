function validateService(){

	var name = document.getElementById("name").value;
	var price = document.getElementById("price").value;
    var type = document.getElementById("type").value;
	var pricemode = document.getElementById("pricemode").value;
	
    var isValidForm = true;
	
	if($("#serviceImage").val() == ''){
        document.getElementById("serviceImage_err").innerHTML = "*Upload required";
        isValidForm = false;
    }
    else
    {
        document.getElementById("serviceImage_err").innerHTML = "";
    }
	
    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
    }
	
    if(price == ""){
        document.getElementById("price_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isNumber(price)){
        document.getElementById("price_err").innerHTML = "*Invalid amount";
        isValidForm = false;
    }
    else{
        document.getElementById("price_err").innerHTML = "";
    }
  
	if(type == "0"){
        document.getElementById("type_err").innerHTML = "*Select Shift";
        isValidForm = false;
    }
    else{
        document.getElementById("type_err").innerHTML = "";
    }
	
	if(pricemode == "0"){
        document.getElementById("pricemode_err").innerHTML = "*Select Pricing";
        isValidForm = false;
    }
    else{
        document.getElementById("pricemode_err").innerHTML = "";
    }
	
    if(!isValidForm){
        return false;
    }
    return true;
}

function validateUpdate(){

	var name = document.getElementById("name").value;
	var price = document.getElementById("price").value;
    var type = document.getElementById("type").value;
	var pricemode = document.getElementById("pricemode").value;
	
    var isValidForm = true;
	
	
    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
    }
	
    if(price == ""){
        document.getElementById("price_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isNumber(price)){
        document.getElementById("price_err").innerHTML = "*Invalid amount";
        isValidForm = false;
    }
    else{
        document.getElementById("price_err").innerHTML = "";
    }
  
	if(type == "0"){
        document.getElementById("type_err").innerHTML = "*Select Shift";
        isValidForm = false;
    }
    else{
        document.getElementById("type_err").innerHTML = "";
    }
	
	if(pricemode == "0"){
        document.getElementById("pricemode_err").innerHTML = "*Select Pricing";
        isValidForm = false;
    }
    else{
        document.getElementById("pricemode_err").innerHTML = "";
    }
	
    if(!isValidForm){
        return false;
    }
    return true;
}


function addServiceAJAX()
{ 
    if(!validateService())
    {
        return false;
    }
    else
    {
      $("#addService").attr('disabled','disabled');
      form = document.forms[0] //assuming only form.
      form.submit();
	  alert("Service added successfully!");
    }
}

function updateServiceAJAX()
{ 
    if(!validateUpdate())
    {
        return false;
    }
    else
    {
      form = document.forms[0] //assuming only form.
      form.submit();
	  alert("Service updated successfully!");
    }
}



function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}

function isNumber(budget) {
  var regex = /^[0-9]*$/;
  return regex.test(budget);
}
