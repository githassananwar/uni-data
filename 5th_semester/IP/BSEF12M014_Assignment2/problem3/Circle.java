package problem3;
import java.util.*;

public class Circle extends Shape
{

	public double radius;

	Circle()
	{
		radius=0;
	}
	
	Circle(int r)
	{
		radius=r;
	}
	
	public int getCircumference()
	{
		return (int)(2*3.14*radius);
	}

	public double area()
	{	
		return 3.14*radius*radius;
	}

	public String getName()
	{
		return "Circle";
	}

	public String toString()
    	{
    	    return ("Circle: Centre point: "+super.toString()+"    radius: "+radius);
    	}

}

