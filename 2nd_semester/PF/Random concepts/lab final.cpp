#include <iostream>

using namespace std;

void function(char*,char*);

int main()
{
    char str1[300]="Hassan";
    char str2[300]="Zindabad";

    function(str1,str2);
    cout<<str1<<endl;
    cout<<str2<<endl;


    return 0;
}

void function(char*first,char*second)
{
    char*ptr=0;
    int i=0;

    for(i=0;*(first+i)!='\0';i++)
    {
        ptr=first+i;

    }

    ptr=ptr+1;


    for(i=0;*(second+i)!='\0';i++)
    {

        *(ptr+i)=*(second+i);

    }
    
	ptr[i]='\0';



}




