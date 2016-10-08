using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Helpers;

using MvcApplication2.Models;

namespace MvcApplication2.Controllers
{
    public class AdminController : Controller
    {
        ICaterer i;
        //
        // GET: /Admin/
        public AdminController(ICaterer j)
        {
            i = j;
        }
        public ActionResult blank()
        {
            return View(i.view());
        }

        public ActionResult charts()
        {
            return View();
        }

        public ActionResult index()
        {
            Database1Entities4 d = new Database1Entities4();
            return View( d.contacts.ToList());
        }

        public ActionResult indexrtl()
        {
            return View();
        }

        public ActionResult tables()
        {
            return View();
        }

        public ActionResult removePost(int id)
        {
            i.remove(id);
            return RedirectToAction("blank", "Admin");
        }




        //public ActionResult addBus()
        //{
        //    HttpPostedFileBase file = Request.Files[0];
        //    if (file != null && file.ContentLength > 0)
        //    {
        //        file.SaveAs(Server.MapPath(@"~/img/" + file.FileName));
        //    }

        //    Bus b = new Bus();
        //    b.Name = Request["name"];
        //    b.Percentage = int.Parse(Request["percent"]);
        //    b.TimeSlots = Request["slot"];
        //    b.Seats = int.Parse(Request["seat"]);
        //    b.Description = Request["desc"];
        //    b.Rent = Request["rent"];
        //    b.SourcePath = "../../img/" + file.FileName;
        //    i.add(b);
        //    return RedirectToAction("blank", "Admin");
        //}

        //public ActionResult removeBus(int id)
        //{
        //    i.remove(id);
        //    return RedirectToAction("blank", "Admin");
        //}
    }
}
