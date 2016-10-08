<html>
<head>
<title>Information</title></head>
<%@ page language = "java" import="java.sql.*" %>
<body>
<%

String login_id = request.getParameter("id");

    Class.forName("com.mysql.jdbc.Driver");
   	
	String url = "jdbc:mysql://127.0.0.1/class_test";;
   	Connection con=DriverManager.getConnection(url, "root", "");

	Statement stmt = con.createStatement();

	String query = "select * from info where username='" +login_id+ "' ";
	ResultSet rs=stmt.executeQuery(query);


if(rs.next()) {out.println("Login ID already Exist. Please choose another");}
else{out.println("Login ID is available. You may proceed.....");}

stmt.close();
con.close();
%>

</body>
</html>