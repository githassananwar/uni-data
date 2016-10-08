import java.util.*;

//--------------------------------------------------p-1-------------------------------------------------

class Factorial
{

public static void main(String [] a)
{
int num;
int fac=1;
Scanner obj=new Scanner(System.in);
System.out.println("Enter your number: ");
num=obj.nextInt();
while(num<0)
{
System.out.println("Invalid number. Enter again: ");
num=obj.nextInt();
}

for(int i=1;i<=num;i++)
{
	fac=fac*i;
}

System.out.println("Factorial of "+num+": "+fac);

}

}

//--------------------------------------------------p-2-------------------------------------------------

class DisplayDigit
{

public static void main(String [] a)
{

DisplayDigit d=new DisplayDigit();

int num;
int x, digitCount=0;
int reverse=0;

Scanner obj=new Scanner(System.in);
System.out.println("Enter six-digit number: ");
num=obj.nextInt();

x=num;
while(x!=0)
{
	x=x/10;
	digitCount=digitCount+1;
}

while(digitCount!=6)
{
	System.out.println("Invalid number! Enter a six-digit number: ");
	num=obj.nextInt();

	x=num;
	digitCount=0;

	while(x!=0)
	{
		x=x/10;
		digitCount=digitCount+1;
	}

}

d.seperateDigit(num);

}

public void seperateDigit(int num)
{	
	if(num==0)
	{
		return;
	}

	seperateDigit(num/10);
	System.out.print(num%10+"   ");

}

}


//--------------------------------------------------p-3-------------------------------------------------

class CalculateDay
{

public static void main(String [] a)
{
int numOfDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
int month, day, dayInYear=0;

Scanner obj=new Scanner(System.in);

System.out.print("Enter Month: ");
month=obj.nextInt();
System.out.print("Enter Day: ");
day=obj.nextInt();

for(int i=0;i<month-1;i++)
{
	dayInYear=dayInYear+numOfDays[i];

}

dayInYear=dayInYear+day;
System.out.println("The day number for "+day+"-"+month+" is "+dayInYear);

}

}






