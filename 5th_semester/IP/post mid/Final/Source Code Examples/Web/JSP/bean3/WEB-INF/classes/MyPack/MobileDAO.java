package MyPack;
import java.io.*; 
import java.sql.*; 
import java.util.*; 

public class MobileDAO implements Serializable{ 

private Connection con; 

public MobileDAO() { 
establishConnection(); 
} 

//********** establishConnection method *************

private void establishConnection(){ 

try{ 
 Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/Mobile";;
    con=DriverManager.getConnection(url, "root", "");
}catch(Exception ex){ 
System.out.println(ex); 
} 

} 

//*********** retrieveMobileList method ******************** 

public ArrayList retrieveMobileList(String cName){ 

ArrayList mobileList = new ArrayList(); 

try{ 
String sql = "SELECT a.companyName, b.model, b.price FROM company as a,detail as b WHERE a.companyName = ? AND a.id = b.id"; 
PreparedStatement pStmt = con.prepareStatement(sql); 
pStmt.setString(1, cName); 
ResultSet rs = pStmt.executeQuery(); 

int price; 
String company; 
String model;
 
while ( rs.next() ) { 
price = rs.getInt("price"); 
company = rs.getString("companyName"); 
model = rs.getString("model"); 

// creating a MobileBean object 
MobileBean mBean = new MobileBean(); 
mBean.setPrice(price); 
mBean.setCompany(company);
mBean.setModel(model); 

// adding a bean to arraylist 
mobileList.add(mBean); 
} 

con.close();

}catch(Exception ex){ 
System.out.println(ex); 
}

// returning ArrayList object 
return mobileList; 

} // end retrieveMobileList

}//end MobileDAO 

