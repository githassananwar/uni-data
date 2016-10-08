package problem4;
import java.util.*;

public class Record
{
	private ArrayList<Vehicle> vehicles;
	private ArrayList<Driver> drivers;

	Record()
	{
		 vehicles=new ArrayList<>();
		 drivers=new ArrayList<>();
	}

	public void addVehicle()
	{
		
		Scanner obj=new Scanner(System.in);

		System.out.print("Enter number: ");
		String number=obj.nextLine();
		
		System.out.print("Enter type: ");
		String type=obj.nextLine();
		
		System.out.print("Enter capacity: ");
		int cap=obj.nextInt();

		Vehicle v=new Vehicle(number, type, cap);
		vehicles.add(v);
	}

	public void addDriver()
	{
		
		Scanner obj=new Scanner(System.in);	
	
		System.out.print("Enter ID: ");
		int id=obj.nextInt();
		
		obj.nextLine();
		System.out.print("Enter Name: ");
		String name=obj.nextLine();
		

		Driver d=new Driver(id,name);
		drivers.add(d);
	}

	public void removeVehicle()
	{
		Scanner obj=new Scanner(System.in);

		System.out.print("Enter Vehicle number: ");
		String number=obj.nextLine();

		for(int i=0; i<vehicles.size(); i++)
		{
			if(number.equals(vehicles.get(i).getNumber()))
			{	
	
				vehicles.get(i).unAssignDriverVehicle();
				vehicles.get(i).unAssignDriver();
				vehicles.remove(i);
			}
		}

	}

	public void removeDriver()
	{
		Scanner obj=new Scanner(System.in);

		System.out.print("Enter Driver name: ");
		String name=obj.nextLine();

		for(int i=0; i<drivers.size(); i++)
		{
			if(name.equals(drivers.get(i).getName()))
			{
				drivers.get(i).unAssignVehicleDriver();
				drivers.get(i).unAssignVehicle();
				drivers.remove(i);
			}
		}

	}

	public void assignDriver()
	{
		Scanner obj=new Scanner(System.in);

		boolean flagV=true, flagD=true;
		System.out.print("Enter Vehicle number: ");
		String number=obj.nextLine();

		for(int i=0; i<vehicles.size() && flagV; i++)
		{
			if(number.equals(vehicles.get(i).getNumber()))
			{
				System.out.print("Enter Driver Name to assign: ");
				String name=obj.nextLine();
				for(int j=0;j<drivers.size() && flagD;j++)
				{
					if(name.equals(drivers.get(j).getName()) && !(drivers.get(j).isDriverAssigned()))
					{
						vehicles.get(i).assignDriver(drivers.get(j));
						drivers.get(j).assignVehicle(vehicles.get(i));
						flagD=false;
					}			

				}
				if(flagD)
				{
					System.out.println("Error! Driver NOT found or already Assigned.");
				}
	
				flagV=false;

			}

		}
		if(flagV)
		{
			System.out.println("Vehicle NOT found.");
		}

	}

	
	public void unAssignDriver()
	{
		Scanner obj=new Scanner(System.in);
		
		boolean flag=true;
		System.out.print("Enter Vehicle number: ");
		String number=obj.nextLine();

		for(int i=0;i<vehicles.size() && flag;i++)
		{
			
			if(number.equals(vehicles.get(i).getNumber()))
			{
				vehicles.get(i).unAssignDriverVehicle();
				vehicles.get(i).unAssignDriver();
				flag=false;
			}			


		}
		if(flag)
		{
			System.out.println("Vehicle NOT found.");
		}

	}

	
	public void printAllVehicles()
	{
		for(int i=0;i<vehicles.size();i++)
		{
			vehicles.get(i).displayVehicle();
		}
		
	}
	
	public void printAllDrivers()
	{
		for(int i=0;i<drivers.size();i++)
		{
			drivers.get(i).displayDriver();
		}
	}
	

}
