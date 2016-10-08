using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BO
{
    public class SaleBO
    {
        private int orderid;
        private int custid;
        private String date;
        private String status;
        private double total;
       


        public int Orderid
        {
            get { return orderid; }
            set { orderid = value; }
        }

        public int Custid
        {
            get { return custid; }
            set { custid = value; }
        }

        public String Date
        {
            get { return date; }
            set { date= value; }
        }

        public String Status
        {
            get { return status; }
            set { status = value; }
        }

        public double Total
        {
            get { return total; }
            set { total = value; }
        }


    }
}
