using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using BLL;
using BO;


namespace PL
{
    public class SalePL
    {
        public void createSale()
        {
            Console.Clear();
            System.Console.WriteLine("New Sale\n\n");

            SaleBO sale = new SaleBO();
            SaleBLL saleB = new SaleBLL();

            int id = saleB.readId();
            System.Console.WriteLine("Sales ID: " + id);

            DateTime thisDay = DateTime.Today;
            System.Console.WriteLine("Sales Date: " + thisDay.ToString("dd/MM/yyyy"));

            System.Console.Write("Enter CustomerID: ");
            int custid;
            String c = System.Console.ReadLine();
            if (c.Length != 0)
            {
                custid = int.Parse(c);
            }
            else
            {
                custid = 0;
            }

            CustomerBLL custB = new CustomerBLL();
            CustomerBO custO = custB.find(custid);
            int choice=0;

            if (custO.Custid != 0)
            {
                List<SaleLineItemBO> lineList = new List<SaleLineItemBO>();

                SaleLineItemBLL lineBI = new SaleLineItemBLL(); //I-initial
                SaleLineItemBO lineitemI = makenewSale();



                if (lineitemI.Itemid != 0)
                {
                    lineitemI.Lineid = lineBI.readId();
                    lineBI.updateId(lineitemI.Lineid + 1);

                    lineitemI.Orderid = id;
                    lineitemI.Amount = lineBI.calculatesubTotal(lineitemI);
                    System.Console.WriteLine("Sub-Total: Rs." + lineitemI.Amount);
                    lineList.Add(lineitemI);


                }


                while (choice != 4)
                {

                    System.Console.WriteLine("\nPress 1 to Enter New Item");
                    System.Console.WriteLine("Press 2 to End Sale");
                    System.Console.WriteLine("Press 3 to Remove an existing Item from the current sale");
                    System.Console.WriteLine("Press 4 to Cancel Sale");
                    System.Console.WriteLine("Choose from option 1 – 4:");

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

                    while (choice < 1 || choice > 4)
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
                        SaleLineItemBLL lineB = new SaleLineItemBLL();
                        SaleLineItemBO lineitem = makenewSale();


                        if (lineitem.Itemid != 0)
                        {
                            lineitem.Lineid = lineB.readId();
                            lineB.updateId(lineitem.Lineid + 1);

                            lineitem.Orderid = id;
                            lineitem.Amount = lineB.calculatesubTotal(lineitem);
                            System.Console.WriteLine("Sub-Total: Rs."+lineitem.Amount);

                            lineList.Add(lineitem);
                        }



                    }
                    else if (choice == 2)
                    {
                        SaleLineItemBLL lineB = new SaleLineItemBLL();
                        if (lineList.Count > 0)
                        {
                            sale.Orderid = id;
                            sale.Date = thisDay.ToString("dd/MM/yyyy");
                            sale.Custid = custO.Custid;
                            sale.Total = saleB.calculateTotal(lineList);

                            if (saleB.checkSaleLimit(sale))
                            {
                                lineB.save(lineList);
                                saleB.save(sale);

                                displayInvoice(sale, lineList);
                            }
                            else
                            {
                                Console.Clear();
                                System.Console.WriteLine("\n\n\n\n\n\n ***Error! Sale Limit Exceeded***");
                                System.Threading.Thread.Sleep(2000);
                            }
                                       
                               
                        }
                        lineB.updateId(1);
                        break;

                    }
                    else if (choice == 3)
                    {
                        int itemid; bool flag = true;
                        System.Console.Write("\nEnter ItemID to be removed: ");
                        c = System.Console.ReadLine();
                        if (c.Length != 0)
                        {
                            itemid = int.Parse(c);
                        }
                        else
                        {
                            itemid = 0;
                        }

                        List<SaleLineItemBO> removeList = new List<SaleLineItemBO>();
                        foreach (var line in lineList)
                        {

                            if (line.Itemid == itemid)
                            {
                                removeList.Add(line);
                                flag = false;
                            }

                        }

                        foreach (var line in removeList)
                        {

                            lineList.Remove(line);

                        }

                        if (flag)
                        {
                            System.Console.WriteLine("Error! Item not included in sale");

                        }


                   }

                    else if (choice == 4)
                    {
                        SaleLineItemBLL lineB = new SaleLineItemBLL();
                        lineB.updateId(1);
                    }


                }


               
            }
            else
            {
                Console.Clear();
                System.Console.WriteLine("\n\n\n\n\n\n ***Error! Customer Not Found***");
                System.Threading.Thread.Sleep(2000);
            }
            

        }


        public SaleLineItemBO makenewSale()
        {
            SaleLineItemBO lineItem=new SaleLineItemBO();
            System.Console.Write("\nItem Id: ");
            int itemid;
            String c = System.Console.ReadLine();
            if (c.Length != 0)
            {
                itemid = int.Parse(c);
            }
            else
            {
                itemid = 0;
            }
            ItemBLL itemB = new ItemBLL();
            ItemBO itemO = itemB.find(itemid);
            int q = 0;

            if (itemO.Itemid != 0)
            {
                System.Console.WriteLine("\nDescription: " + itemO.Description);
                System.Console.WriteLine("Price: Rs." + itemO.Price + ".00");
                System.Console.Write("Quantity: ");

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

                if (q <= itemO.Quantity)
                {
                    lineItem.Itemid = itemO.Itemid;
                    lineItem.Quantity = q;
                    lineItem.Amount = itemO.Price; //sets unit price of item
                }
                else
                {
                    System.Console.WriteLine("Stock quantity Not Available");
                }


            }
            else
            {
                System.Console.WriteLine("Error! Item not found");
            }


            return lineItem;

        }


        public void displayInvoice(SaleBO sale, List<SaleLineItemBO> linelist)
        {
            bool flagS = true;
            Console.Clear();
            System.Console.WriteLine("Invoice:-\n\n\n");

            System.Console.Write("Sales ID: "+sale.Orderid.ToString().PadRight(40));
            System.Console.Write("Customer ID: " + sale.Custid.ToString().PadRight(20)+"\n\n");

            System.Console.Write("Sales Date: " + sale.Date.PadRight(40));

            CustomerBLL custB = new CustomerBLL();
            CustomerBO custO = custB.find(sale.Custid);

            System.Console.Write("Name: " + custO.Name.ToString().PadRight(20) + "\n");

            ItemBLL itemB = new ItemBLL();

            foreach (var i in linelist)
            {
                if (flagS)
                {
                    System.Console.WriteLine("\n----------------------------------------------------");
                    System.Console.WriteLine("Item ID".PadRight(10) + "Description".PadRight(20) + "Quantity".PadRight(10) + "Amount".PadRight(20));
                    System.Console.WriteLine("----------------------------------------------------");
                    flagS = false;
                }
                ItemBO itemO = itemB.find(i.Itemid);
                System.Console.WriteLine(i.Itemid.ToString().PadRight(10) + itemO.Description.PadRight(20) + i.Quantity.ToString().PadRight(10) + i.Amount.ToString().PadRight(20));


            }
            System.Console.WriteLine("----------------------------------------------------");
            System.Console.WriteLine("".PadRight(37)+"Total: Rs."+sale.Total);
            System.Console.WriteLine("----------------------------------------------------\n");
            System.Console.WriteLine("Press any key to continue ...");
            System.Console.ReadLine();

        }

        




    }
}
