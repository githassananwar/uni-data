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
import javax.servlet.http.HttpSession;
@WebServlet("/upemp")
public class upemp extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	public upemp()
	{
		super();
	}
	
	protected void doPost(HttpServletRequest request , HttpServletResponse response) throws ServletException , IOException
	{
	HttpSession s=request.getSession();
	String id = request.getParameter("id");
		String cat=request.getParameter("up");
	s.setAttribute("id", id);
	s.setAttribute("cat", cat);
	
	response.sendRedirect("updateempn.jsp");

	}
	
		
}
