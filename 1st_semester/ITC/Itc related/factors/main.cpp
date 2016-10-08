#include <iostream>

using namespace std;

int main()
{
    int n=0,count=1;
    cout<<"Enter number:"<<endl;
    cin>>n;
    cout<<"Factors are:"<<endl;
    while(count<=n)
    {
        if(n%count==0)
        {
            if(count<1000)
            {
                cout<<count<<endl;
            }
        }
        count=count+1;
    }
}
