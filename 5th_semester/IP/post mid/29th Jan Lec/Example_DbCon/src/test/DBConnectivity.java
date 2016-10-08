package test;
import java.sql.*;
import java.util.ArrayList;

public class DBConnectivity {

	Connection con;
	Statement stmt;
	PreparedStatement pstmt;
	
	public DBConnectivity() {
		establishConnection();
		createStatement();
	}
	
	void establishConnection()
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			con= DriverManager.getConnection("jdbc:mysql://localhost/cms","root","");
		}
		catch(Exception e)
	    {
			e.printStackTrace();
	    }
	}
	void createStatement()
	{
		try
		{
		stmt= con.createStatement();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}		
	}
	
		
	public int AddStudent(int id, String n, float gpa)
	{
		int val=0;
		try
		{
		pstmt = con.prepareStatement("insert into student(id,name,gpa) values (?,?,?)");
		pstmt.setInt(1, id);
		pstmt.setString(2, n);
		pstmt.setFloat(3, gpa);
		val=pstmt.executeUpdate();
		}
		catch(SQLException e)
		{}
			return val;
	}
	int updateStudentById(int id, String n, float gpa)
	{
		int val=0;
		try
		{
		pstmt = con.prepareStatement("update student set name=?, gpa=? where id=?");
		pstmt.setInt(3, id);
		pstmt.setString(1, n);
		pstmt.setFloat(2, gpa);
		val=pstmt.executeUpdate();
		}
		catch(SQLException e)
		{}
			return val;
			
	}
	int deleteStudentById(int id)
	{

		int val=0;
		try
		{
		pstmt = con.prepareStatement("delete from student where id=?");
		pstmt.setInt(1, id);val=pstmt.executeUpdate();
	}
	catch(SQLException e)
	{}
		return val;
			
	}
	
	public boolean VerifyLogin(String id, String name)
	{
	
		boolean flag=false;
        
		try
		{
			
        ResultSet rs=stmt.executeQuery("select * from student");
		while(rs.next())
		{   
			if(rs.getString(1).equals(id) && rs.getString(2).equals(name))
			{
				flag=true;
				break;
			}
		
         }
		}
        catch(Exception e)
		{e.printStackTrace();
		}
		return flag;
	}

	public ArrayList<Student> GetAllStudent()
	{
		ArrayList<Student> lstStudents=new ArrayList<Student>();
		Student s;
		try
		{
	              
        ResultSet rs=stmt.executeQuery("select * from student");
		while(rs.next())
		{   
			s=new Student();
			s.setID(Integer.parseInt(rs.getString(1)));
			s.setName(rs.getString(2));
			s.setGPA(Float.parseFloat(rs.getString(3)));
			lstStudents.add(s);
         }
		}
        catch(Exception e)
		{e.printStackTrace();
		}
		return lstStudents;
	}

}
