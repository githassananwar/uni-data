#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int NO_STUDENTS=2;	   //no of students to be entered.

//Student structure.
struct Student
{
	char rollno[100];
	char name[100];

	int courses[4];
	double courseGpa[4];

	double gpa;
	char* grade[4]; //3rd key is for null character

};

//FUNCTIONS

//enterStudentRecord
void enterStudentRecord(Student* st, int currentStudent)
{
	cout<<"Enter Student Roll no: ";
	cin>>st[currentStudent].rollno;
	
	cin.ignore();
	cout<<"Enter Student Name: ";
	cin.getline(st[currentStudent].name, 100);

	char* subjects[4]={"PF","Calculus","English","Computing"};
	int marks=0;

	cout<<"Enter Marks:-"<<endl<<endl;
	for(int i=0; i<4; i++)
	{
		cout<<"Enter "<<subjects[i]<<" marks: ";
		cin>>marks;
		while(marks<0 || marks>100)
		{
			cout<<"Invalid Marks! Enter again: ";
			cin>>marks;
		}
		st[currentStudent].courses[i]=marks;
	}

}

//Calculate GPA
void calculateGPA(Student* st, int currentStudent)
{
	for(int i=0; i<4; i++)
	{
		int marks=st[currentStudent].courses[i];
		if(marks>=85 && marks<=100)
		{
			st[currentStudent].courseGpa[i]=4;
			st[currentStudent].grade[i]="A+";
		}
		else if(marks>=80 && marks<=84)
		{
			st[currentStudent].courseGpa[i]=3.75;
			st[currentStudent].grade[i]="A-";
		}
		else if(marks>=75 && marks<=79)
		{
			st[currentStudent].courseGpa[i]=3.50;
			st[currentStudent].grade[i]="B+";
		}
		else if(marks>=70 && marks<=74)
		{
			st[currentStudent].courseGpa[i]=3.00;
			st[currentStudent].grade[i]="B";
		}
		else if(marks>=65 && marks<=69)
		{
			st[currentStudent].courseGpa[i]=2.50;
			st[currentStudent].grade[i]="C+";
		}
		else if(marks>=60 && marks<=64)
		{
			st[currentStudent].courseGpa[i]=2.00;
			st[currentStudent].grade[i]="C";
		}
		else if(marks>=55 && marks<=59)
		{
			st[currentStudent].courseGpa[i]=1.50;
			st[currentStudent].grade[i]="D+";
		}
		else if(marks>=50 && marks<=54)
		{
			st[currentStudent].courseGpa[i]=1.0;
			st[currentStudent].grade[i]="D";
		}
		else
		{
			st[currentStudent].courseGpa[i]=0;
			st[currentStudent].grade[i]="F";
		}

	}

	double gpa=0;
	for(int i=0; i<4; i++)
	{
		//Check for PF as it has 4 credit hours 
		if(i==0)
		{
			gpa=gpa+4*st[currentStudent].courseGpa[i];
		}
		//For other subjects
		else
		{
			gpa=gpa+3*st[currentStudent].courseGpa[i];
		}

	}
	//Total credit hours = 13
	gpa=gpa/13;
	st[currentStudent].gpa=gpa;

}

void searchStudent(Student* st)
{
	char rollno[100];
	cout<<"Enter Roll no to search: ";
	cin>>rollno;

	for(int i=0; i<NO_STUDENTS; i++)
	{
		if( !strcmp(rollno, st[i].rollno) )
		{
			cout<<"Student Roll No: "<<st[i].rollno<<endl;
			cout<<"Student Name: "<<st[i].name<<endl;
			cout<<endl<<"Student Marks: "<<endl;
			char* subjects[4]={"PF","Calculus","English","Computing"};
			for(int j=0; j<4; j++)
			{
				cout<<subjects[j]<<" Marks: "<<st[i].courses[j]<<endl;
				cout<<subjects[j]<<" Grade: "<<st[i].grade[j]<<endl<<endl;
			}

			cout<<endl<<"Student overall GPA: "<<st[i].gpa<<endl<<endl;
			system("pause");
			
		}
	}

}

void updateStudentRecord(Student* st)
{
	char rollno[100];
	cout<<"Enter Roll no to Update: ";
	cin>>rollno;

	for(int i=0; i<NO_STUDENTS; i++)
	{
		if( !strcmp(rollno, st[i].rollno) )
		{
			char* subjects[4]={"PF","Calculus","English","Computing"};
			int marks=0;

			cout<<"Update Marks:-"<<endl<<endl;
			for(int j=0; j<4; j++)
			{
				cout<<"Enter "<<subjects[j]<<" marks: ";
				cin>>marks;
				while(marks<0 || marks>100)
				{
					cout<<"Invalid Marks! Enter again: ";
					cin>>marks;
				}
				st[i].courses[j]=marks;
			}
			calculateGPA(st, i);
		}
	}
}

