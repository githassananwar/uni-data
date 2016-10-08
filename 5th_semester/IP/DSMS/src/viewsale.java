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
@WebServlet("/viewsale")
public class viewsale extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	public viewsale()
	{
		super();
	}
	
	protected void doPost(HttpServletRequest request , HttpServletResponse response) throws ServletException , IOException
	{

		String id = request.getParameter("id");
		
		
		String day = request.getParameter("day");
		String mon = request.getParameter("mon");
		String year = request.getParameter("year");

		String day1 = request.getParameter("day1");
		String mon1 = request.getParameter("mon1");
		String year1 = request.getParameter("year1");

		String day2 = request.getParameter("day2");
		String mon2 = request.getParameter("mon2");
		String year2 = request.getParameter("year2");
		
		
		PrintWriter out = response.getWriter();
		
		

		 out.println("<html>");
    		out.println("<head><title>View Sale</title></head>" +
    				"<style>table{table-layout: fixed; }</style>");
   		 out.println("<body style=background-COLOR:#F0F0F0>");
		
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
		
			String query="Select s.saledate, s.saleamount, p.dname from sales s, pos p where p.posid=s.posid";
			if(!(id.isEmpty()))
			{
				query=query+" and s.posid="+id;
				if(!(day.isEmpty() && mon.isEmpty() && year.isEmpty()))
				{
					query=query+" and s.saledate='"+year+"-"+mon+"-"+day+"'";
				}
				else if(!(day1.isEmpty() && mon1.isEmpty() && year1.isEmpty()))
				{
					query=query+" and s.saledate between '"+year1+"-"+mon1+"-"+day1+"'";
					if(!(day2.isEmpty() && mon2.isEmpty() && year2.isEmpty()))
					{
						query=query+" and '"+year2+"-"+mon2+"-"+day2+"'";
					}
					
				}
			}
			
			
			ResultSet rs = st.executeQuery( query );
			
			 String date ="";
			 String amount = "";
			 String posid ="";
			
		boolean flag=true;
		boolean dis=true;
		
		
		while(rs.next()){
			flag=false;
			if(dis)
			{	
				out.println("<h1 style=color:0093b8;>Record found:-</h1>");
			}
			
			date = rs.getString(1);
			amount = rs.getString(2);
			posid = rs.getString(3);
	

		 if(dis)
    	 {
			 out.println("<table border=1 width=700 align=center><tr><td><h4 style=display:inline>SaleDate</h4></td><td><h4 style=display:inline>SaleAmount</h4></td>" +
    	 		"<td><h4 style=display:inline>POS Department</h4></td></tr>");
			 
    	 }
		 dis=false;
		 out.println("<tr><td>"+date+ "</td><td>"+amount+"</td><td>"+posid+"</td></tr>");
	
		 
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
