using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;

using System.IO;
using BO;


namespace DAL
{
    public class SaleLineItemDAL
    {
        public int readId()
        {
            int lineid = 0, noOfRows = 0;
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String checkQuery = "SELECT count(lineid) FROM salelineitem;";
            String query = "SELECT MAX(lineid) FROM salelineitem;";

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
                        lineid = (int)dr[0];
                        return lineid + 1;
                    }

                }
            }

            con.Close();

            return lineid + 1;

        }

        

        public void save(List<SaleLineItemBO> linelist)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            foreach (var line in linelist)
            {

                String query = "insert into salelineitem(orderid,itemid,quantity,amount) values(@orderid,@itemid,@quan,@am);";

                SqlParameter p1 = new SqlParameter("orderid", line.Orderid);
                SqlParameter p2 = new SqlParameter("itemid", line.Itemid);
                SqlParameter p3 = new SqlParameter("quan", line.Quantity);
                SqlParameter p4 = new SqlParameter("am", line.Amount);

                SqlCommand cmd = new SqlCommand(query, con);

                cmd.Parameters.Add(p1);
                cmd.Parameters.Add(p2);
                cmd.Parameters.Add(p3);
                cmd.Parameters.Add(p4);

                con.Open();

                cmd.ExecuteNonQuery();

                con.Close();

            }
        }

    }
}
