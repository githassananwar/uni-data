using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using BLL;
using BO;

namespace PL
{
    public class CustomerPL
    {
        public void input()
        {
            int choice = 0;
            String c;

            while (choice != 5)
            {
                Console.Clear();
                System.Console.WriteLine("Customers Menu\n\n");
                System.Console.WriteLine("1- Add new Customer");
                System.Console.WriteLine("2- Update Customer Details");
                System.Console.WriteLine("3- Find Customer");
                System.Console.WriteLine("4- Remove Existing Customer");
                System.Console.WriteLine("5- Back to Main Menu\n");

                System.Console.Write("Enter Choice: ");
                c = System.Console.ReadLine();
                if (c.Length != 0)
                {
                    choice = int.Parse(c);
                }
                else
                {
                    choice = 0;
                }

                while (choice < 1 || choice > 5)
                {
                    System.Console.Write("InValid Choice! Enter again: ");
                    c = System.Console.ReadLine();
                    if (c.Length != 0)
                    {
                        choice = int.Parse(c);
                    }
                    else
                    {
                        choice = 0;
                    }
                }

                if (choice == 1)
                {
                    addNewCustomer();
                }
                else if (choice == 2)
                {
                    modifyCustomer();
                }
                else if (choice == 3)
                {
                    findCustomer();
                }
                else if (choice == 4)
                {
                    removeCustomer();
                }
            }

        }

        public void addNewCustomer()
        {
            Console.Clear();
            System.Console.WriteLine("Add Customer:- \n\n");

            CustomerBO o = new CustomerBO();
            CustomerBLL CustomerB = new CustomerBLL();

            int id = CustomerB.readId();
            System.Console.WriteLine("CustomerID: " + id);
            System.Console.Write("Enter Name: ");
            String n = System.Console.ReadLine();

            System.Console.Write("Enter Address: ");
            String a = System.Console.ReadLine();

            System.Console.Write("Enter Phone: ");
            String p = System.Console.ReadLine();

            System.Console.Write("Enter Email: ");
            String e = System.Console.ReadLine();

            System.Console.Write("Enter Sales limit: ");
            int s;
            String c = System.Console.ReadLine();
            if (c.Length != 0)
            {
                s = int.Parse(c);
            }
            else
            {
                s = 0;
            }

            while (s < 0)
            {
                System.Console.Write("InValid Amount! Enter again: ");
                c = System.Console.ReadLine();
                if (c.Length != 0)
                {
                    s = int.Parse(c);
                }
                else
                {
                    s = 0;
                }
            }


            System.Console.Write("Confirm addition? (Y/N): ");
            c = System.Console.ReadLine();

            if (c.Length != 0 && (c[0] == 'Y' || c[0] == 'y'))
            {
                o.Custid = id;
                o.Name = n;
                o.Address = a;
                o.Phone = p;
                o.Email = e;
                o.Slimit = s;

                CustomerB.save(o);

                Console.Clear();
                System.Console.WriteLine("\n\n\n\n\n\n ***Addition Successful***");
                System.Threading.Thread.Sleep(1000);

            }
            else
            {
                Console.Clear();
                System.Console.WriteLine("\n\n\n\n\n\n ***Addition NOT Successful***");
                System.Threading.Thread.Sleep(1000);
            }



        }


