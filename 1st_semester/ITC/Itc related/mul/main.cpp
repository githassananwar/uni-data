#include <iostream>

using namespace std;

int main()
{
   int n=0,m=0,c=0,ans=0;
   cout<<"Enter number and multiple:"<<endl;
   cin>>n>>m;
   while(c<m)
   {
       ans=ans+n;
       c++;
   }
   cout<<"Answer= "<<ans;
    return 0;
}
