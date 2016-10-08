using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using DAL;
using BO;


namespace BLL
{
    public class CustomerBLL
    {
        public int readId()
        {
            CustomerDAL Customer = new CustomerDAL();
            return Customer.readId();
        }

        public void save(CustomerBO customerBO)
        {
            CustomerDAL Customer = new CustomerDAL();
            customerBO.Amount = 0.0;

            Customer.updateId(customerBO.Custid + 1);
            Customer.save(customerBO);
        }

        public CustomerBO find(int id)
        {
            CustomerDAL Customer = new CustomerDAL();
            return Customer.search(id);

        }

        public void modify(CustomerBO CustomerBO)
        {
            CustomerDAL Customer = new CustomerDAL();
            Customer.modify(CustomerBO);

        }

        public List<CustomerBO> find(CustomerBO CustomerBO)
        {
            CustomerDAL Customer = new CustomerDAL();
            return Customer.search(CustomerBO);

        }

        public void remove(CustomerBO CustomerBO)
        {
            CustomerDAL Customer = new CustomerDAL();
            Customer.remove(CustomerBO);
        }
    }
}
