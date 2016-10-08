

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class requestHeaders
 */
@WebServlet("/requestHeaders")
public class requestHeaders extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public requestHeaders() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		  PrintWriter out = response.getWriter();
		    String title = "Servlet Example: Showing Request Headers";
		    out.println("<html><BODY BGCOLOR=\"#FDF5E6\">\n" +
		                "<H1 ALIGN=CENTER>" + title + "</H1>\n" +
		                "<B>Request Method: </B>" +
		                request.getMethod() + "<BR>\n" +
		                "<B>Request Protocol: </B>" +
		                request.getProtocol() + "<BR><BR>\n" +
		                "<TABLE BORDER=1 ALIGN=CENTER>\n" +
		                "<TR BGCOLOR=\"#FFAD00\">\n" +
		                "<TH>Header Name<TH>Header Value");
		    Enumeration headerNames = request.getHeaderNames();
		    while(headerNames.hasMoreElements()) {
		      String headerName = (String)headerNames.nextElement();
		      out.println("<TR><TD>" + headerName);
		      out.println("    <TD>" + request.getHeader(headerName));
		    }
		    out.println("</TABLE>\n</BODY></HTML>");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
