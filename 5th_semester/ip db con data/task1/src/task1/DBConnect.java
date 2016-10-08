package task1;
import java.sql.*;
import java.util.*;

public class DBConnect {

	 static final String DB_URL = "jdbc:mysql://localhost/test";
	 static final String USER = "root";
	 static final String PASS = "";
	 
	 public static void main(String[] args) {
	 Connection conn = null;
	 Statement stmt = null;
	 try{
	    //STEP 2: Register JDBC driver
	    Class.forName("com.mysql.jdbc.Driver");
	    

	    //STEP 3: Open a connection
	    System.out.println("Connecting to a selected database...");
	    conn = DriverManager.getConnection(DB_URL, USER, PASS);
	    System.out.println("Connected database successfully...");
	    
	    //STEP 4: Execute a query
	    System.out.println("Creating statement...");
	    stmt = conn.createStatement();
	    String sql = "SELECT id, name FROM  Student";
	    ResultSet rs = stmt.executeQuery(sql);
	    //STEP 5: Extract data from result set
	    while(rs.next()){
	       //Retrieve by column name
	       int id  = rs.getInt("Id");
	       String name = rs.getString("Name");

	       //Display values
	       System.out.print("ID: " + id);
	       System.out.println(", name: " + name);
	    }
	    rs.close();
	 }catch(SQLException se){
	    //Handle errors for JDBC
	    se.printStackTrace();
	 }catch(Exception e){
	    //Handle errors for Class.forName
	    e.printStackTrace();
	 }finally{
	    //finally block used to close resources
	    try{
	       if(conn!=null)
	          conn.close();
	    }
	    catch(SQLException se)
	    {
	       se.printStackTrace();
	    }
	 }
	 System.out.println("Goodbye!");
	}

}

