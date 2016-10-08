function validateCreateEvent(){

	var name = document.getElementById("name").value;
	var type = document.getElementById("etype").value;
    var date = document.getElementById("date").value;
    var shift = document.getElementById("type").value;
	var budget = document.getElementById("budget").value;
	var numofguests = document.getElementById("numofguests").value;
	
    var isValidForm = true;
  
    if(name == ""){
        document.getElementById("name_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("name_err").innerHTML = "";
    }
	
	if(type == ""){
        document.getElementById("type_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("type_err").innerHTML = "";
    }
    
	if(budget == ""){
        document.getElementById("budget_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isNumber(budget)){
        document.getElementById("budget_err").innerHTML = "*Invalid amount";
        isValidForm = false;
    }
    else{
        document.getElementById("budget_err").innerHTML = "";
    }
  
  if(date == ""){
        document.getElementById("date_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("date_err").innerHTML = "";
    }
  
	if(shift == "0"){
        document.getElementById("shift_err").innerHTML = "*Select shift";
        isValidForm = false;
    }
    else{
        document.getElementById("shift_err").innerHTML = "";
    }
  
	if(numofguests == ""){
        document.getElementById("numofguests_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
	else if(!isNumber(numofguests)){
        document.getElementById("numofguests_err").innerHTML = "*Invalid number";
        isValidForm = false;
    }
    else{
        document.getElementById("numofguests_err").innerHTML = "";
    }
  
  
    if(!isValidForm){
        return false;
    }
    return true;
}

function createEventAJAX()
{ 
    if(!validateCreateEvent())
    {
        return false;
    }
    else
    {
	  alert("Event created successfully!");
      form = document.forms[0] //assuming only form.
      form.submit();
    }
}

function updateEventAJAX()
{ 
    if(!validateCreateEvent())
    {
        return false;
    }
    else
    {
	  alert("Event updated successfully!");
      form = document.forms[0] //assuming only form.
      form.submit();
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



$(document).ready(function(){
$("#date").datepicker({ minDate: 0 });
$( "#date" ).datepicker({
    inline: true
});
$( "#datepicker2" ).datepicker({
    inline: true
});
$.extend($.datepicker,{_checkOffset:function(inst,offset,isFixed){return offset}});

});