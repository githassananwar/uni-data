import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class Second extends HttpServlet{
 public void doGet(HttpServletRequest req,HttpServletResponse res)
            throws ServletException,IOException
 {
   String key = (String)req.getAttribute("key");
	 
   String name = req.getParameter("fname");

   PrintWriter out = res.getWriter();

  out.println("<html><body>Output generated by second servlet. <br>"); 
  out.println("Name obtained from HTML is " +name+"<br>");
  out.println("Name obtained from first servlet is " +key+ "<br><body></html>");
 }
}