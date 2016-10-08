
import DAO.Book;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


/**
 * Servlet implementation class shoppingServlet
 */
@WebServlet("/shoppingServlet")
public class shoppingServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public shoppingServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		HttpSession s=request.getSession();
		
		Book bookObj=getBook(request);
		ArrayList<Book> lst;
		PrintWriter pw=response.getWriter();
		
		if(s.getAttribute("selectedbooks")==null)
		{	
			lst=new ArrayList<Book>();
			lst.add(bookObj);
			s.setAttribute("selectedbooks", lst);
		
		}
		else
		{
			lst=(ArrayList<Book>) s.getAttribute("selectedbooks");
			boolean matched=false;
		    for(int i=0;i<lst.size();i++)
		    {
		    	pw.println("i="+i+"lst.get(i).getTitle() = "+ lst.get(i).getTitle() +",bookObj.getQuantity() =" +bookObj.getQuantity());
		    	if(lst.get(i).getTitle().equals(bookObj.getTitle()))
		    	{
		    		lst.get(i).setQuantity(lst.get(i).getQuantity() + bookObj.getQuantity());
		    		matched=true;
		    		break;
		    	}
		    }
		    if(!matched)
		    	lst.add(bookObj);
			s.setAttribute("selectedbooks", lst);
		}
		
		response.sendRedirect("index.jsp");
		
			
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
	private Book getBook(HttpServletRequest req) {
		
		String myBook = req.getParameter("book");
		String qty = req.getParameter("qty");
		
		StringTokenizer t = new StringTokenizer(myBook,"|");
		String title = t.nextToken();
		String author = t.nextToken();
		String price = t.nextToken();
		price = price.replace('$',' ').trim();
		
		Book book = new Book();
		book.setTitle(title);
		book.setAuthor(author);
		book.setPrice((new Float(price)).floatValue());
		book.setQuantity((new Integer(qty)).intValue());
		
		return book;
	}

}
