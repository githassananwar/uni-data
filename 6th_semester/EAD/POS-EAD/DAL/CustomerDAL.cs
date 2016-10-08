using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using BO;
using System.IO;

namespace DAL
{
    public class CustomerDAL
    {
        public int readId()
        {
            FileStream fin = new FileStream("customerid.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String id = sr.ReadLine();

            sr.Close();
            fin.Close();

            return int.Parse(id);

        }

        public void updateId(int id)
        {
            FileStream fout = new FileStream("customerid.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fout);
            System.Console.WriteLine(id);
            sw.Write(id);

            sw.Close();
            fout.Close();
        }

        public void save(CustomerBO customer)
        {
            FileStream fout = new FileStream("customerdata.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fout);
            sw.WriteLine(customer.Custid + ";" + customer.Name + ";" + customer.Address + ";" + customer.Phone + ";" + customer.Email +";" + customer.Slimit + ";" + customer.Amount);

            sw.Close();
            fout.Close();
        }


        public CustomerBO search(int id)
        {
            CustomerBO customer = new CustomerBO();
            FileStream fin = new FileStream("customerdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                if (int.Parse(data[0]) == id)
                {
                    customer.Custid = int.Parse(data[0]);
                    customer.Name= data[1];
                    customer.Address=data[2];
                    customer.Phone=data[3];
                    customer.Email=data[4];
                    customer.Slimit=int.Parse(data[5]);
                    customer.Amount=double.Parse(data[6]);
                    
                    break;
                }
            }

            sr.Close();
            fin.Close();

            return customer;


        }

        public void modify(CustomerBO customer)
        {
            List<CustomerBO> list = new List<CustomerBO>();

            FileStream fin = new FileStream("customerdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');

                CustomerBO cust = new CustomerBO();
                cust.Custid = int.Parse(data[0]);
                cust.Name = data[1];
                cust.Address = data[2];
                cust.Phone = data[3];
                cust.Email = data[4];
                cust.Slimit = int.Parse(data[5]);
                cust.Amount = double.Parse(data[6]);


                list.Add(cust);
            }

            sr.Close();
            fin.Close();

            //Overwriting
            fin = new FileStream("customerdata.txt", FileMode.Create);
            fin.Close();

            foreach (var i in list)
            {
                if (i.Custid == customer.Custid)
                {
                    save(customer);
                }
                else
                {
                    save(i);
                }

            }


        }


        public List<CustomerBO> search(CustomerBO customer)
        {
            List<CustomerBO> list = new List<CustomerBO>();
            FileStream fin = new FileStream("customerdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                bool flag = true;
                if (customer.Custid != 0)
                {
                    if (int.Parse(data[0]) != customer.Custid)
                    {
                        flag = false;
                    }

                }
                if (customer.Name != null)
                {
                    if (data[1] != customer.Name)
                    {
                        flag = false;
                    }

                }
                if (customer.Address != null)
                {
                    if (data[2] != customer.Address)
                    {
                        flag = false;
                    }

                }
                if (customer.Phone != null)
                {
                    if (data[3] != customer.Phone)
                    {
                        flag = false;
                    }

                }
                if (customer.Email != null)
                {
                    if (data[4] != customer.Email)
                    {
                        flag = false;
                    }

                }

                if (customer.Slimit != 0)
                {
                    if (int.Parse(data[5]) != customer.Slimit)
                    {
                        flag = false;
                    }

                }
                if (customer.Amount != 0)
                {
                    if (double.Parse(data[6]) != customer.Amount)
                    {
                        flag = false;
                    }

                }
             
                if (flag)
                {
                    CustomerBO cust = new CustomerBO();
                    cust.Custid = int.Parse(data[0]);
                    cust.Name = data[1];
                    cust.Address = data[2];
                    cust.Phone = data[3];
                    cust.Email = data[4];
                    cust.Slimit = int.Parse(data[5]);
                    cust.Amount = double.Parse(data[6]);

                    list.Add(cust);

                }

            }


            sr.Close();
            fin.Close();

            return list;


        }


        public void remove(CustomerBO customer)
        {
            List<CustomerBO> list = new List<CustomerBO>();

            FileStream fin = new FileStream("customerdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                CustomerBO cust = new CustomerBO();
                cust.Custid = int.Parse(data[0]);
                cust.Name = data[1];
                cust.Address = data[2];
                cust.Phone = data[3];
                cust.Email = data[4];
                cust.Slimit = int.Parse(data[5]);
                cust.Amount = double.Parse(data[6]);
               

                list.Add(cust);
            }

            sr.Close();
            fin.Close();

            //Overwriting
            fin = new FileStream("customerdata.txt", FileMode.Create);
            fin.Close();

            foreach (var i in list)
            {
                if (!(i.Custid == customer.Custid))
                {
                    save(i);
                }

            }

        }

    }
}
