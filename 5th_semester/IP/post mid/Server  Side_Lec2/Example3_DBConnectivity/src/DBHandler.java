

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
/**
 * Servlet implementation class DBHandler
 */
@WebServlet("/DBHandler")
public class DBHandler extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DBHandler() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter pw=response.getWriter();
		
		try
		{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost/cms","root","");
		Statement st=con.createStatement();
               
        	ResultSet rs=st.executeQuery("select * from student");
		while(rs.next())
		{       pw.print(rs.getString(1)+ ", ");
			pw.print(rs.getString(2)+ ", ");
			pw.print(rs.getString(3)+",");
                        pw.println(rs.getString(4));	
                }
		}
                catch(ClassNotFoundException ex)
		{
			pw.println("class not found");
			
		}
		catch(Exception e)
		{
			System.out.println("Exception: " + e.getMessage());
                        e.getStackTrace();
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
