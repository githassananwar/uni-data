import java.util.*;

class Program1
{

public static void main(String[] args) 
{
	int n, sum=0;
	double average=0;
	
	Scanner obj=new Scanner(System.in);
	Random rand = new Random();

	System.out.print("Enter Array size: ");
	n=obj.nextInt();

	int[] arr=new int[n];

	for(int i=0;i<n;i++)
	{
		arr[i]=rand.nextInt((90 - 10) + 1) + 10;
		sum=sum+arr[i];
	}
	

	average=sum/(double)n;
	System.out.println("Average: "+average);
	
	ArrayList<Integer> elementAbove = new ArrayList<>();
	ArrayList<Integer> elementBelow = new ArrayList<>();
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>average)
		{
			elementAbove.add(arr[i]);
		}
		else
		{
			elementBelow.add(arr[i]);
		}
	}
	
	System.out.print("Elements above Average: ");
	for(int i=0;i<elementAbove.size();i++)
	{
		System.out.print(elementAbove.get(i)+"  ");
	}

	System.out.print("\nElements below Average: ");
	for(int i=0;i<elementBelow.size();i++)
	{
		System.out.print(elementBelow.get(i)+"  ");
	}


}


}

class Program2
{

public static void main(String[] args) 
{	
	

	ArrayList<String> nameA = new ArrayList<>();
	ArrayList<String> nameB = new ArrayList<>();

	String  names[]={"Babar","Adil","Anjum","Baqir","Basit","Bilal","Ahmad","Badar" ,"Adnan", "Anwar", "Bari"};
	
	for(int i=0;i<names.length;i++)
	{
		if(names[i].charAt(0)=='A')
		{
			nameA.add(names[i]);
		}
		else
		{
			nameB.add(names[i]);
		}
	}

	System.out.print("Names starting with 'A': ");
	for(int i=0;i<nameA.size();i++)
	{
		System.out.print(nameA.get(i)+"  ");
	}
	
	System.out.print("\nNames starting with 'B': ");
	for(int i=0;i<nameB.size();i++)
	{
		System.out.print(nameB.get(i)+"  ");
	}


}




}


