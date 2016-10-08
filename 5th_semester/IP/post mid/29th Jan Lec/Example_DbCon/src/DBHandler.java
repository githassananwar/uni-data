

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import test.DBConnectivity;
import test.Student;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.mysql.jdbc.PreparedStatement;

@WebServlet("/DBHandler")
public class DBHandler extends HttpServlet {
	private static final long serialVersionUID = 1L;
   
    public DBHandler() {
        super();
     }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
        PrintWriter pw=response.getWriter();		
        DBConnectivity  obj=new DBConnectivity();
        if(request.getParameter("add")!=null && request.getParameter("show")==null)
        {
        	/*this means add button was pressed*/
	        int res= obj.AddStudent(Integer.parseInt(request.getParameter("id")),request.getParameter("name"),Float.parseFloat(request.getParameter("gpa")));
	        response.sendRedirect("/Example4_DbCon/index.jsp?status="+res);
		    	        
	        /* if(res >0)
	        	pw.print("inserted");
	        else 
	        	pw.print("Sorry, could not insert");*/
	           
        }
        else
        {
        	ArrayList<Student> std=obj.GetAllStudent();   
        	
        	for(int i=0;i<std.size();i++)
        		pw.println(std.get(i).getID()+ " , " +std.get(i).getName() + " , "+std.get(i).getGPA() );
             
        	/* pw.println("<html><BODY BGCOLOR=\"#FDF5E6\">\n" +
       	 "<TABLE BORDER=1 ALIGN=CENTER>\n" + "<TR BGCOLOR=\"#FFAD00\">\n" +
           "<TH>ID <TH>NAME <TH> GPA");
       	
       	 for(int i=0;i<std.size();i++)
       	 {
       		 pw.println("<TR><TD>" +std.get(i).getID() + "</TD>");
       		 pw.println("<TD>" +std.get(i).getName() + "</TD>");
       		 pw.println("<TD>" +std.get(i).getGPA() + "</TD> </TR>");
        	 }
       	 pw.println("</TABLE>\n</BODY></HTML>");
       	 */
        }
	
	}

	
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}
	
	

}
