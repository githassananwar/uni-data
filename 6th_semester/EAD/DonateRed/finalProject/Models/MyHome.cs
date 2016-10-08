using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace finalProject.Models
{
    public class MyHome: IHome
    {
        public Boolean checkPWD(String cn, String p)
        {
            Donor a = null;
            using (finalDataBaseEntities2 c = new finalDataBaseEntities2())
            {
                a = c.Donors.FirstOrDefault(x => (x.Email == cn && x.Password == p));
            }

            if (a != null)
            {
                return true;
            }
            return false;
        }

        public Boolean checkIt(String n)
        {
            Donor a = null;
            using (finalDataBaseEntities2 c = new finalDataBaseEntities2())
            {
                a = c.Donors.FirstOrDefault(x => x.Email == n);
            }

            if (a != null)
            {
                return true;
            }
            return false;
        }

        public List<Accepter> getAllRequests()
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            return f.Accepters.ToList();
        }
        public List<Donor> getAllDonors()
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            return f.Donors.ToList();
        }
        public void removeDonor(int id)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            Donor d = f.Donors.First(x => x.DonorId == id);
            f.DeleteObject(d);
            f.SaveChanges();
        }
        public void removeRequest(int id)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            Accepter d = f.Accepters.First(x => x.AccepterId == id);
            f.DeleteObject(d);
            f.SaveChanges();
        }
        public List<Donor> search(Donor d)
        {
            List<Donor> list = null;// = c.properties.Where(x => (x.area == p.area && x.areaunit == p.areaunit && x.bedrooms == p.bedrooms && x.city == p.city && x.location == p.location && x.price == p.price && x.purpose == p.purpose && x.type == p.type)).ToList();
            using (finalDataBaseEntities2 c = new finalDataBaseEntities2())
            {
                IQueryable<Donor> query = c.Donors.Where(x => x.BloodGroup == d.BloodGroup);

                if (d.City != "All")
                {
                    query = query.Where(x => x.City == d.City);
                }
                list = query.ToList();
            }
            return list;
        }
        public List<Donor> sign(string u, string p)
        {
            using (finalDataBaseEntities2 f = new finalDataBaseEntities2())
            {
                List<Donor> list = f.Donors.Where(x => (x.Email == u && x.Password == p)).ToList();
                return list;
            }            
        }
    }
}