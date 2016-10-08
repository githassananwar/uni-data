#include<iostream>

using namespace std;

const int SIZE=100;

struct Info
{
	char name[SIZE];
	int num;
	int points;

};


int main ()
{
    
	Info team[12];

    int i=0;
	for(i=0;i<12;i++)
	{
		cout<<"Enter Player "<<i+1<<" name: ";
		cin>>team[i].name;

		cout<<"Enter Player "<<i+1<<" number: ";
		cin>>team[i].num;
		while(team[i].num<0)
		{
			cout<<"Invalid number, Enter again: ";
			cin>>team[i].num;
		}

		cout<<"Enter Player "<<i+1<<" points: ";
		cin>>team[i].points;
		while(team[i].points<0)
		{
			cout<<"Invalid points, Enter again: ";
			cin>>team[i].points;
		}

		cout<<endl;

	}

	cout<<endl<<"RESULTS-------------------------------------"<<endl;

	int total=0,max=0;
	int number=0;
	char player[100]="bhg";


	max=team[0].points;

	for(i=0;i<12;i++)
	{
		cout<<"Player "<<i+1<<"name: "<<team[i].name<<endl;
		cout<<"Player "<<i+1<<"number: "<<team[i].num<<endl;
		cout<<"Player "<<i+1<<"points: "<<team[i].points<<endl;

		cout<<endl;

		total=total+team[i].points;

		if(team[i].points>max)
		{
			max=team[i].points;
			number=team[i].num;
			strcpy(player,team[i].name);
		}

	}



	cout<<"Total points earned by team: "<<total<<endl;
	cout<<"Number of player who earned most points: "<<number<<endl;;
	cout<<"Name of player who earned most points: : "<<player<<endl;;


   


    return 0;

}