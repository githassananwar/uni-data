using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Helpers;
using finalProject.Models;

namespace EadProject.Controllers
{
    public class BecomeADonorController : Controller
    {
        IDonor o;
        public BecomeADonorController(IDonor i)
        {
            o = i;
        }
        //
        // GET: /BecomeADonor/
     
        public ActionResult donor()
        {
            return View();
        }
        [HttpPost]
        public ActionResult add(Donor d)
        {
            
            d.DOB=Request["day"]+Request["mon"]+Request["year"];

            d.SourcePath = "../../" + Session["opo"].ToString();

            o.save(d);
            return RedirectToAction("donor"); 
        }
        public void save()
        {

        }
    }
}
