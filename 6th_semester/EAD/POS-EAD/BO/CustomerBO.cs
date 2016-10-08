using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BO
{
    public class CustomerBO
    {
        private int custid;
        private String name;
        private String address;
        private String phone;
        private String email;
        private int slimit;
        private double amount;


        public int Custid
        {
            get { return custid; }
            set { custid = value; }
        }

        public String Name
        {
            get { return name; }
            set { name = value; }
        }

        public String Address
        {
            get { return address; }
            set { address = value; }
        }

        public String Phone
        {
            get { return phone; }
            set { phone = value; }
        }


        public String Email
        {
            get { return email; }
            set { email = value; }
        }

        public int Slimit
        {
            get { return slimit; }
            set { slimit = value; }
        }

        public double Amount
        {
            get { return amount; }
            set { amount = value; }
        }

    }
    
}
