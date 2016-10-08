#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
   double distance=0, speed=0, time=0;
   int count=1;

   cout << "Enter speed of vehicle in mph: ";
   cin >> speed;

   while(speed<0)
   {
	   cout << "ERROR!!! Invalid speed. Enter again: ";
	   cin >> speed;
   }


   cout << "How many hours it had travelled: ";
   cin >> time;

   while(time<1)
   {
	   cout << "ERROR!!! Invalid time. Enter again: ";
	   cin >> time;
   }

   cout << "Hours		Distance travelled" << endl;
   cout << "-------------------------------" << endl;

   while(count<=time)
   {
	   distance=distance+speed;
	   cout << count << "		 " << distance << endl;
	   count=count+1;
   }






    return 0;

}