

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class loginServ
 */
@WebServlet("/loginServ")
public class loginServ extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public loginServ() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		HttpSession session=request.getSession();
		
		String btnlogin= request.getParameter("btnlogin");
		String btnlogout= request.getParameter("btnlogout");
		
		if(btnlogin!=null && btnlogout==null)
		{
			String username = request.getParameter("username");
			String password = request.getParameter("password");
			//User user = userDAO.find(username, password);
			if (username.equals("user") && password.equals("123"))
			{
			    session.setAttribute("user", username);
			    response.sendRedirect("index.jsp");
			} else {
			    request.setAttribute("error", "Unknown username/password combo, please try again");
			    request.getRequestDispatcher("/login.jsp").forward(request, response);
			}
		}
		else
		{
			session.removeAttribute("user");
			 response.sendRedirect("login.jsp");
			
		}
		
		
	}

}
