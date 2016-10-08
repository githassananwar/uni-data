using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL
{
    public class MainMenu
    {
        public void display()
        {
            int choice = 0;

            while (choice != 6)
            {
                Console.Clear();
                System.Console.WriteLine("WelCome - Main Menu\n\n");
                System.Console.WriteLine("1- Manage Items");
                System.Console.WriteLine("2- Manage Customers");
                System.Console.WriteLine("3- Make New Sale");
                System.Console.WriteLine("4- Make Payment");
                System.Console.WriteLine("5- Reports Menu");
                System.Console.WriteLine("6- Exit\n");

                System.Console.Write("Enter Choice: ");
                String c = System.Console.ReadLine();

                if (c.Length != 0)
                {
                    choice = int.Parse(c);
                }
                else
                {
                    choice = 0;
                }

                while (choice < 1 || choice > 6)
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
                    ItemPL i = new ItemPL();
                    i.input();
                }
                else if (choice == 2)
                {
                    CustomerPL C = new CustomerPL();
                    C.input();
                }
                else if (choice == 3)
                {
                    SalePL s = new SalePL();
                    s.createSale();
                }
                else if (choice == 4)
                {
                    ReceiptPL r = new ReceiptPL();
                    r.makepayment();
                }
                else if (choice == 5)
                {
                    ReportPL r = new ReportPL();
                    r.input();
                }

            }

            System.Console.WriteLine("\n    --------------------------ThankYou--------------------------\n");

        }  
           
    }
}
