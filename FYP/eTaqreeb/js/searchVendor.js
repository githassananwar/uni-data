function validateSearch(){

	var query = document.getElementById("query").value;
    var searchby=document.querySelector('input[name="search"]:checked').value;
  
    var isValidForm = true;
	
    if(searchby != "all" && query==""){
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


function searchVendor()
{ 

	if(!validateSearch())
    {
        return false;
    }
    else
    {
    
	 var query = document.getElementById("query").value;
     var searchby=document.querySelector('input[name="search"]:checked').value;
     $("#vendorlist").load('functions/vendorList.php', {query:query, searchby:searchby});
       
        
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



