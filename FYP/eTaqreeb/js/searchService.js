function validateSearch(){

	var query = document.getElementById("query").value;
	var range = document.getElementById("range").value;
    var searchby=document.querySelector('input[name="search"]:checked').value;
	var category=document.querySelector('input[name="type"]:checked').value;
	
  
    var isValidForm = true;
	
    if(searchby != "all" && category=="all" && range=="---Select---" && query==""){
        document.getElementById("search_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("search_err").innerHTML = "";
    }
	
	
    if(!isValidForm){
        return false;
    }
	
    return true;
}


function searchVendorService()
{ 

	if(!validateSearch())
    {
        return false;
    }
    else
    {
	
    
	 var query = document.getElementById("query").value;
	 var range = document.getElementById("range").value;
     var searchby=document.querySelector('input[name="search"]:checked').value;
	 var category=document.querySelector('input[name="type"]:checked').value;
	
	
     $("#vendorServiceslist").load('functions/vendorServicesList.php', {query:query, range:range, searchby:searchby, category:category});
       
        
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



