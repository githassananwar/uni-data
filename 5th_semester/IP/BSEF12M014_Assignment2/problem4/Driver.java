package problem4;
import java.util.*;

public class Driver
{
	/*We will use Aggregation for this task as Vehicle and Driver is in a weak relationship i.e. if a vehicle is deleted,
driver that was assigned to it will exist and vice versa. */

	private int id;
	private String name;
	private Vehicle vehicleAssigned;
	

	Driver()
	{
		id=0;
		name=null;
		vehicleAssigned=null;
	
	}

	Driver(int id, String name)
	{
		this.id=id;
		this.name=name;
		this.vehicleAssigned=null;
	}

	Driver(int id, String name, Vehicle v)
	{
		this.id=id;
		this.name=name;
		this.vehicleAssigned=v;
	}

	public void displayDriver()
	{
		System.out.println("\nDRIVER INFO:-");
		System.out.println("Driver ID: "+id);
		System.out.println("Name: "+name);
		
		if(vehicleAssigned!=null)
		{
			System.out.println("Vehicle Assigned:-");
			vehicleAssigned.displayInfo();
		}
		else
		{
			System.out.println("Vehicle not Assigned");
		}

	}

	public void displayInfo()
	{
		System.out.println("Driver ID: "+id);
		System.out.println("Name: "+name);
	}

	public void assignVehicle(Vehicle v)
	{
		if(vehicleAssigned==null)
		{
			vehicleAssigned=v;
		}
		else
		{	
			System.out.println("Error! Vehicle is already Assigned.");
		}
	}

	public void unAssignVehicle()
	{
		vehicleAssigned=null;
	}

	public void unAssignVehicleDriver()
	{
		if(vehicleAssigned!=null)
		{
			vehicleAssigned.unAssignDriver();
		}	
	}

	public boolean isDriverAssigned()
	{
		if(vehicleAssigned!=null)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	public String getName()
	{
		return name;
	}	
	

}
