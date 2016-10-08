#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
int findmax(char *[],int);

int main ()
{
    int i;
    char *arr[10];

    char arr1[10]="12";
    char arr2[10]="13";
    char arr3[10]="14";
    char arr4[10]="15";
    char arr5[10]="16";
    char arr6[10]="17";
    char arr7[10]="18";
    char arr8[10]="132";
    char arr9[10]="1123";
    char arr10[10]="1";


    arr[0]=arr1;
    arr[1]=arr2;
    arr[2]=arr3;
    arr[3]=arr4;
    arr[4]=arr5;
    arr[5]=arr6;
    arr[6]=arr7;
    arr[7]=arr8;
    arr[8]=arr9;
    arr[9]=arr10;

    cout<<"Result: "<<findmax(arr,10);

	return 0;

}

int findmax(char *arr[],int size)
{
    int i;
    int num[size];
    for(i=0;i<size;i++)
    {
        num[i]=atoi(arr[i]);
    }
    int max=0;
    max=num[0];

    for(i=1;i<size;i++)
    {
        if(num[i]>max)
        {
            max=num[i];
        }


    }

    return max;


}
