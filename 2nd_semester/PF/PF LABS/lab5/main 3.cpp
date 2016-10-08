#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

int main ()
{
	int select=0;
	double time=0, speed=0, distance=0; 

	cout << "Carbon dioxide speed: 258.0 m/s (Press 1 to select)" << endl;
	cout << "Air speed: 331.5 m/s (Press 2 to select)" << endl;
	cout << "Helium speed: 972.0 m/s (Press 3 to select)" << endl;
	cout << "Hydrogen speed: 1,270.0 m/s (Press 4 to select)" << endl;

	cout << endl << "Enter menu number: "; 
	cin >> select;

	switch(select)
	{

		case 1:
		{
			speed=258.0;
			cout << "Enter time in seconds: ";
			cin >> time;
			distance = speed*time;
			cout << setprecision(1) << fixed;
			cout << "Distance covered in meters(CO2): " << distance << " meters" << endl;
			break;
		}

		case 2:
		{
			speed=331.5;
			cout << "Enter time in seconds: ";
			cin >> time;
			distance = speed*time;
			cout << setprecision(1) << fixed;
			cout << "Distance covered in meters(Air): " << distance << " meters" << endl;
			break;
		}

		case 3:
		{
			speed=972.0;
			cout << "Enter time in seconds: ";
			cin >> time;
			distance = speed*time;
			cout << setprecision(1) << fixed;
			cout << "Distance covered in meters(He): " << distance << " meters" << endl;
			break;
		}

		case 4:
		{
			speed=1270.0;
			cout << "Enter time in seconds: ";
			cin >> time;
			distance = speed*time;
			cout << setprecision(1) << fixed;
			cout << "Distance covered in meters(H2): " << distance << " meters" << endl;
			break;
		}

		default:
		{
			cout << "ERROR!!! Wrong entry. ." << endl;
		}


	}


    return 0;

}