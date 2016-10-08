using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using BO;

namespace DAL
{
    public class ReceiptDAL
    {
        public int readId()
        {
            FileStream fin = new FileStream("receiptid.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String id = sr.ReadLine();

            sr.Close();
            fin.Close();

            return int.Parse(id);

        }

        public void updateId(int id)
        {
            FileStream fout = new FileStream("receiptid.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fout);
            System.Console.WriteLine(id);
            sw.Write(id);

            sw.Close();
            fout.Close();
        }

        public void save(ReceiptBO rec)
        {
            FileStream fout = new FileStream("receiptdata.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fout);
            sw.WriteLine(rec.Receiptid + ";" + rec.Receiptdate + ";" + rec.Orderid + ";" + rec.Amountpaid);

            sw.Close();
            fout.Close();
        }

        public double calculateAmountPaid(int saleid)
        {
            double amountpaid = 0;
            FileStream fin = new FileStream("receiptdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);

            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                if (int.Parse(data[2]) == saleid)
                {
                    amountpaid = amountpaid + double.Parse(data[3]);
                }

            }

            sr.Close();
            fin.Close();

            return amountpaid;

        }

    }
}
