<html>
<head>
<title>Information</title></head>

<%@ page language = "java" import = "java.sql.*" %>
<body>


<%
try{
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/class_test";;
    Connection con=DriverManager.getConnection(url, "root", "");

String name = request.getParameter("uname");
String address = request.getParameter("uaddress");

Statement stmt = con.createStatement();

int result = stmt.executeUpdate("INSERT INTO info(username,useraddress)VALUES('"+ name + "','" + address+ "') " );

if(result==1)
{out.println("Insertion Successful");}
else
{out.println("Insertion could not be Successful");}
%>

<%
stmt.close();
con.close();
%>

<%
}
catch(Exception e){System.out.println("Exception");} 
%>

</body>
</html>