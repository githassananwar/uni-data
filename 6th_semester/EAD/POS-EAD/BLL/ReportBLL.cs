using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using DAL;
using BO;

namespace BLL
{
    public class ReportBLL
    {
        public List<ItemBO> stockView()
        {
            ReportDAL report = new ReportDAL();
            return report.searchItem();
        }

        public List<CustomerBO> custView()
        {
            ReportDAL customer = new ReportDAL();
            return customer.searchCustomer();

        }


    }
}
