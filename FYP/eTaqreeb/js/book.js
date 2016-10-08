function bookAJAX($amount, $id, $serviceId)
{
		
        
        $.ajax({
            type:"POST",
            url:"functions/book.php",
            data:{amount:$amount, id:$id},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "ok"){
					 window.location='index.php?r=vendorservices/book&id='+$serviceId;
                }
                else{
                    var r = confirm("Alert! Budget limit crossed. Do you still want to request service?");
					if (r == true) {
					  window.location='index.php?r=vendorservices/book&id='+$serviceId;
					} 
                }
            }
        });
        

    
    
}

