<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.sql.*" %>

<html>

<head>

<link rel="StyleSheet" href="style.css"/>
<title>Login</title>

<style>

#options 
{
background-color:#000000;
height:5.5%;
width:100%;
}

#brk
{
background-color:#000000;
height:1%;
width:100%;
display: inline;
float:right;

}


#textsection
{
background-COLOR:#F0F0F0;
float:left;
height:77%;
width:100%;
}


h1
{
display: inline;
}

h3
{
display: inline;
}

</style>
</head>



<body style="background-color:#292929">


<div id="Header" >
<br><br><br>
<h1 style="color:white">&nbsp &nbsp Login</h1>

</div>


<div class="image">
<img src="pic.jpg" border="2" style="border-color:white"/>
</div>


<div id="strip">
</div>

<div id="options">
</div>


<div id="textsection" >
<br><br><br><br>

<form>
  <table align="center" frame="box">
    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Enter UserName: </h3></td>
      <td align="left"><input type="text" name="username" /></td>
    </tr>

<tr></tr><tr></tr>

<tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Enter Password: </h3></td>
      <td align="left"><input type="password" name="password" /></td>
    </tr>

<tr></tr><tr></tr>


    <tr>
      <td align="right" valign="top"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Category: </h3></td>
      
       <td align="left">
<input type="radio" name="ct" value="Owner">Owner&nbsp
<input type="radio" name="ct" value="Manager">Manager&nbsp
<input type="radio" name="ct" value="Cashier">Cashier
</td>


   </tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr>
  

<td align="left">
<h3 style="color:red;">
<%
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String cat = request.getParameter("ct");
		
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
				
			if(username!=null && password!=null && cat!=null)
			{
				ResultSet rs = st.executeQuery("select* from login where username='"+username+"' and password='"+password+"' and cat='"+cat+"'");
				if(rs.next())
				{
					response.sendRedirect("home.html");
				}
				else
				{
					out.println("Invalid Login");
				}
				
			}
			
		}
		catch(Exception ex)
		{
			System.out.println("Exception :" + ex.getMessage());
			ex.getStackTrace();
		}




%>

  
</h3>


</td>

<td align="right">&nbsp&nbsp&nbsp<input type="submit" value="Login" />

</td>
</tr>



<tr></tr><tr></tr>



</table>



</form>


</div>


<div id="strip">
</div>

<div id="footer" >
Copyrights-All Rights Reserved
</div>
</body>


</html>