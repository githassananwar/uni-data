<%@ page language="java" import="java.util.*, DAO.Book" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
ArrayList<Book> lst= (ArrayList<Book>)session.getAttribute("selectedbooks");
if(lst==null)
{
	out.print("no book selected");
}
else
{%>
<table>
<%	for(int i=0;i<lst.size();i++)
    {
		out.println("<TR><TD>" +lst.get(i).getTitle() + "</TD>");
		 out.println("<TD>" +lst.get(i).getQuantity() + "</TD></TR>");
    } %>
    </table>
<%}
%>
</body>
</html>