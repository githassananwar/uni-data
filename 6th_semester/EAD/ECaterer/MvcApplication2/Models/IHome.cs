using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcApplication2.Models
{
    public interface IHome
    {
        List<user> signIn(string u, string p);
        void add(user u);
        void send(contact c);

        Boolean checkNIC(String n);
    }
        
}
