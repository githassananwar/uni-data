


function validateLoginForm(){
    var x = document.getElementById("loginUsername");
    var y = document.getElementById("loginPassword");
    var isValidForm = true;
    if(x.value == ""){
        document.getElementById("loginUsername_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("loginUsername_err").innerHTML = "";
    }
    if(y.value == ""){
        document.getElementById("loginPassword_err").innerHTML = "*This field is required";
        isValidForm = false;
    }
    else{
        document.getElementById("loginPassword_err").innerHTML = "";
    }
    if(!isValidForm){
        return false;
    }
    return true;
}



function LoginAJAX()
{
	$('#invalid_Err_Msg').hide();
    if(!validateLoginForm())
    {
        return false;
    }
    else
    {
        var username = document.getElementById("loginUsername").value;
        var password =  document.getElementById("loginPassword").value;
	var role =  document.getElementById("select-val").value;
        $.ajax({
            type:"POST",
            url:"index.php?r="+role+"/login",
            data:{name:username,password:password},
            cache:false,
			success: function(result){
            var res = trimResult(result);
                if(result == "login"){
                    window.location='index.php?r=site/index';
                    
                }
                else{
                    $('#invalid_Err_Msg').show();
                }
				
	}
        });
    }
}

function clickLogin()
{
	$('#invalid_Err_Msg').hide();
	document.getElementById("username").value="";
	document.getElementById("password").value="";
	
}

function trimResult(res){
    var res=res.replace(/^\s+|\s+$/,'');
    return res;
}