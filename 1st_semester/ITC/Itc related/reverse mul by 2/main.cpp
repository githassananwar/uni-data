#include <iostream>

using namespace std;

int main()
{
   int n=0,rem=0,ans=0;
   cout<<"Enter number:"<<endl;
   cin>>n;
   while(n!=0)
   {
       rem=n%10;
       ans=ans*10+rem;
       n=n/10;

   }
   cout<<ans;
    return 0;
}
