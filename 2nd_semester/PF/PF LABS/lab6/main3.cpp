#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    double floors=0, rooms=0, occupied=0;
	double totalRooms=0, totalOccupied=0, totalUnoccupied=0;
	int count=1;

	cout << "Enter total number of floors: ";
	cin >> floors;

	while(floors<1)
	{
		cout << "ERROR!!! Invalid number of floors. Enter again: ";
		cin >> floors;
	}

	while(count<=floors)
	{
		if(count==13)
		{
				count++;
				floors++;
		}
		else
		{
			
		}

		cout << "Enter total number of rooms for floor " << count << " : ";
		cin >> rooms;

		while(rooms<10)
		{
				cout << "ERROR!!! Invalid number of rooms. Enter again: ";
				cin >> rooms;
		}

		totalRooms=totalRooms+rooms;

		cout << "Enter number of rooms Occupied: ";
		cin >> occupied;

		while(rooms<occupied)
		{
				cout << "ERROR!!! Invalid occupied rooms. Enter again: ";
				cin >> occupied;
		}

		totalOccupied = totalOccupied + occupied;

		
		count++;

	}

	totalUnoccupied=totalRooms-totalOccupied;

	cout << endl << "Results:-" << endl;

	cout << "Total number of rooms: " << totalRooms << endl;

	cout << "Total rooms Occupied: " << totalOccupied << endl;

	cout << "Total rooms Unoccupied: " << totalUnoccupied << endl;

	cout << setprecision(1)<<fixed;

	cout << "Percentage of occupied rooms(%): " << (totalOccupied*100)/totalRooms << endl;

	

    return 0;

}