#include <iostream>
#include <fstream>
using namespace std;

int calculateSquare(int k, int x, int y, int xCheck, int yCheck);

int main()
{
	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be opened" << endl;
	}
	else
	{
		int k=0, x=0, y=0;
		fin>>k>>x>>y;
		do
		{
			cout<<calculateSquare(k, 1024, 1024, x, y)<<endl; //Starting from (1024,1024)
			fin>>k>>x>>y;			
		}
		while(k!=0 && x!=0 && y!=0);

	}

	return 0;
}

int calculateSquare(int k, int x, int y, int xCheck, int yCheck)
{
	int count=0;
	
	int len=2*k+1, subLen=2*(k/2)+1;

	//Range Check
	if( xCheck<=x+(len/2) && xCheck>=x-(len/2) && yCheck<=y+(len/2) && yCheck>=y-(len/2) )
	{
		count++;
	}

	if(k < 1)
	{
		return count;
	}
	
	count=count+( calculateSquare(k/2, x+(len/2), y+(len/2), xCheck, yCheck) );
	count=count+( calculateSquare(k/2, x+(len/2), y-(len/2), xCheck, yCheck) );
	count=count+( calculateSquare(k/2, x-(len/2), y+(len/2), xCheck, yCheck) );
	count=count+( calculateSquare(k/2, x-(len/2), y-(len/2), xCheck, yCheck) );
	
	return count;

}