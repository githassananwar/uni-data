using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BO
{
    public class SaleLineItemBO
    {
        private int lineid;
        private int orderid;
        private int itemid;
        private int quantity;
        private double amount;


        public int Lineid
        {
            get { return lineid; }
            set { lineid = value; }
        }

        public int Orderid
        {
            get { return orderid; }
            set { orderid = value; }
        }

        public int Itemid
        {
            get { return itemid; }
            set { itemid = value; }
        }

        public int Quantity
        {
            get { return quantity; }
            set { quantity = value; }
        }

        
        public double Amount
        {
            get { return amount; }
            set { amount = value; }
        }

        
    }
}
