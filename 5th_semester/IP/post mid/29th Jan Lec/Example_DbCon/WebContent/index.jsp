<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<form action="DBHandler" method="get">
ID: <input name="id" type="text"/><br/>
Name: <input name="name" type="text" /><br/>
GPA: <input name="gpa" type="text" /><br/>
<input type="submit" name="add" value="Add Student"/>
<input type="submit" naem="show" value="Show Student"/>
</form>
<%
if(request.getParameter("status")!=null)
{
	if(request.getParameter("status").equals("1"))
		out.print("Congrats, inserted..");
	else
		out.print("Sorry! Not inserted..");
	}
%>
<jsp:include page="/showStudents.jsp" flush="true" />
</body>
</html>