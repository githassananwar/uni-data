#include<iostream>

using namespace std;

int main ()
{
	int const size=100;
	int count=0, askii=0;

    char input[size];

	cin>>input;

	for(count=0; input[count]!='\0'; count++ )
	{
		askii=input[count];
		if(askii>=97 && askii<=122)
		{
			askii=askii-32;
			input[count]=askii;
		}

	}
   

	cout<<input<<endl;


    return 0;

}