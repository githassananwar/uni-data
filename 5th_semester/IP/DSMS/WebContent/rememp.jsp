<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.sql.*" %>

<html>

<head>

<link rel="StyleSheet" href="style.css"/>
<title>Remove Employee</title>

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
<h1 style="color:white">&nbsp &nbsp Remove Employee</h1>

</div>


<div class="image">
<img src="pic.jpg" border="2" style="border-color:white"/>
</div>


<div id="strip">
</div>

<div id="brk" >
</div>

<div id="options">
<ul id="drop-nav">
  <li><a href="home.html">Home</a></li>
  <li><a href="#">Employee</a>
    <ul>
      <li><a href="addemp.jsp">Add Employee</a></li>
      <li><a href="viewemp.html">View Employee Details</a></li>
      <li><a href="updateemp.html">Update Employee</a></li>
      <li><a href="rememp.jsp">Remove Employee</a></li>
    </ul>
  </li>
  <li><a href="#">Purchase</a>
    <ul>
      <li><a href="viewpurchase.html">View Purchase</a></li>
    </ul>
  </li>
  <li><a href="#">Sale</a>
    <ul>
      <li><a href="viewsale.html">View Sale</a></li>
    </ul>
  </li>

<li><a href="#">Invoice</a>
    <ul>
      <li><a href="geninv.html">Generate Invoice</a></li>
 	<li><a href="viewinv.html">View Invoice</a></li>
    </ul>
  </li>


<li><a href="#">Stock</a>
    <ul>
      <li><a href="addstock.jsp">Add Stock</a></li>
	<li><a href="viewstock.html">View Stock</a></li>
    </ul>
  </li>



</ul>
</div>

<div id="textsection" >
<br>

<form>
  <table align="center" frame="box">
    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Enter Employee ID: </h3></td>
      <td align="left"><input type="text" name="id" /></td>
    </tr>

<tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr>

 <tr>
<td align="left">
<h3 style="color:red;">
	
<%
		String id = request.getParameter("id");
		
	
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
	
				
			if(id!=null)
			{
				int rs = st.executeUpdate("delete from emp where empid="+id);
				if(rs>0)
				{
					out.println("Removed");
				}
				else
				{
					out.println("Failure");
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


<td align="right">&nbsp&nbsp&nbsp<input type="submit" value="Remove" />

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