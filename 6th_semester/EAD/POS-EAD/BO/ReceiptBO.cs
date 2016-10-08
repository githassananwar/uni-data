using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BO
{
    public class ReceiptBO
    {
        private int receiptid;
        private String receiptdate;
        private int orderid;
        private double amountpaid;

        public int Receiptid
        {
            get { return receiptid; }
            set { receiptid = value; }
        }

        public String Receiptdate
        {
            get { return receiptdate; }
            set { receiptdate = value; }
        }

        public int Orderid
        {
            get { return orderid; }
            set { orderid = value; }
        }

        public double Amountpaid
        {
            get { return amountpaid; }
            set { amountpaid = value; }
        }

    }
}
