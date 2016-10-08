using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using BLL;
using BO;

namespace PL
{
    public class ItemPL
    {
        public void input()
        {
            int choice = 0;
            String c;

            while (choice != 5)
            {
                Console.Clear(); 
                System.Console.WriteLine("Items Menu\n\n");
                System.Console.WriteLine("1- Add new Item");
                System.Console.WriteLine("2- Update Item Details");
                System.Console.WriteLine("3- Find Item");
                System.Console.WriteLine("4- Remove Existing Item");
                System.Console.WriteLine("5- Back to Main Menu\n");

                System.Console.Write("Enter Choice: ");
                c = System.Console.ReadLine();
                if (c.Length!=0)
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
                    if (c.Length!=0)
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
                   addNewItem();
                }
                else if (choice == 2)
                {
                    modifyItem();
                }
                else if (choice == 3)
                {
                    findItem();
                }
                else if (choice == 4)
                {
                    removeItem();
                }
            }

        }

        public void addNewItem()
        {
            Console.Clear();
            System.Console.WriteLine("Add Item:- \n\n");

            ItemBO o = new ItemBO();
            ItemBLL itemB = new ItemBLL();

            int id = itemB.readId();
            System.Console.WriteLine("ItemID: " + id);
            System.Console.Write("Enter Description: ");
            String d = System.Console.ReadLine();

            System.Console.Write("Enter Price: ");
            double p;
            String c = System.Console.ReadLine();
            if (c.Length!=0)
            {
                 p= double.Parse(c);
            }
            else
            {
                p = 0;
            }

            while (p < 0)
            {
                System.Console.Write("InValid Price! Enter again: ");
                c = System.Console.ReadLine();
                if (c.Length != 0)
                {
                    p = double.Parse(c);
                }
                else
                {
                    p = 0;
                }
            }




            System.Console.Write("Enter Quantity: ");
            int q;
            c = System.Console.ReadLine();
            if (c.Length != 0)
            {
                q = int.Parse(c);
            }
            else
            {
                q = 0;
            }

            while (q < 0)
            {
                System.Console.Write("InValid Quantity! Enter again: ");
                c = System.Console.ReadLine();
                if (c.Length != 0)
                {
                    q = int.Parse(c);
                }
                else
                {
                    q = 0;
                }
            }

            System.Console.Write("Confirm addition? (Y/N): ");
            c = System.Console.ReadLine();

            if (c.Length!=0 && (c[0] == 'Y' || c[0] == 'y') )
            {
                o.Itemid = id;
                o.Description = d;
                o.Price = p;
                o.Quantity = q;
               
                itemB.save(o);

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


        public void modifyItem()
        {
            Console.Clear();
            System.Console.WriteLine("Modify Item:- \n\n");

            System.Console.Write("Enter Item ID: ");
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

            ItemBLL itemB = new ItemBLL();
            ItemBO o = itemB.find(id);


            if (o.Itemid!=0)
            {
                System.Console.WriteLine("\n----------------------------------------------------");
                System.Console.WriteLine("Item ID".PadRight(10) + "Description".PadRight(20) + "Price".PadRight(10) + "Quantity".PadRight(10));
                System.Console.WriteLine("----------------------------------------------------");
                System.Console.WriteLine(o.Itemid.ToString().PadRight(10)+o.Description.PadRight(20)+o.Price.ToString().PadRight(10)+o.Quantity.ToString().PadRight(10));
                System.Console.WriteLine("----------------------------------------------------");

                System.Console.WriteLine("\nUpdate (Press Enter to continue) :-");


                System.Console.Write("Description: ");
                String u = System.Console.ReadLine();
                if (u.Length != 0)
                {
                    o.Description = u;
                }

                System.Console.Write("Price: ");
                u = System.Console.ReadLine();
                while (u.Length != 0 && double.Parse(u) < 0)
                {
                    System.Console.Write("InValid Price! Enter again: ");
                    u = System.Console.ReadLine();
                }
                if (u.Length != 0)
                {
                    o.Price = double.Parse(u);
                }



                System.Console.Write("Quantity: ");
                u = System.Console.ReadLine();
                while (u.Length != 0 && int.Parse(u) < 0)
                {
                    System.Console.Write("InValid Quantity! Enter again: ");
                    u = System.Console.ReadLine();
                }
                if (u.Length != 0)
                {
                    o.Quantity = int.Parse(u);
                }



                System.Console.Write("Confirm updation? (Y/N): ");
                c = System.Console.ReadLine();

                if (c.Length != 0 && (c[0] == 'Y' || c[0] == 'y'))
                {

                    itemB.modify(o);
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
                System.Console.WriteLine("\nError! Item NOT found");
                System.Threading.Thread.Sleep(1000);
            }

        }


        public void findItem()
        {
            Console.Clear();
            System.Console.WriteLine("Find Item:- \n\n");

            System.Console.WriteLine("Fill atleast one entry (Press Enter to continue):-");
            ItemBO o = new ItemBO();

            System.Console.Write("Item ID: ");
            String s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Itemid = int.Parse(s);
            }


            System.Console.Write("Description: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Description = s;
            }

            System.Console.Write("Price: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Price = double.Parse(s);
            }

            System.Console.Write("Quantity: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Quantity= int.Parse(s);
            }

            System.Console.Write("Date: ");
            s = System.Console.ReadLine();
            if (s.Length != 0)
            {
                o.Date = s;
            }

            ItemBLL itemB = new ItemBLL(); bool flagS = true; 
            List<ItemBO> list = itemB.find(o);

            if (list.Count != 0)
            {
                foreach (var i in list)
                {
                    if (flagS)
                    {
                        System.Console.WriteLine("\n----------------------------------------------------");
                        System.Console.WriteLine("Item ID".PadRight(10) + "Description".PadRight(20) + "Price".PadRight(10) + "Quantity".PadRight(10));
                        System.Console.WriteLine("----------------------------------------------------");
                        flagS = false;
                    }
                    System.Console.WriteLine(i.Itemid.ToString().PadRight(10) + i.Description.PadRight(20) + i.Price.ToString().PadRight(10) + i.Quantity.ToString().PadRight(10));


                }
                System.Console.WriteLine("----------------------------------------------------");
                System.Console.ReadLine();
            }
            else
            {
                System.Console.WriteLine("\nError! Item NOT found");
                System.Threading.Thread.Sleep(1000);
            }
                
        }


        public void removeItem()
        {
            Console.Clear();
            System.Console.WriteLine("Remove Item:- \n\n");

            System.Console.Write("Enter Item ID: ");
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

            ItemBLL itemB = new ItemBLL();
            ItemBO o = itemB.find(id);


            if (o.Itemid != 0)
            {
                System.Console.Write("Confirm removal? (Y/N): ");
                c = System.Console.ReadLine();

                if (c.Length != 0 && (c[0] == 'Y' || c[0] == 'y'))
                {

                    itemB.remove(o);
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
                System.Console.WriteLine("\nError! Item NOT found");
                System.Threading.Thread.Sleep(1000);
            }

        }
   

        
    }
}
