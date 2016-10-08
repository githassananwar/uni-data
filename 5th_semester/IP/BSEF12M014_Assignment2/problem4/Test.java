package problem4;
import java.util.*;

public class Test
{
	public static void main(String[] args) 
	{
		Record r=new Record();
		int choice=0;
	
		System.out.print("-------------------------------VEHICLE COMPANY-------------------------------\n");
		Scanner obj=new Scanner(System.in);
	
		while(choice!=9)
		{

			System.out.println("\n1 - Add Vehicle");
			System.out.println("2 - Add Driver");
			System.out.println("3 - Assign Driver");
			System.out.println("4 - Unassign Driver");
			System.out.println("5 - Remove Vehicle");
			System.out.println("6 - Remove Driver");
			System.out.println("7 - Display All Vehicles");
			System.out.println("8 - Display All Drivers");
			System.out.println("9 - Exit");
	
			System.out.print("Select Choice: ");

			choice=obj.nextInt();
			while(choice<1 || choice>9)
			{
				System.out.print("Invalid choice! Enter again: ");
				choice=obj.nextInt();
			}

			if(choice==1)
			{
				r.addVehicle();
			}
			else if(choice==2)
			{
				r.addDriver();

			}
			else if(choice==3)
			{
				r.assignDriver();
	
			}
			else if(choice==4)
			{
				r.unAssignDriver();
			}
			else if(choice==5)
			{
				r.removeVehicle();
			}
			else if(choice==6)
			{
				r.removeDriver();
			}
			else if(choice==7)
			{
				r.printAllVehicles();
			}
			else if(choice==8)
			{
				r.printAllDrivers();
			}
	
		}

	}

}
