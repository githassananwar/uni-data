#include <iostream>

using namespace std;

int main()
{
    char code[41];
    char ch, check='a';

    int times=0;

    cout<<"Enter statement: ";
    cin.getline(code,41);

    cout<<"Enter letter: ";
    cin>>ch;

    for(int count=0;(count<41&&check!='\0');count++)
    {

        check=code[count];


        if(check==ch)
        {
            times++;
        }



    }

    cout<<"Times repeated: "<<times<<endl;



    return 0;
}



