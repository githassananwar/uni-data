import java.util.*;


class Test
{

public static void main(String[] args) 
{
	AddressBook ad= new AddressBook();
	int choice=0;
	
	System.out.print("-------------------------------ADDRESS BOOK-------------------------------\n");
	Scanner obj=new Scanner(System.in);
	
	while(choice!=4)
	{

	System.out.println("\n1 - Add Person");
	System.out.println("2 - Delete Person");
	System.out.println("3 - Search Person");
	System.out.println("4 - Exit");
	System.out.print("Select Choice: ");

	choice=obj.nextInt();
	while(choice<1 || choice>4)
	{
		System.out.print("Invalid choice! Enter again: ");
		choice=obj.nextInt();
	}

	if(choice==1)
	{
		ad.addPerson();
	}
	else if(choice==2)
	{
		System.out.print("Enter name to be deleted: ");
		obj.nextLine();
		String name=obj.nextLine();
		ad.deletePerson(name);	

	}
	else if(choice==3)
	{
		System.out.print("Enter name to be searched: ");
		obj.nextLine();
		String name=obj.nextLine();
		ad.searchPerson(name);	
	
	}

	}
	
}


}

class PersonInfo
{
	private String name; 
	private String address;
	private String phoneNumber;
	

	PersonInfo()
	{
		name=null;
		address=null;
		phoneNumber=null;
			
	}

	PersonInfo(String name, String address, String phoneNumber)
	{
		this.name=name;
		this.address=address;
		this.phoneNumber=phoneNumber;
	}	
	
	public void displayInfo()
	{
		System.out.println("Person Info:-");
		System.out.println("Name: "+name);
		System.out.println("Address: "+address);
		System.out.println("Contact number: "+phoneNumber);		
	}

	public String getName()
	{
		return name;
	}




}


class AddressBook
{
	private ArrayList<PersonInfo> person;
	
	AddressBook()
	{
		person=new ArrayList<>();
	}
		
	public void addPerson()
	{
		Scanner obj=new Scanner(System.in);
		
		System.out.print("Enter Name: ");
		String name=obj.nextLine();
		
		System.out.print("Enter Address: ");
		String add=obj.nextLine();
		
		System.out.print("Enter Contact Number: ");
		String phone=obj.nextLine();

		PersonInfo p=new PersonInfo(name,add,phone);
		person.add(p);		
		
		
	}
	
	public void deletePerson(String name)
	{
		boolean flag=true;
		for(int i=0;i<person.size() && flag; i++)
		{
			if(name.equals(person.get(i).getName()))
			{
				person.remove(i);
				flag=false;
			}	
				
		}
		if(flag)
		{
			System.out.println("Person NOT found.");

		}
	}

	public void searchPerson(String name)
	{
		boolean flag=true;
		for(int i=0;i<person.size() && flag;i++)
		{
			if(name.equals(person.get(i).getName()) )
			{
				person.get(i).displayInfo();
				flag=false;
			}
				
		}
		
		if(flag)
		{
			System.out.println("Person NOT found.");
		}
		
	}


}