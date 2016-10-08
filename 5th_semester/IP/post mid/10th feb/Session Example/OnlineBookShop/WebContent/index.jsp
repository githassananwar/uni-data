<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%if (session.getAttribute("user") != null) 
    {%>
    	<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
    	<html>
    	<head>
    	<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
    	<title>Insert title here</title>
    	</head>
    	<body>
    	<font face="Times New Roman,Times" size="+3">
    	    Online Book Store
    	  </font>
    	  <hr><p>
    	  <center>
    	  <form  action="loginServ" method="POST">
    	  <input type="submit" name="btnlogout" value="logout"/>
    	 </form>
    	  <form name="shoppingForm" action="shoppingServlet" method="POST">
    	  <b>Books :</b> 
    		  <select name="book">
    			<option>Inside XML | The Guo Brothers | $14.95</option>
    			<option>Inside Java | Babatunde Olatunji |  $16.95</option>
    			<option>Inside JEE | Tounami Diabate|  $16.95</option>
    			<option>Inside JME | Eliades Ochoa | $13.95</option>
    			<option>Inside WML | Outback |  $14.95</option>
    			<option>Inside XHTML | Samulnori | $12.95</option>
    			<option>Inside WML Script | Tounami Diabate | $14.95</option>
    			<option>Inside WAP | PUCIT |  $12.95</option>
    			<option>Inside CSS | Cesaria Evora | $16.95</option>
    			<option>Inside Web Services | Kodo | $13.95</option>
    		  </select>
    	  <b>Quantity: </b>
    		  <input type="text" name="qty" SIZE="3" value=1>
    		  <input type="submit" name="Submit" value="Add to Cart">
    	  </form>
    	    <jsp:include page="/showCart.jsp" flush="true" />
    	  </center>

    	</body>
    	</html>
    	
    <%} else {
        response.sendRedirect("login.jsp"); // Not logged in, redirect to login page.
    } %>
