import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class DataServletExample extends HttpServlet
 {
	
   public DataServletExample() {
        super();
    }

protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
{
PrintWriter pw=response.getWriter();
pw.println("Hello, " + request.getParameter("fn") +" " + request.getParameter("ln"));
}

protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
 {
		
}

}
