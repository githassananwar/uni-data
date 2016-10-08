package MyPack;

import javax.servlet.jsp.*; 
import javax.servlet.jsp.tagext.*; 

public class WelcomeTagHandler extends SimpleTagSupport{

public void doTag() throws JspException { 


PageContext pageContext = (PageContext)getJspContext();
JspWriter out = pageContext.getOut(); 
try { 

	out.println(" Hello World "); 

     } catch (java.io.IOException ex) 
	{} 

}
}

