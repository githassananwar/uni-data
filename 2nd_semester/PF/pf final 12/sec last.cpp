#include <iostream>

using namespace std;

double* extractPositives (double* , int , int&);

int main()
{
    double arr[10]={2,3.4,4,6,7,7.65,11.92};
    int newsize=0, i=0;

    double *ptr=extractPositives (arr,10,newsize);

    for(i=0;i<newsize;i++)
    {
        cout<<ptr[i]<<"  ";
    }

    return 0;
}

double* extractPositives (double* original, int origSize, int& newSize)
{

    int i, countp=0, index=0;
    for(int i=0;i<origSize;i++)
    {
        if(original[i]>0)
        {
            countp++;

        }
    }

    newSize=countp;

    double *newarr=new double[countp];

    for(i=0;i<origSize;i++)
    {
        if(original[i]>0)
        {
            newarr[index]=original[i];
            index++;
        }
    }


    return newarr;






}
