<%@ page language="java" import="java.util.*, test.DBConnectivity, test.Student"%>

<%
DBConnectivity obj=new DBConnectivity();
ArrayList<Student> std=obj.GetAllStudent(); 
%>
<TABLE BORDER=1 ALIGN=CENTER>
<TR BGCOLOR="#FFAD00">
<TH>ID </TH><TH>NAME</TH> <TH> GPA	</TH>
</TR><tr>	
<%for(int i=0;i<std.size();i++)
{
		out.println("<TR><TD>" +std.get(i).getID() + "</TD>");
		 out.println("<TD>" +std.get(i).getName() + "</TD>");
		 out.println("<TD>" +std.get(i).getGPA() + "</TD> </TR>");
 }
%>
</TABLE>