using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Data.SqlClient;

using BO;

namespace DAL
{
    public class ItemDAL
    {
        public int readId()
        {
            int itemid=0, noOfRows=0;
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String checkQuery = "SELECT count(itemid) FROM item;";
            String query = "SELECT MAX(itemid) FROM item;";
                   
            SqlCommand cmd = new SqlCommand(checkQuery, con);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();

            if (dr.Read())
            {
                noOfRows = (int)dr[0];
                if (noOfRows!=0)
                {
                    con.Close();
                    cmd = new SqlCommand(query, con);
                    con.Open();
                    dr = cmd.ExecuteReader();

                    if (dr.Read())
                    {
                        itemid = (int)dr[0];
                        return itemid+1;
                    }

                }
            }

            con.Close();

            return itemid+1;
            
        }

        public void save(ItemBO item)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "insert into item(description,price,quantity,creationdate) values(@des,@pri,@quan,@create);";

            SqlParameter p1 = new SqlParameter("des", item.Description);
            SqlParameter p2 = new SqlParameter("pri", item.Price);
            SqlParameter p3 = new SqlParameter("quan", item.Quantity);
            SqlParameter p4 = new SqlParameter("create", item.Date);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);
            cmd.Parameters.Add(p2);
            cmd.Parameters.Add(p3);
            cmd.Parameters.Add(p4);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();

           
        }


        public ItemBO search(int itemid)
        {
            ItemBO item = new ItemBO();

            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from item where itemid=@itemid;";

            SqlParameter p1 = new SqlParameter("itemid", itemid);
    
            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);

            con.Open();

            SqlDataReader dr=cmd.ExecuteReader();

            if(dr.Read())
            {
                item.Itemid = (int)dr[0];
                item.Description = (string)dr[1];
                item.Price = (double)dr[2];
                item.Quantity = (int)dr[3];
                item.Date = (string)dr[4];
            }

            con.Close();

            
            return item;


        }

        public void modify(ItemBO item)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "update item set description=@des,price=@pri,quantity=@quan,creationdate=@create from item where itemid=@itemid;";


            SqlParameter p1 = new SqlParameter("des", item.Description);
            SqlParameter p2 = new SqlParameter("pri", item.Price);
            SqlParameter p3 = new SqlParameter("quan", item.Quantity);
            SqlParameter p4 = new SqlParameter("create", item.Date);
            SqlParameter p5 = new SqlParameter("itemid", item.Itemid);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);
            cmd.Parameters.Add(p2);
            cmd.Parameters.Add(p3);
            cmd.Parameters.Add(p4);
            cmd.Parameters.Add(p5);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();


        }


        public List<ItemBO> search(ItemBO item)
        {
            List<ItemBO> list = new List<ItemBO>();
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from item";
            
            if(item.Itemid!=0 )
            {
                query = query + " where itemid="+item.Itemid;

                if (item.Description != null)
                {
                    query = query + " and description='"+item.Description+"'";
                }
                if (item.Price != 0)
                {
                    query = query + " where price=" + item.Price;
                }
                if (item.Quantity != 0)
                {
                    query = query + " and quantity=" + item.Quantity;
                }
                if (item.Date != null)
                {
                    query = query + " and creationdate='" +item.Description+"'";
                }
                   
            }
            else if (item.Description != null)
            {
                query = query + " where description='" + item.Description + "'";
                if (item.Price != 0)
                {
                    query = query + " and price=" + item.Price;
                }
                if (item.Quantity != 0)
                {
                    query = query + " and quantity=" + item.Quantity;
                }
                if (item.Date != null)
                {
                    query = query + " and creationdate='" + item.Description + "'";
                }

            }
            else if (item.Price != 0)
            {
                query = query + " where price=" + item.Price;
                if (item.Quantity != 0)
                {
                    query = query + " and quantity=" + item.Quantity;
                }
                if (item.Date != null)
                {
                    query = query + " and creationdate='" + item.Description + "'";
                }

            }
            else if (item.Quantity != 0)
            {
                query = query + " where quantity=" + item.Quantity;
                if (item.Date != null)
                {
                    query = query + " and creationdate='" + item.Description + "'";
                }

            }
            else if (item.Date != null)
            {
                query = query + " where creationdate='" + item.Date+"'";
            }

            query = query + ";";

            SqlCommand cmd = new SqlCommand(query, con);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();

            while (dr.Read())
            {
                ItemBO itemFound = new ItemBO();
                itemFound.Itemid = (int)dr[0];
                itemFound.Description = (string)dr[1];
                itemFound.Price = (double)dr[2];
                itemFound.Quantity = (int)dr[3];
                itemFound.Date = (string)dr[4];

                list.Add(itemFound);
            }

            con.Close();

            return list;
               

        }


        public void remove(ItemBO item)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "delete from item where itemid=@itemid;";

            SqlParameter p1 = new SqlParameter("itemid", item.Itemid);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();

            
        }


    }
}
