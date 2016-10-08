using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcApplication2.Models
{
    public interface ICaterer
    {
        void add(caterer u , int i);
        List<caterer> view();
        caterer detail(int id);
        List<caterer> find(caterer u);
        void remove(int id);
        user getUserById(int? id);
    }
}
