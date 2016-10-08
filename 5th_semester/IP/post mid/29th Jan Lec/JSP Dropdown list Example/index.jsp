<%@ page language="java" contentType="text/html; charset=ISO-8859-1" import="java.sql.*"%>
<html>
<head>
<title>Insert title here</title>
</head>
<body>

<form>
<select name="category" onchange="this.form.submit()">
<option value="--select--">--select--</option>
<option value="1"> Mobile</option>
<option  value="2"> Books</option>
</select>
<select multiple>
<%
String cat=request.getParameter("category");
out.print("cat selecte : " +cat);
try
{
Class.forName("com.mysql.jdbc.Driver");
Connection con=DriverManager.getConnection("jdbc:mysql://localhost/test","root","");
Statement st=con.createStatement();
ResultSet rs=st.executeQuery("select * from products where catId="+ cat);
while(rs.next())
{  
    out.print("<option>" + rs.getString(2)+ "</option>");
 }
}
        catch(ClassNotFoundException ex)
{
	out.println("class not found");
	
}
catch(Exception e)
{
	System.out.println("Exception: " + e.getMessage());
                e.getStackTrace();
}

%>
</select>
</form>
</body>
</html>