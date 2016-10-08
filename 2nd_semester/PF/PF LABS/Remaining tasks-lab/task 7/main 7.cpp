#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>


using namespace std;



int main()
{

    unsigned random = time(0);
    srand(random);

    int x=rand()%1000;
    int y=rand()%1000;

	char enter;

    int tot=0;
    
    
    cout << "LEARN ADDITION!!! Press Enter to know the answer. ." << endl;

    cout << setw(4) << x << endl;
    cout << "+" << y << endl;
	cout << "_____" << endl;

    tot = x+y;

    cin.get(enter);

    cout << "=" << tot << endl << endl;


    return 0;

}

