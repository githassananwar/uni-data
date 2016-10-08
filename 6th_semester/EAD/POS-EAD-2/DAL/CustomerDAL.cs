using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;

using BO;
using System.IO;

namespace DAL
{
    public class CustomerDAL
    {
        public int readId()
        {
            int custid = 0, noOfRows = 0;
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String checkQuery = "SELECT count(custid) FROM customer;";
            String query = "SELECT MAX(custid) FROM customer;";

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
                        custid = (int)dr[0];
                        return custid + 1;
                    }

                }
            }

            con.Close();

            return custid + 1;
        }


        public void save(CustomerBO customer)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "insert into customer(name,address,phone,email,amount,salelimit) values(@n,@add,@ph,@em,@am,@sl);";

            SqlParameter p1 = new SqlParameter("n", customer.Name);
            SqlParameter p2 = new SqlParameter("add", customer.Address);
            SqlParameter p3 = new SqlParameter("ph", customer.Phone);
            SqlParameter p4 = new SqlParameter("em", customer.Email);
            SqlParameter p5 = new SqlParameter("am", customer.Amount);
            SqlParameter p6 = new SqlParameter("sl", customer.Slimit);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);
            cmd.Parameters.Add(p2);
            cmd.Parameters.Add(p3);
            cmd.Parameters.Add(p4);
            cmd.Parameters.Add(p5);
            cmd.Parameters.Add(p6);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();
        }


        public CustomerBO search(int id)
        {
            CustomerBO customer = new CustomerBO();

            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from customer where custid=@custid;";

            SqlParameter p1 = new SqlParameter("custid", id);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();

            if (dr.Read())
            {
                customer.Custid = (int)dr[0];
                customer.Name = (string)dr[1];
                customer.Address = (string)dr[2];
                customer.Phone = (string)dr[3];
                customer.Email = (string)dr[4];
                customer.Amount = (double)dr[5];
                customer.Slimit = (int)dr[6];
            }

            con.Close();


            return customer;



        }

        public void modify(CustomerBO customer)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "update customer set name=@n,address=@add,phone=@ph,email=@em,amount=@am,salelimit=@sl from customer where custid=@custid;";


            SqlParameter p1 = new SqlParameter("n", customer.Name);
            SqlParameter p2 = new SqlParameter("add", customer.Address);
            SqlParameter p3 = new SqlParameter("ph", customer.Phone);
            SqlParameter p4 = new SqlParameter("em", customer.Email);
            SqlParameter p5 = new SqlParameter("am", customer.Amount);
            SqlParameter p6 = new SqlParameter("sl", customer.Slimit);
            SqlParameter p7 = new SqlParameter("custid", customer.Custid);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);
            cmd.Parameters.Add(p2);
            cmd.Parameters.Add(p3);
            cmd.Parameters.Add(p4);
            cmd.Parameters.Add(p5);
            cmd.Parameters.Add(p6);
            cmd.Parameters.Add(p7);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();

        }


        public List<CustomerBO> search(CustomerBO customer)
        {
            List<CustomerBO> list = new List<CustomerBO>();
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "select* from customer";

            if (customer.Custid != 0)
            {
                query = query + " where custid='" + customer.Custid+"'";

                if (customer.Name != null)
                {
                    query = query + " and name='" + customer.Name+"'";
                }
                if (customer.Phone != null)
                {
                    query = query + " and phone='" + customer.Phone+"'";
                }
                if (customer.Email != null)
                {
                    query = query + " and email='" + customer.Email+"'";
                }
                if (customer.Slimit != 0)
                {
                    query = query + " and salelimit=" + customer.Slimit;
                }

            }
            else if (customer.Name != null)
            {
                query = query + " where name='" + customer.Name+"'";

                if (customer.Phone != null)
                {
                    query = query + " and phone='" + customer.Phone+"'";
                }
                if (customer.Email != null)
                {
                    query = query + " and email='" + customer.Email+"'";
                }
                if (customer.Slimit != 0)
                {
                    query = query + " and salelimit=" + customer.Slimit;
                }

            }
            else if (customer.Email != null)
            {
                query = query + " where email='" + customer.Email+"'";

                if (customer.Phone != null)
                {
                    query = query + " and phone='" + customer.Phone+"'";
                }
                if (customer.Slimit != 0)
                {
                    query = query + " and salelimit=" + customer.Slimit;
                }

            }
            else if (customer.Phone != null)
            {
                query = query + " where phone='" + customer.Phone+"'";

                if (customer.Slimit != 0)
                {
                    query = query + " and salelimit=" + customer.Slimit;
                }

            }
            else if (customer.Slimit != 0)
            {
                query = query + " where salelimit=" + customer.Slimit;
            }

            
            query = query + ";";

            SqlCommand cmd = new SqlCommand(query, con);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader();

            while (dr.Read())
            {
                CustomerBO custFound = new CustomerBO();
                custFound.Custid = (int)dr[0];
                custFound.Name = (string)dr[1];
                custFound.Address = (string)dr[2];
                custFound.Phone = (string)dr[3];
                custFound.Email = (string)dr[4];
                custFound.Amount = (double)dr[5];
                custFound.Slimit = (int)dr[6];

                list.Add(custFound);
            }

            con.Close();

            return list;

           


        }


        public void remove(CustomerBO customer)
        {
            String connectionstring = @"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\Hassan\Desktop\POS-EAD-2\POS\MyDatabase.mdf;Integrated Security=True";
            SqlConnection con = new SqlConnection(connectionstring);

            String query = "delete from customer where custid=@custid;";

            SqlParameter p1 = new SqlParameter("custid", customer.Custid);

            SqlCommand cmd = new SqlCommand(query, con);

            cmd.Parameters.Add(p1);

            con.Open();

            cmd.ExecuteNonQuery();

            con.Close();

        }

    }
}
