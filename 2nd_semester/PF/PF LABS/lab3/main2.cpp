#include<iostream>

using namespace std;

int main ()
{
	int num=0;

	cout << "Enter number: ";
	cin >> num;

	switch(num)
		{
	        case 1:
				cout << "Roman notation: I" << endl;
				break;

			case 2:
				cout << "Roman notation: II" << endl;
				break;

			case 3:
				cout << "Roman notation: III" << endl;
				break;

			case 4:
				cout << "Roman notation: IV" << endl;
				break;

			case 5:
				cout << "Roman notation: V" << endl;
				break;

			case 6:
				cout << "Roman notation: VI" << endl;
				break;

			case 7:
				cout << "Roman notation: VII" << endl;
				break;

			case 8:
				cout << "Roman notation: VIII" << endl;
				break;

			case 9:
				cout << "Roman notation: XI" << endl;
				break;

			case 10:
				cout << "Roman notation: X" << endl;
				break;

			default:
				cout << "ERROR!!! Invalid input. ." << endl;
				break;

		}


	return 0;

}


