using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using BO;
using System.Data.SqlClient;

namespace DAL
{
    public class SaleDAL
    {
        public int readId()
        {
            int orderid = 0, noOfRows = 0;
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String checkQuery = "SELECT count(orderid) FROM sale;";
            String query = "SELECT MAX(orderid) FROM sale;";

            SqlCommand cmd = new SqlCommand(checkQuery, con);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();

            if (dr.Read())
            {
                noOfRows = (int)dr[0];
                if (noOfRows != 0)
                {
                    con.Close();
                    cmd = new SqlCommand(query, con);
                    con.Open();
                    dr = cmd.ExecuteReader();

                    if (dr.Read())
                    {
                        orderid = (int)dr[0];
                        return orderid + 1;
                    }

                }
            }

            con.Close();

            return orderid + 1;

        }


        public void save(SaleBO sale)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "insert into sale(customerid,amount,date) values(@custid,@am,@date);";

            SqlParameter p1 = new SqlParameter("custid", sale.Custid);
            SqlParameter p2 = new SqlParameter("am", sale.Total);
            SqlParameter p3 = new SqlParameter("date", sale.Date);
            
            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);
            cmd.Parameters.Add(p2);
            cmd.Parameters.Add(p3);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();
        }

        public double checkDailySale(SaleBO sale)
        {
            double dailySale=0;

            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from sale where customerid=@custid and date=@date;";

            SqlParameter p1 = new SqlParameter("custid", sale.Custid);
            SqlParameter p2 = new SqlParameter("date", sale.Date);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);
            cmd.Parameters.Add(p2);

            con.Open();

             SqlDataReader dr = cmd.ExecuteReader();
            
             if (dr.Read())
             {
                 dailySale = dailySale + (double)dr[3];
             }

             con.Close();
             return dailySale;

        }

        public SaleBO search(int id)
        {
            SaleBO sale = new SaleBO();

            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from sale where orderid=@orderid;";

            SqlParameter p1 = new SqlParameter("orderid", id);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();

            if (dr.Read())
            {
                sale.Orderid = (int)dr[0];
                sale.Custid = (int)dr[1];
                sale.Date = (string)dr[2];
                sale.Total = (double)dr[3];
            }

            con.Close();


            return sale;


        }

    }
}
