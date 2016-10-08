import java.sql.*;

public class std {
 
 static final String DB_URL = "jdbc:mysql://localhost/librarydb";
 static final String USER = "root";
 static final String PASS = "";
 
 public static void displayAllAuthors()
 {
	 
	 try{
	 String query = "select FirstName from Authors order by firstname;" ;
	Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
	Statement stmt = con.createStatement() ;
	ResultSet rs = stmt.executeQuery(query) ;
	
	while(rs.next()){
	       //Retrieve by column name
	       
	       String name = rs.getString("FirstName");

	       //Display values
	       
	       System.out.println(", name: " + name);
	    }
	rs.close();
	 }
	 
	 catch (Exception e)
	 {
		 System.out.println("EXCEPTION in displayAllAuthors!");
		 e.printStackTrace();
	 }
	 finally
	 {
		 
	 }
 }
 public static void GetBooksbyAuthorID(int AuthorID)
 {
	 
	 try{
	 String query = "select bookTitle from books where AuthorID = "+ AuthorID + ";" ;
	Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
	Statement stmt = con.createStatement() ;
	ResultSet rs = stmt.executeQuery(query) ;
	
	while(rs.next()){
	       //Retrieve by column name
	       
	       String name = rs.getString("bookTitle");

	       //Display values
	       
	       System.out.println(", book : " + name);
	    }
	rs.close();
	 }
	 
	 catch (Exception e)
	 {
		 System.out.println("EXCEPTION in displayAllAuthors!");
		 e.printStackTrace();
	 }
	 finally
	 {
		 
	 }
 }
 public static int AddAuthor(int id , String fn , String ln)
 {
	 try{
	 String query = "insert into authors(id , FirstName , LastName) values ( "+ id + ",'" + fn + "','" + ln + "')" ;
	Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
	Statement stmt = con.createStatement() ;
	return stmt.executeUpdate(query) ;
		
	
	 }
	 
	 catch (Exception e)
	 {
		 System.out.println("EXCEPTION in displayAllAuthors!");
		 e.printStackTrace();
	 }
	 finally
	 {
		 
	 }
	 return 0;
 }
 public static int UpdateAuthorByID(int id , String fn , String ln)
 {
	 try{
	 String query = "update authors set FirstName = '" + fn + "' , LastName = '" + ln + "' where id = " + id + ";" ;
	Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
	Statement stmt = con.createStatement() ;
	return stmt.executeUpdate(query) ;
		
	
	 }
	 
	 catch (Exception e)
	 {
		 System.out.println("EXCEPTION in displayAllAuthors!");
		 e.printStackTrace();
	 }
	 finally
	 {
		 
	 }
	 return 0;
 }

 public static int DeleteAuthorByID(int id)
 {
	 try{
	 String query = "delete from authors where id = " + id ;
	Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
	Statement stmt = con.createStatement() ;
	return stmt.executeUpdate(query) ;
		
	
	 }
	 
	 catch (Exception e)
	 {
		 System.out.println("EXCEPTION in displayAllAuthors!");
		 e.printStackTrace();
	 }
	 finally
	 {
		 
	 }
	 return 0;
 }
 
 
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
    //System.out.println("Creating statement...");
    //stmt = conn.createStatement();
    //String sql = "SELECT * FROM  ac";
    //ResultSet rs = stmt.executeQuery(sql);
    
    displayAllAuthors() ;
    GetBooksbyAuthorID(2) ;
   AddAuthor(5 , "Ehsan" , "Saleem");
    //UpdateAuthorByID(2 , "changeFN" , "ChangeLN");
    DeleteAuthorByID(2);
    //STEP 5: Extract data from result set
    /*while(rs.next()){
       //Retrieve by column name
       int id  = rs.getInt("id");
       String name = rs.getString("name");

       //Display values
       System.out.print("ID: " + id);
       System.out.println(", name: " + name);
    }*/
    //rs.close();
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
