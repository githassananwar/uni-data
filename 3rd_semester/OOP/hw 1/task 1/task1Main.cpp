#include<iostream>
#include<iomanip>

using namespace std;

int**  allocateMemory();
void initialize(int**);
void displayStatus(int**);
void chooseMenu(int**);
void login(int**);
void logout(int**);
void search(int**);
void idInput(int&);
void lab_pcInput(int&,int&);
void deallocate(int**);

int main()
{
	int **lab=0;
	lab=allocateMemory();
	initialize(lab);
	displayStatus(lab);
	cout<<endl;
	chooseMenu(lab);
	deallocate(lab);
	
	
	return 0;

}

int** allocateMemory()
{
	int count=5;

	int **lab=0;

	lab=new int*[4];

	for(int i=0;i<2;i++)
	{
		lab[i]=new int[count];
		count++;
	}

	count=4;

	for(int i=2;i<4;i++)
	{
		lab[i]=new int[count];
		count--;
	}

	return lab;

}

void initialize(int** lab)
{
	int count=5;
	for(int r=0;r<2;r++)
	{
		for(int c=0;c<count;c++)
		{
			lab[r][c]=0;
		}
		count++;
	}

	count=4;

	for(int r=2;r<4;r++)
	{
		for(int c=0;c<count;c++)
		{
			lab[r][c]=0;
		}
		count--;
	}

}

void displayStatus(int** lab)
{
	cout<<left<<setw(25)<<"Lab#"<<right<<"Computer Stations"<<endl;

	int count=5;
	for(int r=0;r<2;r++)
	{
		cout<<r+1<<setw(10);
		for(int c=0;c<count;c++)
		{
			if(lab[r][c]==0)
			{
				cout<<c+1<<": "<<"empty"<<"   ";
			}
			else
			{
				cout<<c+1<<": "<<lab[r][c]<<"   ";
			}
		}
		count++;
		cout<<endl;
	}

	count=4;

	for(int r=2;r<4;r++)
	{
		cout<<r+1<<setw(10);
		for(int c=0;c<count;c++)
		{
			if(lab[r][c]==0)
			{
				cout<<c+1<<": "<<"empty"<<"   ";
			}
			else
			{
				cout<<c+1<<": "<<lab[r][c]<<"   ";
			}
		}
		count--;
		cout<<endl;
	}

}

void chooseMenu(int** lab)
{
	int choice=0;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1. LogIn"<<endl;
		cout<<"2. LogOut"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Quit"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;

		cout<<endl;

		while(choice<0 || choice>4)
		{
			cout<<"Invalid Entry. Enter again: ";
			cin>>choice;
		}

		if(choice==1)
		{
			login(lab);
		}
		else if(choice==2)
		{
			logout(lab);
		}
		else if(choice==3)
		{
			search(lab);
		}
		
	}
	while(choice!=4);

}

void login(int**lab)
{
	int id=0, labNum=0, pcNum=0;
	
	idInput(id);

	lab_pcInput(labNum,pcNum);

	labNum--;
	pcNum--;

	if(lab[labNum][pcNum]==0)
	{
		lab[labNum][pcNum]=id;
	}
	else
	{
		cout<<"Error! This Computer Station is already LOGGED IN."<<endl;
	}

	cout<<endl;

	displayStatus(lab);	

	cout<<endl;

}

void logout(int** lab)
{
	int labNum=0, pcNum=0;
	
	lab_pcInput(labNum,pcNum);

	labNum--;
	pcNum--;

	if(lab[labNum][pcNum]==0)
	{
		cout<<"Error! This Computer Station is already LOGGED OFF."<<endl;
	}
	else
	{
		lab[labNum][pcNum]=0;
	}

	cout<<endl;

	displayStatus(lab);	

	cout<<endl;

}

void search(int** lab)
{
	int id=0, count=5;
	bool check=0;
	idInput(id);
	for(int r=0;r<2;r++)
	{
		for(int c=0;c<count;c++)
		{
			if(lab[r][c]==id)
			{
				cout<<"ID "<<id<<" is logged on to Lab#: "<<r+1<<", Computer Station#: "<<c+1<<endl;
				check=1;
			}
		}
		count++;
	}

	count=4;

	for(int r=2;r<4;r++)
	{
		for(int c=0;c<count;c++)
		{
			if(lab[r][c]==id)
			{
				cout<<"ID "<<id<<" is logged on to Lab#: "<<r+1<<", Computer Station#: "<<c+1<<"."<<endl;
				check=1;
			}
		}
		count--;
	}

	if(!check)
	{
		cout<<"Error! ID "<<id<<" is not logged on."<<endl;
	}

	cout<<endl;

	displayStatus(lab);	

	cout<<endl;

}

void idInput(int& id)
{
	cout<<"Enter ID(5-digit): ";
	cin>>id;
	while(id<10000||id>99999)
	{
		cout<<"Invalid id. Enter again: ";
		cin>>id;
	}

}


void lab_pcInput(int& labNum, int&pcNum)
{
	cout<<"Enter Lab#: ";
	cin>>labNum;
	while(labNum<1||labNum>4)
	{
		cout<<"Invalid Lab Number. Enter again: ";
		cin>>labNum;
	}

	cout<<"Enter Computer Station#: ";
	cin>>pcNum;
	switch (labNum)
	{
	case 1:
		while(pcNum<1||pcNum>5)
		{
			cout<<"Invalid Computer Station Number. Enter again: ";
			cin>>pcNum;
		}
		break;
	case 2:
		while(pcNum<1||pcNum>6)
		{
			cout<<"Invalid Computer Station Number. Enter again: ";
			cin>>pcNum;
		}
		break;

	case 3:
		while(pcNum<1||pcNum>4)
		{
			cout<<"Invalid Computer Station Number. Enter again: ";
			cin>>pcNum;
		}
		break;

	case 4:
		while(pcNum<1||pcNum>3)
		{
			cout<<"Invalid Computer Station Number. Enter again: ";
			cin>>pcNum;
		}
		break;
	}

}

void deallocate(int** lab)
{
	for(int i=0;i<4;i++)
	{
		delete [] lab[i];
		lab[i]=0;
	}

	delete [] lab;
	lab=0;

}
