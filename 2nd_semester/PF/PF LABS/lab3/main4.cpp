#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>


using namespace std;



int main()
{

    unsigned random = time(0);
    srand(random);

    int x = rand()%1000;
    int y = rand()%1000;

	char enter;

    int tot=0;

	int ans=0;
    
    
    cout << "LEARN ADDITION!!!" << endl;

    cout << setw(4) << x << endl;
    cout << "+" << y << endl;
	cout << "_____" << endl;

    tot = x+y;

	cout<<"=";

	cin>>ans;

	if(ans==tot)
	{
		cout << "Congratulations boy!!! KEEP IT UP :)" << endl;
	}
	else
	{
		cout << "Sorry! You entered a wrong answer. ." << endl;
		cout << "Answer is: " << tot << endl;

	}



    return 0;

}



