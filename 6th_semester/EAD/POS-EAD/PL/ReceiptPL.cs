using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using BLL;
using BO;


namespace PL
{
    public class ReceiptPL
    {
        public void makepayment()
        {
            Console.Clear();
            System.Console.WriteLine("Payment\n\n");

            ReceiptBO rec = new ReceiptBO();
            ReceiptBLL recB = new ReceiptBLL();

            int recid = recB.readId();
            
            DateTime thisDay = DateTime.Today;

            System.Console.Write("Enter SaleID: ");
            int saleid;
            String c = System.Console.ReadLine();
            if (c.Length != 0)
            {
                saleid = int.Parse(c);
            }
            else
            {
                saleid = 0;
            }

            SaleBLL saleB = new SaleBLL();
            SaleBO saleO = saleB.find(saleid);

            CustomerBLL custB = new CustomerBLL();
            CustomerBO custO = custB.find(saleO.Custid);

            if (saleO.Orderid != 0)
            {
                double amountpaid=recB.amountpaid(saleid);
                double remain= saleO.Total-amountpaid;
                System.Console.WriteLine("Customer Name: "+custO.Name);
                System.Console.WriteLine("Total Sales Amount: " + saleO.Total);
                System.Console.WriteLine("Amount paid: " + amountpaid);
                System.Console.WriteLine("Remaining Amount: " +remain);
                System.Console.Write("Enter Amount: ");
                
                double amt;
                c = System.Console.ReadLine();
                if (c.Length != 0)
                {
                    amt = double.Parse(c);
                }
                else
                {
                    amt = 0;
                }

                while (amt < 0 || amt>remain)
                {
                    System.Console.Write("InValid Amount! Enter again: ");
                    c = System.Console.ReadLine();
                    if (c.Length != 0)
                    {
                        amt = double.Parse(c);
                    }
                    else
                    {
                        amt = 0;
                    }
                }

                if (remain > 0)
                {
                    custO.Amount = custO.Amount - amt;
                    custB.modify(custO);

                    rec.Receiptid = recid;
                    rec.Orderid = saleid;
                    rec.Amountpaid = amt;
                    recB.save(rec);
                }
                else
                {
                    System.Console.WriteLine("Back to Main Menu...");
                    System.Threading.Thread.Sleep(2000);

                }



            }

        }
    }

}
