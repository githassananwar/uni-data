using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using BO;


namespace DAL
{
    public class SaleLineItemDAL
    {
        public int readId()
        {
            FileStream fin = new FileStream("lineid.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String id = sr.ReadLine();

            sr.Close();
            fin.Close();

            return int.Parse(id);

        }

        public void updateId(int id)
        {
            FileStream fout = new FileStream("lineid.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fout);
            sw.Write(id);

            sw.Close();
            fout.Close();
        }

        public void save(List<SaleLineItemBO> linelist)
        {
            FileStream fout = new FileStream("linedata.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fout);

            foreach(var line in linelist)
            {
                sw.WriteLine(line.Lineid + ";" + line.Orderid + ";" + line.Itemid + ";" + line.Quantity + ";" + line.Amount);

            }

            sw.Close();
            fout.Close();
        }

    }
}
