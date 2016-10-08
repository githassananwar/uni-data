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
@WebServlet("/viewinv")
public class viewinv extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	public viewinv()
	{
		super();
	}
	
	protected void doPost(HttpServletRequest request , HttpServletResponse response) throws ServletException , IOException
	{

		String invid = request.getParameter("invid");
		String invamount = request.getParameter("invamount");
		String empid = request.getParameter("empid");
		String posid = request.getParameter("posid");
		
		String day = request.getParameter("day");
		String mon = request.getParameter("mon");
		String year = request.getParameter("year");

		
		
		
		PrintWriter out = response.getWriter();
		
		

		 out.println("<html>");
    		out.println("<head><title>View Invoice</title></head>" +
    				"<style>table{table-layout: fixed; }</style>");
   		 out.println("<body style=background-COLOR:#F0F0F0>");
		
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
		
			String query="Select i.invid, i.invdate,i.invamount,i.empid,p.dname from invoice i, pos p where p.posid=i.posid";
			if(!(invid.isEmpty()))
			{
				query=query+" and i.invid="+invid;
				
			}
			else if(!(day.isEmpty() && mon.isEmpty() && year.isEmpty()))
			{
				query=query+" and i.invdate='"+year+"-"+mon+"-"+day+"'";
			}
			else if(!(invamount.isEmpty()))
			{
				query=query+" and i.invamount="+invamount;
				
			}
			else if(!(empid.isEmpty()))
			{
				query=query+" and i.empid="+empid;
				
			}
			else if(!(posid.isEmpty()))
			{
				query=query+" and i.posid="+posid;
				
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
			
			invid = rs.getString(1);
			String invdate = rs.getString(2);
			invamount = rs.getString(3);
			empid=rs.getString(4);
			posid=rs.getString(5);


	

		 if(dis)
    	 {
			 out.println("<table border=1 width=700 align=center><tr><td><h4 style=display:inline>Invoice ID</h4></td><td><h4 style=display:inline>Invoice Date</h4></td>" +
    	 		"<td><h4 style=display:inline>Invoice Amount</h4></td><td><h4 style=display:inline>Employee ID</h4></td><td><h4 style=display:inline>POS Department</h4></td></tr>");
			 
    	 }
		 dis=false;
		 out.println("<tr><td>"+invid+ "</td><td>"+invdate+"</td><td>"+invamount+"</td><td>"+empid+"</td><td>"+posid+"</td></tr>");
	
		 
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
