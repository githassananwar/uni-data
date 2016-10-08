#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int h=0,p=0,b=0;
    cout<<"Enter hypotenuse length:";
    cin>>h;
    cout<<endl<<"Enter base length:";
    cin>>b;
    cout<<endl<<"Enter perpendicular length:";
    cin>>p;
    if(pow(h,2)==pow(b,2)+pow(p,2))
    {
        cout<<endl<<"It's a Right angle triangle. . "<<endl;
    }
    else
    {
        cout<<endl<<"It's Not a right angle triangle. ."<<endl;
    }

    return 0;
}
