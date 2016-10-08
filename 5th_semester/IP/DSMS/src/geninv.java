import java.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.*; 

import javax.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/geninv")
public class geninv extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	public geninv()
	{
		super();
	}
	
	protected void doPost(HttpServletRequest request , HttpServletResponse response) throws ServletException , IOException
	{

		PrintWriter out = response.getWriter();		
		
		 out.println("<html>");
    		out.println("<head><title>Invoice</title></head>" +
    				"<style>table{table-layout: fixed; }</style>");
   		 out.println("<body style=background-COLOR:#F0F0F0>");		

		
		String day = request.getParameter("day");
		String mon = request.getParameter("mon");
		String year = request.getParameter("year");
		String id = request.getParameter("id");
		String empid = request.getParameter("empid");
		String name="";
		String price="";

		Connection conn;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/shop", "root", "");
			Statement st = conn.createStatement();
			
			String query1="Select fname from emp where empid="+empid;
			out.println("<table width=700 border=1 align=center><tr><td><h4 style=display:inline;color:red>Date:-</h4></td><td colspan=2><h4 style=display:inline>"+day+"-"+mon+"-"+year+"</h4></td></tr>" +
    	 		"<tr><td><h4 style=display:inline;color:red>Invoice Id</h4></td><td colspan=2><h4 style=display:inline>"+id+"</h4></td></tr>");
			
			int total=0;
			String itemid="";
			String quantity="";
			ResultSet rs1=st.executeQuery( query1 );
			if(rs1.next())
			{
				out.println("<tr><td><h4 style=display:inline;color:red>Served by:</h4></td><td colspan=2><h4 style=display:inline>"+rs1.getString(1)+"</h4></td></tr>");
			}
			
			out.println("<tr><td colspan=3><h4 style=display:inline;color:red>Item/s Description:-</h4></td></tr>");
			out.println("<tr><td><h4 style=display:inline>Item</h4></td><td><h4 style=display:inline>Quantity</h4></td><td><h4 style=display:inline>Price</h4></td></tr>");
			
			int r=st.executeUpdate("insert into invoice (invid) values("+id+");");
			if(r==1)
			{
				for(int i=0;(request.getParameter("item"+Integer.toString(i+1))!="" && request.getParameter("qt"+Integer.toString(i+1))!="") &&  request.getParameter("item"+Integer.toString(i+1))!=null && request.getParameter("qt"+Integer.toString(i+1))!=null;i++)
				{
					itemid=request.getParameter("item"+Integer.toString(i+1));
					quantity=request.getParameter("qt"+Integer.toString(i+1));
					String query2="Select name, rprice from stock where stockid="+itemid;
					
					ResultSet rs2 = st.executeQuery( query2 );
					if(rs2.next())
					{
						name=rs2.getString(1);
						price=rs2.getString(2);
						out.println("<tr><td>"+name+"</td><td align=right>"+quantity+"</h4></td><td align=right>"+Integer.parseInt(price)*Integer.parseInt(quantity)+".00</td></tr>");
						total=total+(Integer.parseInt(price)*Integer.parseInt(quantity));
						st.executeUpdate("update stock set itemquantity=itemquantity-"+quantity+" where stockid="+itemid);
					}
					
					
				}
			}
		if(total>0)
		{
			String posid="";
			out.println("<tr><td><h4 style=display:inline;color:red>Total</h3></td><td colspan=2 align=right><h4 style=display:inline>"+Integer.toString(total)+".00</h4></td></tr>");
			ResultSet rp=st.executeQuery("select p.posid from emp e, pos p where e.empid="+empid+" and p.dname=e.hdept");
			if(rp.next())
			{
				posid=rp.getString(1);
			}
			int ri = st.executeUpdate("update invoice set invamount="+ Integer.toString(total)+", invdate='"+year+"-"+mon+"-"+day+"', empid="+empid+", posid="+posid+" where invid="+id);
			if(ri>0)
			{
				out.println("<tr><td align=left colspan=3><h4 style=display:inline;color:red>Invoice Recorded</h3></td></tr></table></body></html>");
				ResultSet rsale=st.executeQuery("select saledate from sales where saledate='"+year+"-"+mon+"-"+day+"'");
				if(rsale.next())
				{
					st.executeUpdate("update sales set saleamount=saleamount+"+Integer.toString(total)+" where saledate='"+year+"-"+mon+"-"+day+"' and posid="+posid);
				}
				else
				{
					st.executeUpdate("insert into sales (saledate,saleamount,posid) values('"+year+"-"+mon+"-"+day+"',"+Integer.toString(total)+","+posid+")");
				}
				
			}
		}
		
			
		}
		catch(Exception ex)
		{
			System.out.println("Exception :" + ex.getMessage());
			ex.getStackTrace();
		}
		
	}
}