        public void modifyCustomer()
        {
            Console.Clear();
            System.Console.WriteLine("Modify Customer Details:- \n\n");

            System.Console.Write("Enter Customer ID: ");
            int id;
            String c = System.Console.ReadLine();

            if (c.Length != 0)
            {
                id = int.Parse(c);
            }
            else
            {
                id = 0;
            }

            CustomerBLL custB = new CustomerBLL();
            CustomerBO o = custB.find(id);


            if (o.Custid != 0)
            {
                System.Console.WriteLine("\n-----------------------------------------------------------------------------");
                System.Console.WriteLine("CustomerID".PadRight(12) + "Name".PadRight(20) + "Email".PadRight(20) + "Phone".PadRight(15) + "SalesLimit".PadRight(10));
                System.Console.WriteLine("-----------------------------------------------------------------------------");
                System.Console.WriteLine(o.Custid.ToString().PadRight(12) + o.Name.PadRight(20) + o.Email.PadRight(20) + o.Phone.PadRight(15)+o.Slimit.ToString().PadRight(10));
                System.Console.WriteLine("-----------------------------------------------------------------------------");

                System.Console.WriteLine("\nUpdate (Press Enter to continue) :-");


                System.Console.Write("Name: ");
                String u = System.Console.ReadLine();
                if (u.Length != 0)
                {
                    o.Name = u;
                }

                System.Console.Write("Address: ");
                u = System.Console.ReadLine();
                if (u.Length != 0)
                {
                    o.Address = u;
                }

                System.Console.Write("Phone: ");
                u = System.Console.ReadLine();
                if (u.Length != 0)
                {
                    o.Phone = u;
                }

                System.Console.Write("Email: ");
                u = System.Console.ReadLine();
                if (u.Length != 0)
                {
                    o.Email = u;
                }


                System.Console.Write("Sale limit: ");
                u = System.Console.ReadLine();
                while (u.Length != 0 && int.Parse(u) < 0)
                {
                    System.Console.Write("InValid Price! Enter again: ");
                    u = System.Console.ReadLine();
                }
                if (u.Length != 0)
                {
                    o.Slimit = int.Parse(u);
                }



                System.Console.Write("Confirm updation? (Y/N): ");
                c = System.Console.ReadLine();

                if (c.Length != 0 && (c[0] == 'Y' || c[0] == 'y'))
                {

                    custB.modify(o);
                    Console.Clear();
                    System.Console.WriteLine("\n\n\n\n\n\n ***Updation Successful***");
                    System.Threading.Thread.Sleep(1000);

                }
                else
                {
                    Console.Clear();
                    System.Console.WriteLine("\n\n\n\n\n\n ***Updation NOT Successful***");
                    System.Threading.Thread.Sleep(1000);
                }


            }

            else
            {
                System.Console.WriteLine("\nError! Customer NOT found");
                System.Threading.Thread.Sleep(1000);
            }

        }


        public void findCustomer()
        {
            Console.Clear();
            System.Console.WriteLine("Find Customer:- \n\n");

            System.Console.WriteLine("Fill atleast one entry (Press Enter to continue):-");
            CustomerBO o = new CustomerBO();

            System.Console.Write("Customer ID: ");
            String s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Custid = int.Parse(s);
            }


            System.Console.Write("Name: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Name = s;
            }

            System.Console.Write("Email: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Email = s;
            }

            System.Console.Write("Phone: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Phone = s;
            }

          
            System.Console.Write("Sale Limit: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Slimit = int.Parse(s);
            }

            CustomerBLL custB = new CustomerBLL(); bool flagS = true;
           
            List<CustomerBO> list = custB.find(o);

            if (list.Count != 0)
            {
                foreach (var i in list)
                {
                    if (flagS)
                    {
                        System.Console.WriteLine("\n-----------------------------------------------------------------------------");
                        System.Console.WriteLine("CustomerID".PadRight(12) + "Name".PadRight(20) + "Email".PadRight(20) + "Phone".PadRight(15) + "SalesLimit".PadRight(10));
                        System.Console.WriteLine("-----------------------------------------------------------------------------");
                        flagS = false;
                    }
                    System.Console.WriteLine(i.Custid.ToString().PadRight(12) + i.Name.PadRight(20) + i.Email.PadRight(20) + i.Phone.PadRight(15) + i.Slimit.ToString().PadRight(10));

                }
                System.Console.WriteLine("-----------------------------------------------------------------------------");
                System.Console.ReadLine();
            }
            else
            {
                System.Console.WriteLine("\nError! Customer NOT found");
                System.Threading.Thread.Sleep(1000);
            }

        }


        public void removeCustomer()
        {
            Console.Clear();
            System.Console.WriteLine("Remove Customer:- \n\n");

            System.Console.Write("Enter Customer ID: ");
            int id;
            String c = System.Console.ReadLine();

            if (c.Length != 0)
            {
                id= int.Parse(c);
            }
            else
            {
                id = 0;
            }

            CustomerBLL custB = new CustomerBLL();
            CustomerBO o = custB.find(id);


            if (o.Custid != 0)
            {
                System.Console.Write("Confirm removal? (Y/N): ");
                c = System.Console.ReadLine();

                if (c.Length != 0 && (c[0] == 'Y' || c[0] == 'y'))
                {

                    custB.remove(o);
                    Console.Clear();
                    System.Console.WriteLine("\n\n\n\n\n\n ***Removal Successful***");
                    System.Threading.Thread.Sleep(1000);

                }
                else
                {
                    Console.Clear();
                    System.Console.WriteLine("\n\n\n\n\n\n ***Removal NOT Successful***");
                    System.Threading.Thread.Sleep(1000);
                }
                

            }
            else
            {
                System.Console.WriteLine("\nError! Customer NOT found");
                System.Threading.Thread.Sleep(1000);
            }

        }
   


    }

}
