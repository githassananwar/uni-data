package test;

public class Student 
{
	int id;
	String name;
	float gpa;
	
	public Student()
	{
		id=0;
		name=null;
		gpa=0.0f;
	}
	public int getID()
	{
		return id;		
	}
	public void setID(int sid)
	{
		id= sid;
	}
	public String getName()
	{
		return name;		
	}
	public void setName(String sname)
	{
		name= sname;
	}
	public float getGPA()
	{
		return gpa;		
	}
	public void setGPA(float sgpa)
	{
		gpa=sgpa;
	}
	
}
