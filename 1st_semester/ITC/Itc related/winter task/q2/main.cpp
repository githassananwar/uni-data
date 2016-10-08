#include<iostream>

using namespace std;



int main()
{




int num=0,x=0, count=0, n=0, great=0, less=0, equal=0;
cout<<"Enter test number X"<<endl;
cin>>x;
cout<<"Enter number of inputs:"<<endl;
cin>>n;
cout<<"Enter "<<n<<" numbers:"<<endl;
while(count<n)
{
    cin>>num;
    if(num>x)
    {
        great=great+1;
    }
    if(num<x)
    {
        less=less+1;
    }
    if(num==x)
    {
        equal=equal+1;
    }
    count=count+1;
}
cout<<great<<" numbers are greater than "<<x<<endl;
cout<<less<<" numbers are less than "<<x<<endl;
cout<<equal<<" numbers are equal to "<<x<<endl;

return 0;



}
