using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

using BO;

namespace DAL
{
    public class ReportDAL
    {
        public List<ItemBO> searchItem()
        {
            List<ItemBO> list = new List<ItemBO>();
            FileStream fin = new FileStream("itemdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
               
                ItemBO itemFound = new ItemBO();
                itemFound.Itemid = int.Parse(data[0]);
                itemFound.Description = data[1];
                itemFound.Price = double.Parse(data[2]);
                itemFound.Quantity = int.Parse(data[3]);
                itemFound.Date = data[4];

                list.Add(itemFound);

             }

         
        

            sr.Close();
            fin.Close();

            return list;


        }


        public List<CustomerBO> searchCustomer()
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

            return list;


        }





    }
}
