#include<iostream>

using namespace std;

void swap(int&, int&);

int main ()
{
    int a = 4, b = 8;

	cout << a << " " << b << endl; // should display 4 8 

	swap (a,b);

	cout << a << " " << b << endl; // should display 8 4

	return 0;
	
}

void swap (int &first, int &second)
{
	int reverse = 0;

	reverse = first;

	first = second;

	second = reverse;

}