import java.util.*;
class SearchChar
{

public static void main(String [] a)
{

int count=0;

Scanner obj=new Scanner(System.in);

System.out.println("Enter a Line of Text: ");
String input=obj.nextLine();

System.out.println("Enter the character you want to search: ");
char chReq=obj.next().charAt(0);

for(int i=0;i<input.length();i++)
{
	if(input.charAt(i)==chReq)
	{
		count=count+1;
	}
	
}

System.out.println(chReq+" occured "+count+" times in input text.");

}

}