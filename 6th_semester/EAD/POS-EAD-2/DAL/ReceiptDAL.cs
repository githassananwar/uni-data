using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;

using System.IO;
using BO;

namespace DAL
{
    public class ReceiptDAL
    {
        public int readId()
        {
            int receiptid = 0, noOfRows = 0;
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String checkQuery = "SELECT count(receiptid) FROM receipt;";
            String query = "SELECT MAX(receiptid) FROM receipt;";

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
                        receiptid = (int)dr[0];
                        return receiptid + 1;
                    }

                }
            }

            con.Close();

            return receiptid + 1;

        }


        public void save(ReceiptBO rec)
        {
           String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
           SqlConnection con = new SqlConnection(connectionstring);

           String query = "insert into receipt(date,orderid,amount) values(@date,@orderid,@am);";

           SqlParameter p1 = new SqlParameter("orderid", rec.Orderid);
           SqlParameter p2 = new SqlParameter("date", rec.Receiptdate);
           SqlParameter p3 = new SqlParameter("am", rec.Amountpaid);

           SqlCommand cmd = new SqlCommand(query, con);

           cmd.Parameters.Add(p1);
           cmd.Parameters.Add(p2);
           cmd.Parameters.Add(p3);

           con.Open();

           cmd.ExecuteNonQuery();

           con.Close();

           
               

        }



        public double calculateAmountPaid(int saleid)
        {
            double amountpaid = 0;
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from receipt where orderid=@saleid";

            SqlParameter p1 = new SqlParameter("saleid", saleid);
            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                amountpaid = amountpaid + (double)dr[3];
            }

            con.Close();


            return amountpaid;

        }

    }
}
