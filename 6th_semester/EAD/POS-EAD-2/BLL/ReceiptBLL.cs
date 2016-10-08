using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using DAL;
using BO;

namespace BLL
{
    public class ReceiptBLL
    {
        public int readId()
        {
            ReceiptDAL rec = new ReceiptDAL();
            return rec.readId();
        }

        public void save(ReceiptBO rec)
        {
            ReceiptDAL recDAL = new ReceiptDAL();
            DateTime thisDay = DateTime.Today;
            rec.Receiptdate = thisDay.ToString("dd/MM/yyyy");

            recDAL.save(rec);
        }

        public double amountpaid(int saleid)
        {
            ReceiptDAL rec = new ReceiptDAL();
            return rec.calculateAmountPaid(saleid);
        }

    }


}
