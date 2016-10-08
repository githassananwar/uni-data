using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using finalProject.Models;
namespace EadProject.Controllers
{
    public class ContactUsController : Controller
    {
        //
        // GET: /ContactUs/

        public ActionResult contactUs()
        {
            return View();
        }
        [HttpPost]
        public ActionResult addContact(Contact c)
        {
            finalDataBaseEntities2 f = new finalDataBaseEntities2();
            f.Contacts.AddObject(c);
            f.SaveChanges();
            return RedirectToAction("contactUs");
        }

    }
}