void displayTopper(Student* st)
{
	int studentIndex=0;
	double max=st[0].gpa;
	for(int i=1; i<NO_STUDENTS; i++)
	{
		if( st[i].gpa>max )
		{
			studentIndex=i;
			max=st[i].gpa;
		}
	}

	cout<<"---Topper Result---"<<endl;
	cout<<"Student Roll No: "<<st[studentIndex].rollno<<endl;
	cout<<"Student Name: "<<st[studentIndex].name<<endl;
	cout<<"Student Marks: "<<endl;
	char* subjects[4]={"PF","Calculus","English","Computing"};
	for(int i=0; i<4; i++)
	{
		cout<<subjects[i]<<" Marks: "<<st[studentIndex].courses[i]<<endl;
		cout<<subjects[i]<<" Grade: "<<st[studentIndex].grade[i]<<endl<<endl;
	}

	cout<<endl<<"Student overall GPA: "<<st[studentIndex].gpa<<endl<<endl;
	system("pause");

}

void displayLowestResult(Student* st)
{
	int studentIndex=0;
	double min=st[0].gpa;
	for(int i=1; i<NO_STUDENTS; i++)
	{
		if( st[i].gpa<min )
		{
			studentIndex=i;
			min=st[i].gpa;
		}
	}

	cout<<"---Lowest GPA Student Result---"<<endl;
	cout<<"Student Roll No: "<<st[studentIndex].rollno<<endl;
	cout<<"Student Name: "<<st[studentIndex].name<<endl;
	cout<<"Student Marks: "<<endl;
	char* subjects[4]={"PF","Calculus","English","Computing"};
	for(int i=0; i<4; i++)
	{
		cout<<subjects[i]<<" Marks: "<<st[studentIndex].courses[i]<<endl;
		cout<<subjects[i]<<" Grade: "<<st[studentIndex].grade[i]<<endl<<endl;
	}

	cout<<endl<<"Student overall GPA: "<<st[studentIndex].gpa<<endl<<endl;
	system("pause");

}

void displayAbove3(Student* st)
{
	int count=0;
	cout<<"---Students Above 3.00 GPA---"<<endl;
	for(int i=0; i<NO_STUDENTS; i++)
	{
		if( st[i].gpa>=3.00 )
		{
			cout<<"Student Roll No: "<<st[i].rollno<<endl;
			cout<<"Student Name: "<<st[i].name<<endl;
			cout<<"Student overall GPA: "<<st[i].gpa<<endl;
			count++;
		
		}
	}
	cout<<endl<<"Total no. of Students above or equal 3.0 GPA: "<<count<<endl;
	system("pause");
}

void displayBetween2n3(Student* st)
{
	int count=0;
	cout<<"---Students between 2.00 and 3.00 GPA---"<<endl;
	for(int i=0; i<NO_STUDENTS; i++)
	{
		if( st[i].gpa>=2.00 && st[i].gpa<3.00 )
		{	
			cout<<"Student Roll No: "<<st[i].rollno<<endl;
			cout<<"Student Name: "<<st[i].name<<endl;
			cout<<"Student overall GPA: "<<st[i].gpa<<endl<<endl;
			count++;		
		}
	}
	cout<<endl<<"Total no. of Students between 2.00 and 3.00 GPA: "<<count<<endl;
	system("pause");

}

void displayGradeA(Student* st)
{
	int count=0;
	cout<<"---Students having A Grade in any Subject---"<<endl;
	for(int i=0; i<NO_STUDENTS; i++)
	{
		for(int j=0; j<4; j++)
		{
			if( !strcmp(st[i].grade[j], "A+") ||  !strcmp(st[i].grade[j], "A-") )
			{
				cout<<st[i].rollno<<" got A grade in ";
				if(j==0)
				{
					cout<<"PF"<<endl;
				}
				else if(j==1)
				{
					cout<<"Calculus"<<endl;
				}
				else if(j==2)
				{
					cout<<"English"<<endl;
				}
				else if(j==3)
				{
					cout<<"Computing"<<endl;
				}
				count++;
			}
	
		}
		
	}
	cout<<endl<<"Total no. of Students with grade A: "<<count<<endl;
	system("pause");

}

void displayGradeB(Student* st)
{
	int count=0;
	cout<<"---Students having B Grade in any Subject---"<<endl;
	for(int i=0; i<NO_STUDENTS; i++)
	{
		for(int j=0; j<4; j++)
		{
			if( !strcmp(st[i].grade[j], "B+") ||  !strcmp(st[i].grade[j], "B") )
			{
				cout<<st[i].rollno<<" got B grade in ";
				if(j==0)
				{
					cout<<"PF"<<endl;
				}
				else if(j==1)
				{
					cout<<"Calculus"<<endl;
				}
				else if(j==2)
				{
					cout<<"English"<<endl;
				}
				else if(j==3)
				{
					cout<<"Computing"<<endl;
				}
				count++;
			}
	
		}
		
	}
	cout<<endl<<"Total no. of Students with grade B: "<<count<<endl;
	system("pause");

}

