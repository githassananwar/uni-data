using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

using BO;

namespace DAL
{
    public class ItemDAL
    {
        public int readId()
        {
            FileStream fin = new FileStream("itemid.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String id = sr.ReadLine();

            sr.Close();
            fin.Close();

            return int.Parse(id);
            
        }

        public void updateId(int id)
        {
            FileStream fout = new FileStream("itemid.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fout);
            System.Console.WriteLine(id);
            sw.Write(id);

            sw.Close();
            fout.Close();
        }

        public void save(ItemBO item)
        {
            FileStream fout = new FileStream("itemdata.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fout);
            sw.WriteLine(item.Itemid+";"+item.Description+";"+item.Price+";"+item.Quantity+";"+item.Date);

            sw.Close();
            fout.Close();
        }


        public ItemBO search(int id)
        {
            ItemBO item = new ItemBO();
            FileStream fin = new FileStream("itemdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');
                if (int.Parse(data[0]) == id)
                {
                    item.Itemid = int.Parse(data[0]);
                    item.Description = data[1];
                    item.Price = double.Parse(data[2]);
                    item.Quantity = int.Parse(data[3]);
                    item.Date = data[4];
                    break;
                }
            }

            sr.Close();
            fin.Close();

            return item;


        }

        public void modify(ItemBO item)
        {
            List<ItemBO> list = new List<ItemBO>();

            FileStream fin = new FileStream("itemdata.txt", FileMode.Open);   
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');

                ItemBO io = new ItemBO();
                io.Itemid = int.Parse(data[0]);
                io.Description = data[1];
                io.Price = double.Parse(data[2]);
                io.Quantity = int.Parse(data[3]);
                io.Date = data[4];


                list.Add(io);
            }

            sr.Close();
            fin.Close();

            //Overwriting
            fin = new FileStream("itemdata.txt", FileMode.Create);
            fin.Close();

            foreach (var i in list)
            {
                if (i.Itemid == item.Itemid)
                {
                    save(item);
                }
                else
                {
                    save(i);
                }

            }


        }


        public List<ItemBO> search(ItemBO item)
        {
            List<ItemBO> list = new List<ItemBO>();
            FileStream fin = new FileStream("itemdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';'); 
                bool flag=true;
                if(item.Itemid!=0 )
                {
                    if (int.Parse(data[0]) != item.Itemid)
                    {
                        flag = false;
                    }
                   
                }
                if (item.Description != null)
                {
                    if (data[1] != item.Description)
                    {
                        flag = false;
                    }

                }
                if (item.Price != 0)
                {
                    if (double.Parse(data[2]) != item.Price)
                    {
                        flag = false;
                    }

                }
                if (item.Quantity != 0)
                {
                    if (int.Parse(data[3]) != item.Quantity)
                    {
                        flag = false;
                    }

                }
                if (item.Date != null)
                {
                    if (data[4] != item.Date)
                    {
                        flag = false;
                    }

                }

                if (flag)
                {
                    ItemBO itemFound = new ItemBO();
                    itemFound.Itemid = int.Parse(data[0]);
                    itemFound.Description = data[1];
                    itemFound.Price = double.Parse(data[2]);
                    itemFound.Quantity = int.Parse(data[3]);
                    itemFound.Date = data[4];

                    list.Add(itemFound);

                }

            }
            

            sr.Close();
            fin.Close();

            return list;


        }


        public void remove(ItemBO item)
        {
            List<ItemBO> list = new List<ItemBO>();

            FileStream fin = new FileStream("itemdata.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fin);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                String[] data = line.Split(';');

                ItemBO io = new ItemBO();
                io.Itemid = int.Parse(data[0]);
                io.Description = data[1];
                io.Price = double.Parse(data[2]);
                io.Quantity = int.Parse(data[3]);
                io.Date = data[4];


                list.Add(io);
            }

            sr.Close();
            fin.Close();

            //Overwriting
            fin = new FileStream("itemdata.txt", FileMode.Create);
            fin.Close();

            foreach (var i in list)
            {
                if (!(i.Itemid == item.Itemid))
                {
                    save(i);
                }
                
            }

        }


    }
}
