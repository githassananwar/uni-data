/**
 * Created by Asad Rehman on 07-Mar-16.
 */

/**************************************************
//	Softenica Answer Query
**************************************************/

function validateAnswerQuery($id){
    var reply = document.getElementById("reply"+$id).value;
   
    var isValidForm = true;
    if(reply == ""){
        document.getElementById("reply_err"+$id).innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("reply_err"+$id).innerHTML = "";
    }

    

    if(!isValidForm){
        return false;
    }
    return true;
}


function answerQueryAJAX($id, $email, $name)
{
    if(!validateAnswerQuery($id))
    {
        return false;
    }
    else
    {
        var reply = document.getElementById("reply"+$id).value;
        var id= $id;
        var email= $email;
        var name= $name;
        $.ajax({
            type:"POST",
            url:"../functions/answerQuery.php",
            data:{reply:reply, id:id, email:email, name:name},
            cache:false,
            success: function(result){
                var res = trimResult(result);
                if(result == "add"){
                    document.getElementById("reply"+$id).value="";
                    $("#query").load('queryList.php');
                    alert('Reply Sent Successfully');
                }
                else{
                    alert('Error');
                }
            }
        });
        
        

    }
    
}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}