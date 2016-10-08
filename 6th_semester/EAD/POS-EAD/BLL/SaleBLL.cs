using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using DAL;
using BO;


namespace BLL
{
    public class SaleBLL
    {
        public int readId()
        {
            SaleDAL item = new SaleDAL();
            return item.readId();
        }

        public double calculateTotal(List<SaleLineItemBO> linelist)
        {
            double total = 0;
            foreach (var line in linelist)
            {
                total = total + line.Amount;

            }

            return total;

        }

        public void save(SaleBO sale)
        {

            CustomerDAL custD = new CustomerDAL();
            CustomerBO customer = custD.search(sale.Custid);

            customer.Amount = customer.Amount + sale.Total;
            custD.modify(customer);

            SaleDAL s = new SaleDAL();
            s.updateId(sale.Orderid + 1);
            s.save(sale);

        }

        public bool checkSaleLimit(SaleBO sale)
        {
            SaleDAL saleD=new SaleDAL();
            CustomerDAL custD = new CustomerDAL();
            CustomerBO customer = custD.search(sale.Custid);

            if (saleD.checkDailySale(sale) + sale.Total <= customer.Slimit)
            {
                return true;
            }

            return false;

        }

        public SaleBO find(int id)
        {
            SaleDAL sale = new SaleDAL();
            return sale.search(id);

        }


    }
}
