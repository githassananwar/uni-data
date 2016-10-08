package databasePractice;

import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

//import com.mysql.jdbc.ResultSet;
import java.sql.* ;

public class Driver {
	public static void main(String[] args){
		String DB_URL = "jdbc:mysql://localhost/uni" ;
		String user = "root" ;
		String pwd = "" ;
		Connection conn = null ;
		Statement st = null ;
		PreparedStatement ps = null ;
		
		//////////////////////////
		try {
			Class.forName("com.mysql.jdbc.Driver") ;
			conn = DriverManager.getConnection(DB_URL, user, pwd) ;
		} 
		catch (ClassNotFoundException e){
			e.printStackTrace();
		} 
		catch(SQLException e){
			e.printStackTrace(); 
		}
		///////////////////////////
		try {
			st = conn.createStatement() ;
			ps = conn.prepareStatement("insert into emp(id,name) values(?,?) ;") ;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		String sql = "select * from emp" ;
		//int id1 = 3 ;
		//String name1 = "Nanna" ;
		//String insert = "insert into emp (id,name) values (" + id1 + ",'" + name1 + "');" ;
		//String delete = "delete from emp where id = 300" ;
		//String update = "update emp set name = '" + name1 + "' where id = " + id1 + " ;";
		
		try {
			ps.setInt(1, 30);
			ps.setString(2, "abcsd");
			ps.executeUpdate() ;
			ps.setInt(1 ,  20);
			ps.setString(2 , "asfa");
			ps.executeUpdate();
			//int x = st.executeUpdate(update) ;
			ResultSet rs = st.executeQuery(sql) ;
			while(rs.next()){
				int id = rs.getInt("id") ;
				String name = rs.getString("name") ;
				//print
				System.out.print("ID = " + id);
				System.out.println(", Name = " + name) ;
			}
			rs.close(); 
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}