package MyPack;

import java.util.*; 
import java.sql.*; 

public class PersonDAO{ 

private Connection con; 

// default constructor 
public PersonDAO() throws ClassNotFoundException,SQLException{
establishConnection(); } 

// method used to establish connection with db 
private void establishConnection() throws ClassNotFoundException,SQLException{ 
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/person";;
    con=DriverManager.getConnection(url, "root", "");

System.out.print("Connection created...........");
} 

// used to search the person records against name and returns the ArrayList that contains only those PersonInfo objects which matches the search criteria i.e. name 

public ArrayList retrievePersonList(String Name) throws SQLException { 

ArrayList personList = new ArrayList(); 

String sql = " SELECT * FROM Person WHERE name = ?"; 
PreparedStatement pStmt = con.prepareStatement(sql); 
pStmt.setString( 1, Name); 

// executing query 
ResultSet rs = pStmt.executeQuery(); 

String name; 
String add; 
int pNo; 

while ( rs.next() ) { 
name = rs.getString("name"); 
add = rs.getString("address"); 
pNo = rs.getInt("phoneNumber"); 

// creating a PersonBean object 
PersonInfo personBean = new PersonInfo(); 
personBean.setName(name); 
personBean.setAddress(add); 
personBean.setPhoneNum(pNo); 

// adding a bean to arraylist 
personList.add(personBean); 
} // end while

 return personList; 

} // end retrievePersonList 

public void addPerson(PersonInfo person) throws SQLException{ 

String sql = " INSERT INTO Person VALUES (?, ?, ?)"; 
PreparedStatement pStmt = con.prepareStatement(sql); 

String name = person.getName(); 
String add = person.getAddress(); 
int pNo = person.getPhoneNum(); 

pStmt.setString( 1 , name ); 
pStmt.setString( 2 , add ); 
pStmt.setInt( 3 , pNo );

pStmt.executeUpdate(); 

} 



} // end PersonDAO class 
