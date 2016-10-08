using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcApplication2.Models;

namespace  MvcApplication2.Controllers
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

        public ActionResult Index()
        {
            return View();
        }

        

        public ViewResult Contact()
        {
            return View();
        }

        public ViewResult Login()
        {
            return View();
        }

        public ViewResult SignUp()
        {
            return View();
        }
    
        public ViewResult AboutUs()
        {
            return View();
        }

        [HttpPost]
        public ActionResult sendMessage(contact c)
        {
            o.send(c);
            return RedirectToAction("Index");
        }

        [HttpPost]
        public ActionResult addUser(user u)
        { 
            o.add(u);
            return RedirectToAction("Login");
        }

        [HttpPost]
        public ActionResult SignIn()
        {
            List<user> list = null;
            if (ModelState.IsValid)
            {
                string u = Request["Username"];
                string p = Request["Password"];
                list = o.signIn(u, p);

                if (list.Count != 0)
                {
                    Session["Username"] = list.ElementAt(0).username;
                    Session["uId"] = list.ElementAt(0).Id;
                    Session["signin"] = "done";
                    Session["soButton"] = "true";
                    Session["info"] = "true";
                }
                else
                {
                    Session["info"] = "false";
                    return RedirectToAction("Login", "Home");
                }
            }
            if (list.Count != 0 && list.ElementAt(0).rank == "Admin")
            {
                return RedirectToAction("blank", "Admin");
            }
            return RedirectToAction("Index", "Home");
        }

        public ActionResult logout()
        {
            Session["signin"] = null;
            Session["soButton"] = "false";
            return RedirectToAction("Index", "Home");
        }

        public JsonResult check(String n)
        {
            return this.Json(o.checkNIC(n), JsonRequestBehavior.AllowGet);
        }

    }
}
