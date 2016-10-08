using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using finalProject.Models;

namespace finalProject.Controllers
{
    public class BloodRequestController : Controller
    {
        //
        // GET: /BloodRequest/

        public ActionResult bloodRequest()
        {
            return View();
        }
        [HttpPost]
        public ActionResult addRequest(Accepter a)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            f.Accepters.AddObject(a);
            f.SaveChanges();
            return RedirectToAction("bloodRequest");
        }
    }
}
