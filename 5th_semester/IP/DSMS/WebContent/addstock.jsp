<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.sql.*" %>

<html>

<head>

<link rel="StyleSheet" href="style.css"/>
<title>Add Stock</title>

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
<h1 style="color:white">&nbsp &nbsp Add Stock</h1>

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
&nbsp&nbsp&nbsp&nbsp&nbsp
<form>
  <table align="center" frame="box">

<tr></tr>

    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Stock ID: </h3></td>
      <td align="left"><input type="text" name="stockid" /></td>
    </tr>

<tr></tr><tr></tr>

 <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Purchase ID: </h3></td>
      <td align="left"><input type="text" name="pid" /></td>
    </tr>

<tr></tr><tr></tr>

<tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Purchase Date: </h3></td>
	<td align="left"><input type="text" name="day" maxlength="2" size="1" placeholder="DD" />
&nbsp&nbsp<input type="text" name="mon" maxlength="3" size="1" placeholder="MM" />
&nbsp&nbsp<input type="text" name="year" maxlength="4" size="5" placeholder="YYYY" />
</td>
    </tr>

    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Item Name: </h3></td>
      <td align="left"><input type="text" name="name" /></td>
    </tr>

<tr></tr><tr></tr>
    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Item Price(ws): </h3></td>
      <td align="left"><input type="text" name="wprice" /></td>
    </tr>

<tr></tr><tr></tr>

<tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Item Price(ret): </h3></td>
      <td align="left"><input type="text" name="rprice" /></td>
    </tr>

<tr></tr><tr></tr>


    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Item Quantity: </h3></td>
      <td align="left"><input type="text" name="itemquantity" /></td>
    </tr>

<tr></tr><tr></tr>
    <tr>
      <td align="right"><h3 style="color:0093b8;">
	&nbsp&nbsp&nbsp Stock Department: </h3></td>
      <td align="left">
<input type="radio" name="dp" value="Cosmetics">Cosmetics&nbsp
<input type="radio" name="dp" value="Food">Food&nbsp
<input type="radio" name="dp" value="Grocery">Grocery&nbsp
<input type="radio" name="dp" value="Electronics">Electronics
</td>
    </tr>


   <tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr><tr></tr>
    
<tr>
<td align="left">
<h3 style="color:red;">
<%
		String stockid = request.getParameter("stockid");
		String pid = request.getParameter("pid");
		String day = request.getParameter("day");
		String mon = request.getParameter("mon");
		String year = request.getParameter("year");

		String name = request.getParameter("name");
		String wprice = request.getParameter("wprice");
		String rprice = request.getParameter("rprice");
		String quantity=request.getParameter("itemquantity");
		String dname = request.getParameter("dp");
		
		
	
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
		

			if(stockid!=null)
			{
				int rs=st.executeUpdate("insert into purchase values (" + pid+",'"+year+"-"+mon+"-"+day+"',"+quantity+","+Integer.toString(Integer.parseInt(quantity)*Integer.parseInt(wprice))+","+stockid+")");
				
				if(rs == 1)
				{
					int rs2 = st.executeUpdate("insert into stock values (" + stockid + ",'" + name +"',"+wprice+","+rprice+","+quantity+",'"+dname+"')"); 
					if(rs2==1)
					{out.println("Added");}
					else{out.println("Failure");}
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

<td align="right">&nbsp&nbsp&nbsp<input type="submit" value="Add" />

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