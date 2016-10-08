using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Helpers;
using finalProject.Models;

namespace EadProject.Controllers
{
    public class HomeController : Controller
    {
        //
        // GET: /Home/

        IHome o;
        public HomeController(IHome i)
        {
            o = i;
        }

        public ActionResult HtmlPage1()
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            var x = (from y in f.Accepters
                     select y).ToList();
            ViewBag.mydata = x;
            return View();
        }

        public ActionResult SignUp()
        {
            return View();
        }
        [HttpPost]
        public ActionResult find(Donor d)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            var x = (from y in f.Accepters
                     select y).ToList();
            ViewBag.mydata = x;
            int c = 0;
            ViewBag.cont = c;
            Session["bdgroup"] = d.BloodGroup;
            Session["cty"] = d.City;
            return View(o.search(d));
        }
        [HttpPost]
        public ActionResult SignIn()
        {
            List<Donor> list=null;
            if (ModelState.IsValid)
            {
                string u = Request["usname"];
                string p = Request["pwd"];
                list = o.sign(u,p);

                if (list.Count != 0)
                {
                    Session["uid"] = list.ElementAt(0).DonorId;
                    Session["uname"] = list.ElementAt(0).Name;
                    Session["signin"] = "done";
                }
                else
                {
                    Session["abc"] = "wrong";
                }
                
            }
            if (list.Count != 0 && list.ElementAt(0).rank == "Admin")
            {
                return RedirectToAction("index", "Admin");
            }

            return RedirectToAction("HtmlPage1", "Home");
        }

        public ActionResult logout()
        {
            Session["signin"] = null;
            return RedirectToAction("HtmlPage1", "Home");
        }

        public JsonResult check(String n)
        {
            return this.Json(o.checkIt(n), JsonRequestBehavior.AllowGet);
        }

        public JsonResult checkPWD(String n, String p)
        {
            return this.Json(o.checkPWD(n, p), JsonRequestBehavior.AllowGet);
        }
        public ActionResult UpdateInfo()
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            int id = int.Parse(Session["uid"].ToString());
            Donor y = f.Donors.First(x => x.DonorId == id);
            return View(y);
        }
        public ActionResult upInfo(Donor d)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            int id = int.Parse(Session["uid"].ToString());
            Donor y = f.Donors.First(x => x.DonorId == id);
            y.Name = d.Name;
            y.City = d.City;
            y.Email = d.Email;
            y.Address = d.Address;
            y.Contact = d.Contact;
            if (d.Password != null)
            {
                y.Password = d.Password;
            }
            if (Session["opo"] != "")
            {
                y.SourcePath = "../../" + Session["opo"].ToString();
            }
            f.SaveChanges();
            Session["uname"] = y.Name;
            return RedirectToAction("HtmlPage1", "Home");
        }
    }
}
