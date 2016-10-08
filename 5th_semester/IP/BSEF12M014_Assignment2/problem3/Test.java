package problem3;
import java.util.*;

class Test
{

public static void main(String [] args)
{
	Rectangle r=new Rectangle(6,6);
	Circle c=new Circle(6);
	System.out.println("Rectangle Parameter: "+r.getParameter());	
	System.out.println("Circle Circumference: "+c.getCircumference()+"\n");
	
	Shape s1=new Rectangle(2,3);
	Shape s2=new Circle(2);
	Shape s3=new Rectangle(2,3);
	Shape [] arrayOfShapes={s1,s2,s3};

	for(int i=0;i<arrayOfShapes.length;i++)
	{
		System.out.println(arrayOfShapes[i].toString());
		System.out.println("Area: "+arrayOfShapes[i].area()+" unit square\n");	
	}

	System.out.println("\nRectangles Only:-");
	for(int i=0;i<arrayOfShapes.length;i++)
	{
		if("Rectangle".equals(arrayOfShapes[i].getName()) )
		{
			System.out.println(arrayOfShapes[i].toString());
		}
	}	

}


}