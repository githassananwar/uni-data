using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BO
{
    public class ItemBO
    {
        private int itemid;
        private String description;
        private double price;
        private int quantity;
        private String date;

        

        public int Itemid
        {
            get { return itemid; }
            set { itemid = value; }
        }

        public String Description
        {
            get { return description; }
            set { description = value; }
        }

        public double Price
        {
            get { return price; }
            set { price = value; }
        }


        public int Quantity
        {
            get { return quantity; }
            set { quantity = value; }
        }

        public String Date
        {
            get { return date; }
            set { date = value; }
        }

    }
}
