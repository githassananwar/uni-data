import java.util.*;
class ShapeDrawer
{

public static void main(String [] a)
{

int height, width, size, choice;
ShapeDrawer s=new ShapeDrawer();

Scanner obj=new Scanner(System.in);

System.out.println("1 - Draw Filled Rectagle");
System.out.println("2 - Draw Empty Rectagle");
System.out.println("3 - Draw Left Triangle");
System.out.println("4 - Draw Right Triangle");
System.out.println("5 - Draw Triagle");
System.out.print("Select Choice: ");

choice=obj.nextInt();
while(choice<1 || choice>5)
{
	System.out.print("Invalid choice! Enter again: ");
	choice=obj.nextInt();
}

if(choice==1)
{
	System.out.print("Enter height: ");
	height=obj.nextInt();
	System.out.print("Enter width: ");
	width=obj.nextInt();
	s.DrawFilledrectagle (height, width);

}
else if(choice==2)
{
	System.out.print("Enter height: ");
	height=obj.nextInt();
	System.out.print("Enter width: ");
	width=obj.nextInt();
	s.DrawEmptyrectagle (height, width);

}
else if(choice==3)
{
	System.out.print("Enter height: ");
	height=obj.nextInt();
	s.DrawLeftTriangle (height);
	
}
else if(choice==4)
{
	System.out.print("Enter height: ");
	height=obj.nextInt();
	s.DrawRightTriangle (height); 
	

}
else if(choice==5)
{
	System.out.print("Enter height: ");
	height=obj.nextInt();
	s.DrawRTriangle (height);

}

}

void DrawFilledrectagle (int height, int width)
{
for(int i=0; i<height; i++)
{
	for(int j=0; j<width; j++)
	{
		System.out.print("*");
	}
	System.out.print("\n");		

}

}



void DrawEmptyrectagle (int height, int width)
{
for(int i=0; i<height; i++)
{
	for(int j=0; j<width; j++)
	{
		if(i==0 || i==height-1) 
		{
			System.out.print("*");
		}
		else
		{
			if(j==0 || j==width-1)
				System.out.print('*');
			else
				System.out.print(' ');
		}
	}
	System.out.print("\n");		

}

}


void DrawLeftTriangle (int size)
{
	int count=1;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<count;j++)
		{
			System.out.print('*');
		}
		count=count+1;
		System.out.print("\n");	
	}

}

void DrawRightTriangle (int size)
{
	int spCount=size-1;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(j<spCount)
				System.out.print(' ');
			else
				System.out.print('*');
		}
		
		spCount=spCount-1;
		System.out.print("\n");	
	}

}


void DrawRTriangle (int height )
{
	int rows=height*2-1;
    	int pntc=(rows/2)+1;
	int chk=0;

    	for(int countRow=1; countRow<=height; countRow++)
    	{
        	
        	for(int countCol=1; countCol<=rows; countCol++)
        	{

 			if(countCol>=pntc-chk && countCol<=pntc+chk)
            		{
                		System.out.print("*");
		        }
        		else
            		{
                		System.out.print(" ");

		        }
            		

		}
		chk=chk+1;
		System.out.print("\n");

	}

}



}