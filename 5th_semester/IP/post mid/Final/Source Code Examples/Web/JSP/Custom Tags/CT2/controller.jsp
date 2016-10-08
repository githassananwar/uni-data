<%-- 
    Document   : controller
    Created on : Dec 24, 2009, 12:04:34 AM
    Author     : admin
--%>

<html> 
<body> 

<% 
String mobile_name = request.getParameter("mobile"); 

// redirecting user based on selection made 
if (mobile_name.equals("Nokia")) 
{
 response.sendRedirect("Nokia.jsp"); 
} 
else if (mobile_name.equals("Samsung") ) 
{
 response.sendRedirect("Samsung.jsp"); 
} 

%>

</body> 
</html>