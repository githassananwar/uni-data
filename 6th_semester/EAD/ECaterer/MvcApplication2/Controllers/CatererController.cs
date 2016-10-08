using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcApplication2.Models;

namespace MvcApplication2.Controllers
{
    public class CatererController : Controller
    {
        //
        // GET: /Caterer/
        ICaterer o;
        public CatererController(ICaterer i)
        {
            o = i;
        }


        public ViewResult AddCaterer()
        {
            return View();
        }

        [HttpPost]
        public ActionResult addNewCaterer(caterer u)
        {
            HttpPostedFileBase file = Request.Files[0];
            if (file != null && file.ContentLength > 0)
            {
                file.SaveAs(Server.MapPath(@"~/img/" + file.FileName));
            }
            u.image = "../../img/" + file.FileName;
            if (u.image == "../../img/")
            {
                //Image File uploading is compulsory.
                u.image = "../../img/7.jpg";
            }

            int i = int.Parse(Session["uId"].ToString());

            o.add(u , i);
            return RedirectToAction("ViewCaterer", "Caterer"); 
        }

   
        public ActionResult ViewCaterer()
        {
            return View(o.view());
        }

        public ActionResult updateCaterer()
        {
            Database1Entities4 d = new Database1Entities4();
            int i = int.Parse(Session["uId"].ToString());
            user u = d.users.First(x => x.Id == i);

            return View(u.caterers.ToList());
            
        }

        public ActionResult DetailCaterer(int id)
        {
            return View(o.detail(id));
        }

        public ActionResult findCaterer(caterer c)
        {
            return View(o.find(c));
        }

        public ActionResult updateInfo(int id)
        {
            Session["cId"] = id;
            return View(o.detail(id));
           
        }

        
        public ActionResult update(caterer c)
        {
            Database1Entities4 d = new Database1Entities4();
            int id = int.Parse(Session["cId"].ToString());
            caterer y = d.caterers.First(x => x.Id == id);
            y.name = c.name;
            y.address = c.address;
            y.city = c.city;
            y.description = c.description;
            y.email = c.email;
            y.fb = c.fb;
            y.note = c.note;
            y.perhead = c.perhead;
            y.phone = c.phone;
            y.services = c.services;
            y.social = c.social;
            y.twitter = c.twitter;
            d.SaveChanges();
            return RedirectToAction("Index", "Home");
        }



    }
}
