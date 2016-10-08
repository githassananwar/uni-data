
function actionEventService($id)
{
	var submit_id=$id;
    var choice = document.getElementById(submit_id).value;
  
    if(choice=="Confirm")
    {
        $.ajax({
            type:"POST",
            url:"index.php?r=eventservices/confirmrequest&id="+submit_id,
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "confirm"){
                   $("#customerRequests").load('?r=eventServices/customerRequests');
                   
                }
                else
                {
                    alert('Error!');
                }
            }
            });
        
    }
	else if(choice=="Cancel")
    {
        $.ajax({
            type:"POST",
            url:"index.php?r=eventservices/cancelrequest&id="+submit_id,
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "cancelled"){
                   $("#customerRequests").load('?r=eventServices/customerRequests');
                   
                }
                else
                {
                    alert('Error!');
                }
            }
            });
        
    }
 
}



function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}