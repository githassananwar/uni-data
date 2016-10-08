package problem4;
import java.util.*;

public class Vehicle
{
	/*We will use Aggregation for this task as Vehicle and Driver is in a weak relationship i.e. if a vehicle is deleted,
driver that was assigned to it will exist and vice versa. */
	
	private String number;
	private String type;
	private int capacity;
	Driver driverAssigned;

	Vehicle()
	{
		number=null;
		type=null;
		capacity=0;
		driverAssigned=null;
	}
	
	Vehicle(String num, String type, int cap)
	{
		this.number=num;
		this.type=type;
		this.capacity=cap;
		this.driverAssigned=null;
	}

	Vehicle(String num, String type, int cap, Driver d)
	{
		this.number=num;
		this.type=type;
		this.capacity=cap;
		this.driverAssigned=d;
	}	

	public void displayVehicle()
	{
		System.out.println("\nVEHICLE INFO:-");
		System.out.println("Vehicle Number: "+number);
		System.out.println("Vehicle Type: "+type);
		System.out.println("Vehicle Capacity: "+capacity);
		
		if(driverAssigned!=null)
		{
			System.out.println("Driver Assigned:-");
			driverAssigned.displayInfo();
		}
		else
		{
			System.out.println("Driver not Assigned");
		}

	}

	public void displayInfo()
	{
		System.out.println("Vehicle Number: "+number);
		System.out.println("Vehicle Type: "+type);
	}

	public void assignDriver(Driver d)
	{
		if(driverAssigned==null)
		{	
			driverAssigned=d;
		}
		else
		{	
			System.out.println("Error! Driver is already Assigned.");
		}
	}

	public void unAssignDriver()
	{	
		driverAssigned=null;
	}

	public void unAssignDriverVehicle()
	{
		if(driverAssigned!=null)
		{
			driverAssigned.unAssignVehicle();
		}	
	}

	public String getNumber()
	{
		return number;
	}
	

}
