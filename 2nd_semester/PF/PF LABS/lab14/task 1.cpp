#include<iostream>
#include<fstream>

using namespace std;


void arrayToFile(char*, int*,int );
void fileToArray(char*,int*,int);

int main ()
{
	const int SIZE=30;
	char name[SIZE]="data.dat";
	int arr[5]={1,2,3,4,5};
	int arr2[5];
    
    int size=sizeof(int);
    
	arrayToFile(name,arr,size);

	fileToArray(name,arr2,size);

    return 0;

}

void arrayToFile(char *name , int* arr,int size )
{
	ofstream fout(name, ios::binary);
	if(!fout)
	{
		cout<<"ERROR!!! File cant be created."<<endl;

	}
	else
	{

		fout.write(reinterpret_cast<char*>(arr),5*size);

		fout.close();

	}
	

}

void fileToArray(char* name,int* arr2,int size)
{
	

	ifstream fin(name, ios::binary);
	if(!fin)
	{
		cout<<"ERROR!!! File not found."<<endl;

	}
	else
	{
		fin.read(reinterpret_cast<char*>(arr2),5*size);

		for(int i=0;i<5;i++)
		{
			if(i!=4)
			{
				cout<<arr2[i]<<",";

			}
			else
			{
				cout<<arr2[i];
			}
			
		}
		cout<<endl;

		fin.close();
	}
	


}