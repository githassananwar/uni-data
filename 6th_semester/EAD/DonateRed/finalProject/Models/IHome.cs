using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace finalProject.Models
{
    public interface IHome
    {
        List<Donor> search(Donor d);
        List<Donor> sign(string u,string p);
        List<Accepter> getAllRequests();
        List<Donor> getAllDonors();


        void removeDonor(int id);
        void removeRequest(int id);

        Boolean checkIt(String n);
        Boolean checkPWD(String cn, String p);
    }
}
