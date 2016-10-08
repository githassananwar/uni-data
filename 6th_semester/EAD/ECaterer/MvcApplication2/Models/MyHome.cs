using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcApplication2.Models
{
    public class MyHome : IHome
    {
        //
        // GET: /MyHome/

        public Boolean checkNIC(String n)
        {
            user a = null;
            using (Database1Entities4 c = new Database1Entities4())
            {
                a = c.users.FirstOrDefault(x => x.username == n);
            }

            if (a != null)
            {
                return true;
            }
            return false;
        }

        public List<user> signIn(string u, string p)
        {
            using (Database1Entities4 f = new Database1Entities4())
            {
                List<user> list = f.users.Where(x => (x.username == u && x.password == p)).ToList();
                return list;
            }
        }

        public void add(user u)
        {
            Database1Entities4 f = new Database1Entities4();
            f.users.AddObject(u);
            f.SaveChanges();
        }

        public void send(contact c)
        {
            Database1Entities4 f = new Database1Entities4();
            f.contacts.AddObject(c);
            f.SaveChanges();
        }


        
    }
}
