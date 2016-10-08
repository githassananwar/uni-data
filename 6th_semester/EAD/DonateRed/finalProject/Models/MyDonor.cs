using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace finalProject.Models
{
    public class MyDonor: IDonor
    {
        public void save(Donor d)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            f.Donors.AddObject(d);
            f.SaveChanges();
        }
    }
}