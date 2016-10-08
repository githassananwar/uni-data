#include <iostream>

using namespace std;

int main()
{
while(1)
{


    int n=0,count=0;
    cout<<"Enter number:"<<endl;
    cin>>n;
    while(count<n)
    {
        if(count*count==n)
        {
            cout<<"Square root is "<<count<<endl
        }
        count=count+1;
    }
}
    return 0;
}
