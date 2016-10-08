using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using DAL;
using BO;

namespace BLL
{
    public class ItemBLL
    {
        public int readId()
        {
            ItemDAL item = new ItemDAL();
            return item.readId();
        }

        public void save(ItemBO itemBO)
        {
            ItemDAL item = new ItemDAL();
            DateTime thisDay = DateTime.Today;
            itemBO.Date = thisDay.ToString("dd/MM/yyyy");

            item.updateId(itemBO.Itemid + 1);
            item.save(itemBO);
        }

        public ItemBO find(int id)
        {
            ItemDAL item = new ItemDAL();
            return item.search(id);
               
        }

        public void modify(ItemBO itemBO)
        {
            ItemDAL item = new ItemDAL();
            item.modify(itemBO);

        }

        public List<ItemBO> find(ItemBO itemBO)
        {
            ItemDAL item = new ItemDAL();
            return item.search(itemBO);

        }

        public void remove(ItemBO itemBO)
        {
            ItemDAL item = new ItemDAL();
            item.remove(itemBO);
        }

        

    }
}
