import java.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
@WebServlet("/viewemp")
public class viewemp extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	public viewemp()
	{
		super();
	}
	
	protected void doPost(HttpServletRequest request , HttpServletResponse response) throws ServletException , IOException
	{

		String id = request.getParameter("id");
		String fname = request.getParameter("fname");
		String lname = request.getParameter("lname");
		String day = request.getParameter("day");
		String mon = request.getParameter("mon");
		String year = request.getParameter("year");
		String sal = request.getParameter("sal");
		String address = request.getParameter("address");
		String city = request.getParameter("city");
		String dept =request.getParameter("dp");
		String cat=request.getParameter("ct");
		
		
		PrintWriter out = response.getWriter();
		
		

		 out.println("<html>");
    		out.println("<head><title>View Employee</title></head>" +
    				"<style>table{table-layout: fixed; }</style>");
   		 out.println("<body style=background-COLOR:#F0F0F0>");
		
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
		
			String query="Select* from emp";
			if(!(id.isEmpty()))
			{
				query=query+" where empid='"+id+"'";
			}
			else if(!(fname.isEmpty()))
			{
				query=query+" where fname='"+fname+"'";	
			}
			else if(!(lname.isEmpty()))
			{
				query=query+" where lname='"+lname+"'";		
			}
			else if(!(day.isEmpty() && mon.isEmpty() && year.isEmpty()))
			{
				query=query+" where hiredate='"+year+"-"+mon+"-"+day+"'";
			}
			else if(!(sal.isEmpty()))
			{
				query=query+" where sal='"+sal+"'";
			}
			else if(!(address.isEmpty()))
			{
				query=query+" where address='"+address+"'";
			}
			else if(!(city.isEmpty()))
			{
				query=query+" where city='"+city+"'";
			}
			else if(!(dept==null))
			{
				
				query=query+ " where hdept='"+dept+"'";
			}
			else if(!(cat==null))
			{
				query=query+ " where cat='"+cat+"'";
			}
			
			
						
			ResultSet rs = st.executeQuery( query );
			
			
			 
		boolean flag=true;
		boolean dis=true;
		
		while(rs.next()){
			flag=false;
			if(dis)
			{	
				out.println("<h1 style=color:0093b8;>Record found:-</h1>");
			}
			
		 id = rs.getString(1);
		 fname = rs.getString(2);
		 lname = rs.getString(3);
		 String hiredate = rs.getString(4);
		 sal = rs.getString(5);
		 address = rs.getString(6);
		 city = rs.getString(7);
		 dept = rs.getString(8);
		 cat = rs.getString(9);

		 if(dis)
    	 {
			 out.println("<table border=1 width=700 align=center><tr><td><h4 style=display:inline>Id</h4></td><td><h4 style=display:inline>Name</h4></td>" +
    	 
    	 		"<td><h4 style=display:inline>HireDate</h4></td><td><h4 style=display:inline>Salary</h4></td>" +
    	 		"<td><h4 style=display:inline>Address</h4></td>" +
    	 		"<td><h4 style=display:inline>City</h4></td>" +
    	 		"<td><h4 style=display:inline>Department</h4></td>"+
    	 		"<td><h4 style=display:inline>Category</h4></td></tr>");
			 
    	 }
		 dis=false;
    	 
	    out.println("<tr><td>"+id+ "</td><td>"+fname+" "+lname+"</td><td>"+hiredate+ "</td>" +
	    		"<td>"+sal+ "</td><td>"+address+ "</td><td>"+city+ "</td><td>"+dept+ "</td>" +
	    				"<td>"+cat+ "</td></tr>");
	   
	  }
		if(flag)
		{
			out.println("<h1 style=color:0093b8;text-align:center>No Record found.</h1>");
	    }
     
    


out.println("</table></body></html>");

		
		}
		catch(Exception ex)
		{
			System.out.println("Exception :" + ex.getMessage());
			ex.getStackTrace();
		}
	}
}
