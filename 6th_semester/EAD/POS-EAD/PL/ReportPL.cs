using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


using BLL;
using BO;

namespace PL
{
    public class ReportPL
    {
        public void input()
        {
            int choice = 0;
            String c;

            while (choice != 5)
            {
                Console.Clear();
                System.Console.WriteLine("Reports Menu\n\n");
                System.Console.WriteLine("1- Stock in Hand");
                System.Console.WriteLine("2- Customer Balance");
                System.Console.WriteLine("3- Sales Report");
                System.Console.WriteLine("4- OutStanding Sales");
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
                    viewStock();
                }
                else if (choice == 2)
                {
                   viewCustBalance();
                }
                else if (choice == 3)
                {
                    //findItem();
                }
                else if (choice == 4)
                {
                   // removeItem();
                }
            }
        }

        public void viewStock()
        {
                ReportBLL r = new ReportBLL();
                List<ItemBO> list= r.stockView();
                bool flagS=true;
                foreach (var i in list)
                {
                    if (flagS)
                    {
                        System.Console.WriteLine("\n----------------------------------------------------");
                        System.Console.WriteLine("Item ID".PadRight(10) + "Description".PadRight(20)  + "Quantity".PadRight(10));
                        System.Console.WriteLine("----------------------------------------------------");
                        flagS = false;
                    }
                    System.Console.WriteLine(i.Itemid.ToString().PadRight(10) + i.Description.PadRight(20) + i.Quantity.ToString().PadRight(10));


                }
                System.Console.WriteLine("----------------------------------------------------");
                System.Console.ReadLine();

            }

        public void viewCustBalance()
        {
            ReportBLL r = new ReportBLL();
            List<CustomerBO> list= r.custView();
            bool flagS=true;
            foreach (var i in list)
                {
                    if (flagS)
                    {
                        System.Console.WriteLine("\n-----------------------------------------------------------------------------");
                        System.Console.WriteLine("CustomerID".PadRight(12) + "Name".PadRight(20) + "Amount Payable".PadRight(10));
                        System.Console.WriteLine("-----------------------------------------------------------------------------");
                        flagS = false;
                    }
                    System.Console.WriteLine(i.Custid.ToString().PadRight(12) + i.Name.PadRight(20) +  i.Amount.ToString().PadRight(10));

                }
                System.Console.WriteLine("-----------------------------------------------------------------------------");
                System.Console.ReadLine();
            


        }



    }


    
}
