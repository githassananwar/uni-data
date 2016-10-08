package problem3;
import java.util.*;

public class Rectangle extends Shape
{

	public int height;
	public int width;
	
	Rectangle()
	{
		height=0;
		width=0;
	}
	
	Rectangle(int w, int h)
	{
		height=w;
		width=h;
	}
	
	public int getParameter()
	{
		return 2*(height+width);

	}

	public double area()
	{	
		return (double)height*width;
	}

	public String getName()
	{
		return "Rectangle";
	}

	public String toString()
    	{
    	    return ("Rectangle: Upper left corner: "+super.toString()+"    width: "+width+"       "+"height: "+height);
    	}

}
