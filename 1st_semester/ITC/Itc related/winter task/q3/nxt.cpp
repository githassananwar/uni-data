#include<iostream>

using namespace std;



int main()
{




int n=0,nxt=0,f1=0,f2=1, count=0,fst=0,scnd=0,rnxt=0;
cout<<"Enter number"<<endl;
cin>>n;

while(count<n-2)
{



        nxt=f1+f2;
        count=count+1;
        if(count!=n-2)
        {
        f1=f2;
        f2=nxt;
        }


}
fst=nxt;
scnd=f2;
count=0;
cout<<fst<<","<<scnd<<",";

while(count<n-2)
{

   rnxt=fst-scnd;
   fst=scnd;
   scnd=rnxt;
   cout<<rnxt<<",";
   count=count+1;

}



return 0;



}
