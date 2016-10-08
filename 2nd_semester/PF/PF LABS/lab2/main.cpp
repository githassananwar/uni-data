#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{

	double test1=0,test2=0,test3=0,test4=0,test5=0;
	double avg=0, totMarks=0;

	cout << "Enter test 1 marks: ";
	cin >> test1;

	cout << "Enter test 2 marks: ";
	cin >> test2;

	cout << "Enter test 3 marks: ";
	cin >> test3;

	cout << "Enter test 4 marks: ";
	cin >> test4;

	cout << "Enter test 5 marks: ";
	cin >> test5;

	totMarks = test1+test2+test3+test4+test5;
	avg = totMarks/5;

	cout << endl << "Your test score average is: ";
	cout << setprecision(1) << fixed<<avg;

	cout<<endl<<"Congratulations :)"<<endl<<endl;





	return 0;

}
