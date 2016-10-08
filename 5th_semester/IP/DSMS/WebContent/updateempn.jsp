<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.sql.*" %>

<html>

<head>

<link rel="StyleSheet" href="style.css"/>
<title>Update Employee</title>

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
<h1 style="color:white">&nbsp &nbsp Update Employee</h1>

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
      
   
<%
String id= (String)session.getAttribute("id");
String cat= (String)session.getAttribute("cat");

Connection conn;
try {
	Class.forName("com.mysql.jdbc.Driver");
	conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
	Statement st = conn.createStatement();

	String query="update emp set ";
	String n="";
if(cat.equals("FirstName"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Enter new FirstName: </h3></td>"
	+" <td align=left><input type=text name=fname></td></tr>");
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"fname='";
	String fname=request.getParameter("fname");
	n=fname;
	query=query+fname+"' where empid="+id+";";
}

else if(cat.equals("LastName"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Enter new LastName: </h3></td>"
	+" <td align=left><input type=text name=lname></td></tr>");
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"lname='";
	String lname=request.getParameter("lname");
	n=lname;
	query=query+lname+"' where empid="+id+";";
}

else if(cat.equals("HireDate"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Enter new HireDate: </h3></td>"
	+" <td align=left><input type=text name=day maxlength=2 size=1 placeholder=DD />"
	+"&nbsp&nbsp<input type=text name=mon maxlength=3 size=1 placeholder=MM />"
	+"&nbsp&nbsp<input type=text name=year maxlength=4 size=5 placeholder=YYYY /></td></tr>");
	
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"hiredate='";
	String day = request.getParameter("day");
	String mon = request.getParameter("mon");
	String year = request.getParameter("year");
	n=year;
	query=query+year+"-"+mon+"-"+day+"' where empid="+id+";";
}

else if(cat.equals("Salary"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Enter new Salary: </h3></td>"
	+" <td align=left><input type=text name=sal></td></tr>");
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"sal='";
	String sal=request.getParameter("sal");
	n=sal;
	query=query+sal+"' where empid="+id+";";
}

else if(cat.equals("Address"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Enter new Address: </h3></td>"
	+" <td align=left><input type=text name=add></td></tr>");
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"address='";
	String address=request.getParameter("add");
	n=address;
	query=query+address+"' where empid="+id+";";
}

else if(cat.equals("City"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Enter new City: </h3></td>"
	+" <td align=left><input type=text name=city></td></tr>");
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"city='";
	String city=request.getParameter("city");
	n=city;
	query=query+city+"' where empid="+id+";";
}

else if(cat.equals("Department"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Choose new Department: </h3></td>"
	+" <td align=left><input type=radio name=dp value=Cosmetics>Cosmetics&nbsp"
	+"<input type=radio name=dp value=Food>Food&nbsp"
	+"<input type=radio name=dp value=Grocery>Grocery&nbsp"
	+"<input type=radio name=dp value=Electronics>Electronics</td></tr>");
	
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"hdept='";
	String dept=request.getParameter("dp");
	n=dept;
	query=query+dept+"' where empid="+id+";";
}

else if(cat.equals("Category"))
{
	out.println("<td align=right><h3 style=color:0093b8;>&nbsp&nbsp&nbsp Choose new Category: </h3></td>"
	+" <td align=left><input type=radio name=ct value=Manager>Manager&nbsp"
	+"<input type=radio name=ct value=Cashier>Cashier</td></tr>");
	
	out.println(" <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr>");
	query=query+"cat='";
	String catg=request.getParameter("ct");
	n=catg;
	query=query+catg+"' where empid="+id+";";
}


			if(n!=null)
			{
				
				int rs = st.executeUpdate( query );
				if(rs>0)
				{
					out.println("<td align=left><h3 style=color:red;>Updated</h3></td>");
				}
				else
				{
					out.println("<td></td>");
				}
			
			}
			else
			{
				out.println("<td></td>");		
			}
		
		}
		catch(Exception ex)
		{
			System.out.println("Exception :" + ex.getMessage());
			ex.getStackTrace();
		}



%>

<td align="right">&nbsp&nbsp&nbsp<input type="submit" value="Submit" /></td></tr>

    




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