package MyPack;


import javax.servlet.jsp.tagext.*;
import javax.servlet.jsp.*;
import java.util.*; 

public class MyTagHandler extends SimpleTagSupport { 

private String companyName; 


/** 
* setter method to get the attribute value 
*/
public void setcompanyName(String value){
this.companyName = value;
} 


public void doTag() throws JspException { 

MobileDAO mobile = new MobileDAO(); 
ArrayList mobileList = mobile.retrieveMobileList(companyName); 
display(mobileList); 
} 


private void display(ArrayList mobileList)throws JspException{ 
PageContext pc = (PageContext)getJspContext(); 
JspWriter out = pc.getOut(); 

try{ 

out.print("<TABLE BORDER=1 >"); 
out.print("<TR>"); 
out.print("<TH> Company Name </TH>"); 
out.print("<TH> Model </TH>"); 
out.print("<TH> Price </TH>"); 
out.print("</TR>"); 


// loop to iterate over mobileList 

for (int i=0; i<mobileList.size(); i++){ 
MobileBean MBean = (MobileBean)mobileList.get(i); 

// displaying one row 

out.print("<TR>"); 
out.print("<TD>" + MBean.getCompany() + "</TD>"); 
out.print("<TD>" + MBean.getModel() + "</TD>"); 
out.print("<TD>" + MBean.getPrice() + "</TD>"); 
out.print("</TR>"); 

} 

out.print("</TABLE>"); 

}catch(java.io.IOException ex)
{throw new JspException(ex.getMessage());}

} 
} 
