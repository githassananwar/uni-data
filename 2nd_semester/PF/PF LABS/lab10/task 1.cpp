#include<iostream>

using namespace std;

int main ()
{
	const int no=5, size=100, scores=4;

	int r=0, count=0; 
	double average[no];

	char names[no][size];
	char letters[no];


	double total=0;
	double student1[scores];
	double student2[scores];
	double student3[scores];
	double student4[scores];
	double student5[scores];

	for(r=0; r<no; r++)
	{
	    total = 0;

		cout<<"Enter student "<<r+1<<" name: ";

		cin.ignore();
		cin.getline(names[r], size);

		cout << "Enter marks:- " << endl;

		if(r==0)
		{
			for(count=0; count<scores; count++)
			{
				cout << "Enter test " << count+1 << " marks : ";
				cin >> student1[count];

				while(student1[count]<0 || student1[count]>100)
				{
					cout << "Invalid marks, Enter again: ";
					cin >> student1[count];

				}

				total = total+student1[count];
			}
			average[r] = total/4;

		}
		else if(r==1)
		{
			for(count=0; count<scores; count++)
			{
				cout << "Enter test " << count+1 << " marks : ";
				cin >> student2[count];
				while(student2[count]<0 || student2[count]>100)
				{
					cout << "Invalid marks, Enter again: ";
					cin >> student2[count];

				}

				total = total+student2[count];
			}
			average[r] = total/4;

		}
		else if(r==2)
		{
			for(count=0; count<scores; count++)
			{
				cout << "Enter test " << count+1 << " marks : ";
				cin >> student3[count];
				while(student3[count]<0 || student3[count]>100)
				{
					cout << "Invalid marks, Enter again: ";
					cin >> student3[count];

				}
				total = total+student3[count];
			}
			average[r] = total/4;

		}
		else if(r==3)
		{
			for(count=0; count<scores; count++)
			{
				cout << "Enter test " << count+1 << " marks : ";
				cin >> student4[count];
				while(student4[count]<0 || student4[count]>100)
				{
					cout << "Invalid marks, Enter again: ";
					cin >> student4[count];

				}
				total = total+student4[count];
			}
			average[r] = total/4;

		}
		else if(r==4)
		{
			for(count=0; count<scores; count++)
			{
				cout << "Enter test " << count+1 << " marks : ";
				cin >> student5[count];
				while(student5[count]<0 || student5[count]>100)
				{
					cout << "Invalid marks, Enter again: ";
					cin >> student5[count];

				}
				total = total+student5[count];
			}
			average[r] = total/4;

		}

	}
	cout << endl;

	for(count=0;count<no;count++)
	{

		if(average[count]>=90 && average[count]<=100)
		{
			letters[count]='A';
		}
		else if(average[count]>=80 && average[count]<=89)
		{
			letters[count]='B';
		}
		else if(average[count]>=70 && average[count]<=79)
		{
			letters[count]='C';
		}
		else if(average[count]>=60 && average[count]<=69)
		{
			letters[count]='D';
		}
		else if(average[count]>=0 && average[count]<=59)
		{
			letters[count]='F';
		}

	}


	for(count=0; count<no; count++)
	{
		cout << "Average of student" << count+1 << " : " << average[count] << endl;
		cout << "Letter grade: " << letters[count] << endl;

	}

    return 0;

}
