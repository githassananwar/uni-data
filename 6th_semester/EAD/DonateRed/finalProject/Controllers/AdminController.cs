using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using finalProject.Models;
namespace finalProject.Controllers
{
    public class AdminController : Controller
    {
        IHome i;
        //
        // GET: /Admin/
        public AdminController(IHome j)
        {
            i = j;
        }
        public ActionResult Index()
        {
            return View();
        }
        public ActionResult blank()
        {
            ViewBag.req = i.getAllRequests();
            return View(i.getAllDonors());
        }
        public ActionResult charts()
        {
            return View();
        }
        public ActionResult indexrtl()
        {
            return View();
        }
        public ActionResult tables()
        {
            return View();
        }

        public ActionResult removeDonor(int id)
        {
            i.removeDonor(id);
            return RedirectToAction("blank", "Admin");
        }

        public ActionResult removeRequest(int id)
        {
            i.removeRequest(id);
            return RedirectToAction("blank", "Admin");
        }
    }
}
