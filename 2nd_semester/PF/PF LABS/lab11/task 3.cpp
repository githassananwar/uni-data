#include<iostream>

using namespace std;

int doSomething(int* ,int* );

int main ()
{
	int n1=3,n2=4;
	int *ptr1=&n1;
	int *ptr2=&n2;

	doSomething(ptr1,ptr2);
    
	cout<<"n1 value: "<<*ptr1<<endl;
	cout<<"n2 value: "<<*ptr2<<endl;
	cout<<"Returned calculated value: "<<doSomething(ptr1,ptr2)<<endl;

    return 0;

}

int doSomething(int *ptr1, int *ptr2)
{
	int temp=*ptr1;
	*ptr1=*ptr2*10;
	*ptr2=temp*10;
	return *ptr1+*ptr2;
	

}