#include <iostream>

using namespace std;

int main()
{
    int n=0,count=2,result=0,chk=0;
    cout<<"Enter number:"<<endl;
    cin>>n;

    while(count<n)
    {
        if(n%count==0)
        {
           chk=n;
        }
        count=count+1;

    }
    if(chk==0)
    {
        cout<<"Prime"<<endl;
    }
    else
    {
        cout<<"Not prime"<<endl;
    }
}
