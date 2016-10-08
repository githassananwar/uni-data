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
@WebServlet("/viewstock")
public class viewstock extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	public viewstock()
	{
		super();
	}
	
	protected void doPost(HttpServletRequest request , HttpServletResponse response) throws ServletException , IOException
	{

		String id = request.getParameter("id");
		String name = request.getParameter("name");
		String price = request.getParameter("price");
		String quantity = request.getParameter("quantity");
		String dept =request.getParameter("dp");
		
		
		
		PrintWriter out = response.getWriter();
		
		

		 out.println("<html>");
    		out.println("<head><title>View Stock</title></head>" +
    				"<style>table{table-layout: fixed; }</style>");
   		 out.println("<body style=background-COLOR:#F0F0F0>");
		
		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
		
			String query="Select stockid,name,wprice,itemquantity,dname from stock";
			if(!(id.isEmpty()))
			{
				query=query+" where stockid="+id;
			}
			else if(!(name.isEmpty()))
			{
				query=query+" where name='"+name+"'";	
			}
			else if(!(price.isEmpty()))
			{
				query=query+" where rprice="+price;		
			}
			else if(!(quantity.isEmpty()))
			{
				query=query+" where itemquantity="+quantity;
			}
			else if(!(dept==null))
			{
				
				query=query+ " where dname='"+dept+"'";
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
		name = rs.getString(2);
		 price = rs.getString(3);
		quantity = rs.getString(4);
		 dept =rs.getString(5);

		 if(dis)
    	 {
			 out.println("<table border=1 width=700 align=center><tr>" +
    	 		"<td><h4 style=display:inline>Stock ID</h4></td><td><h4 style=display:inline>StockName</h4></td>" +
    	 		"<td><h4 style=display:inline>StockPrice</h4></td>" +
    	 		"<td><h4 style=display:inline>StockQuantity</h4></td>" +
    	 		"<td><h4 style=display:inline>StockDepartment</h4></td></tr>");
			 
    	 }
		 dis=false;
    	 
	    out.println("<tr><td>"+id+ "</td><td>"+name+ "</td>" +
	    		"<td>"+price+ "</td><td>"+quantity+ "</td><td>"+dept+ "</td></tr>");
	   
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
