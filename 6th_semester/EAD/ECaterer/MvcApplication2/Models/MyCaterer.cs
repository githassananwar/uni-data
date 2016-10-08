using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcApplication2.Models
{
    public class MyCaterer : ICaterer
    {
        //
        // GET: /MyCaterer/
        public user getUserById(int? id)
        {
            user u = null;
            using (Database1Entities4 f = new Database1Entities4())
            {
                u = f.users.First(x => x.Id == id);
            }
            return u;
        }

        public void remove(int id)
        {
            using (Database1Entities4 f = new Database1Entities4())
            {
                caterer obj = f.caterers.First(x => x.Id == id);
                f.caterers.DeleteObject(obj);
                f.SaveChanges();
            }
        }

        public void add(caterer u , int i)
        {
            user usr = null;
            using (Database1Entities4 f = new Database1Entities4())
            {
                usr = f.users.First(x => x.Id == i);
                u.user = usr;
                usr.caterers.Add(u);
                f.caterers.AddObject(u);
                f.SaveChanges();
            }
        }

       public List<caterer> view ()
        {
            Database1Entities4 d = new Database1Entities4();
            return d.caterers.ToList();
        }

       public caterer detail(int id)
       {
           Database1Entities4 d = new Database1Entities4();
           return d.caterers.First(x => x.Id == id);
       }

       public List<caterer> find(caterer u)
       {
           Database1Entities4 d = new Database1Entities4();
           List<caterer> list = d.caterers.Where(x => (x.name == u.name) || (x.city == u.city)).ToList();
           return list;
       }

      
       
    }
}
