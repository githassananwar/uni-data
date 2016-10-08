using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using BO;

namespace DAL
{
    public class SaleDAL
    {
        public int readId()
        {
            FileStream fin = new FileStream("saleid.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String id = sr.ReadLine();

            sr.Close();
            fin.Close();

            return int.Parse(id);

        }


        public void updateId(int id)
        {
            FileStream fout = new FileStream("saleid.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fout);
            System.Console.WriteLine(id);
            sw.Write(id);

            sw.Close();
            fout.Close();
        }

        public void save(SaleBO sale)
        {
            FileStream fout = new FileStream("saledata.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fout);
            sw.WriteLine(sale.Orderid + ";" + sale.Custid + ";" + sale.Date + ";" + sale.Status + ";" + sale.Total);

            sw.Close();
            fout.Close();
        }

        public double checkDailySale(SaleBO sale)
        {
            double dailySale=0;
            FileStream fin = new FileStream("saledata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);

            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                if (int.Parse(data[1]) == sale.Custid && data[2] == sale.Date)
                {
                    dailySale = dailySale + double.Parse(data[4]);
                }

            }

            sr.Close();
            fin.Close();

            return dailySale;
        }

        public SaleBO search(int id)
        {
            SaleBO sale = new SaleBO();
            FileStream fin = new FileStream("saledata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                if (int.Parse(data[0]) == id)
                {
                    sale.Orderid = int.Parse(data[0]);
                    sale.Custid = int.Parse(data[1]);
                    sale.Date = data[2];
                    sale.Status = data[3];
                    sale.Total = double.Parse(data[4]);
                    
                    break;
                }
            }

            sr.Close();
            fin.Close();

            return sale;


        }

    }
}