void displayGradeC(Student* st)
{
	int count=0;
	cout<<"---Students having C Grade in any Subject---"<<endl;
	for(int i=0; i<NO_STUDENTS; i++)
	{
		for(int j=0; j<4; j++)
		{
			if( !strcmp(st[i].grade[j], "C+") ||  !strcmp(st[i].grade[j], "C") )
			{
				cout<<st[i].rollno<<" got C grade in ";
				if(j==0)
				{
					cout<<"PF"<<endl;
				}
				else if(j==1)
				{
					cout<<"Calculus"<<endl;
				}
				else if(j==2)
				{
					cout<<"English"<<endl;
				}
				else if(j==3)
				{
					cout<<"Computing"<<endl;
				}
				count++;
			}
	
		}
		
	}
	cout<<endl<<"Total no. of Students with grade C: "<<count<<endl;
	system("pause");

}

void displayGradeF(Student* st)
{
	int count=0;
	cout<<"---Students having F Grade in any Subject---"<<endl;
	for(int i=0; i<NO_STUDENTS; i++)
	{
		for(int j=0; j<4; j++)
		{
			if( !strcmp(st[i].grade[j], "F") )
			{
				cout<<st[i].rollno<<" got F grade in ";
				if(j==0)
				{
					cout<<"PF";
				}
				else if(j==1)
				{
					cout<<"Calculus";
				}
				else if(j==2)
				{
					cout<<"English";
				}
				else if(j==3)
				{
					cout<<"Computing";
				}
				cout<<". It must be REPEATED."<<endl;
				count++;
			}
	
		}
		
	}
	cout<<endl<<"Total no. of Students with grade F: "<<count<<endl;
	system("pause");

}



int main()
{
	//Students struct array
	Student st[NO_STUDENTS];

	//Current Student to be entered
	int currentStudent=0;

	cout<<"---- Welcome to GPA Evaluation System ----"<<endl<<endl;
	int choice;
	do
	{

		cout<<"Menu"<<endl;
		cout<<"1.  Enter Student's Marks Record"<<endl;
		cout<<"2.  Search Student via Roll no"<<endl;
		cout<<"3.  Update Student Marks"<<endl;
		cout<<"4.  Display highest CGPA Student Result"<<endl;
		cout<<"5.  Display lowest CGPA Student Result"<<endl;
		cout<<"6.  Display no. of Students greater or equal 3.00 CGPA"<<endl;
		cout<<"7.  Display no. of Students in between 2.00 and 3.00 CGPA"<<endl;
		cout<<"8.  Display no. of Students having 'A' Grade"<<endl;
		cout<<"9.  Display no. of Students having 'B' Grade"<<endl;
		cout<<"10. Display no. of Students having 'C' Grade"<<endl;
		cout<<"11. Display no. of Students having 'F' Grade"<<endl;
		cout<<"12. Quit"<<endl<<endl;
		cout<<"Enter your choice: ";

		cin>>choice;

		cout<<endl;

		//input validation
		while(choice<1 || choice>12)
		{
			cout<<"Invalid Entry!!! Enter again: ";
			cin>>choice;
		}

		//if - else if. To call a particular function according to the user demand.
		if(choice==1)
		{
			if(currentStudent<NO_STUDENTS)
			{
				enterStudentRecord(st, currentStudent);
				calculateGPA(st, currentStudent);
				currentStudent++;
				system("cls");
			}
			else
			{
				cout<<"Sorry! No more Students can be entered."<<endl;
			}
		}
		else if(choice==2)
		{
			searchStudent(st);
			system("cls");
		}
		else if(choice==3)
		{
			updateStudentRecord(st);
			system("cls");
		}
		else if(choice==4)
		{
			displayTopper(st);
			system("cls");
		}
		else if(choice==5)
		{
			displayLowestResult(st);
			system("cls");
		}
		else if(choice==6)
		{
			displayAbove3(st);
			system("cls");
		}
		else if(choice==7)
		{
			displayBetween2n3(st);
			system("cls");
		}
		else if(choice==8)
		{
			displayGradeA(st);
			system("cls");
		}
		else if(choice==9)
		{
			displayGradeB(st);
			system("cls");
		}
		else if(choice==10)
		{
			displayGradeC(st);
			system("cls");
		}
		else if(choice==11)
		{
			displayGradeF(st);
			system("cls");
		}

		

	}
	while(choice!=12);


	return 0;

}