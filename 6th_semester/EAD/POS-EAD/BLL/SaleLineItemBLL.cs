using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using DAL;
using BO;

namespace BLL
{
    public class SaleLineItemBLL
    {
        public int readId()
        {
            SaleLineItemDAL saleLine = new SaleLineItemDAL();
            return saleLine.readId();
        }

        public void updateId(int id)
        {
            SaleLineItemDAL saleLine = new SaleLineItemDAL();
            saleLine.updateId(id);
        }

        public double calculatesubTotal(SaleLineItemBO lineitem)
        {
            return lineitem.Quantity * lineitem.Amount;
        }

        public void save(List<SaleLineItemBO> linelist)
        {

            ItemDAL itemD = new ItemDAL();
            foreach (var line in linelist)
            {
                ItemBO i = itemD.search(line.Itemid);
                i.Quantity = i.Quantity-line.Quantity;
                itemD.modify(i);

            }
            SaleLineItemDAL saleLine = new SaleLineItemDAL();
            saleLine.save(linelist);
        }

    }
}
