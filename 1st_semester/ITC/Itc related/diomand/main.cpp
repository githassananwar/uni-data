#include <iostream>

using namespace std;

int main()
{
    int cc=1,cr=1,nc=0,nr=0,chk=0,pntc=0,pntr=0,chklow=0;
    cout<<"Enter odd rows:"<<endl;
    cin>>nr;
    cout<<"Enter same columns:"<<endl;
    cin>>nc;
    pntc=(nc/2)+1;
    pntr=(nr/2)+1;


    while(cr<=nr)
    {
        cc=1;


        while(cc<=nc)
        {

            //upper part
            if(cr<=pntr)
            {

            if((cc==pntc-chk)||cc==(pntc+chk))
            {
                cout<<"*";
                chklow=chk;

            }
            else
            {
                cout<<" ";
                chklow=chk;

            }
            }

           //lower part

            if(cr>pntr)
            {
                if(cc==pntc-chklow||cc==pntc+chklow)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

            }

            cc++;

        }


         cout<<endl;
         chk++;
         cr++;
         chklow=chklow-1;//decrease by 1 at start from chk value coming from up to run for cr>pntr
    }






    return 0;
}
