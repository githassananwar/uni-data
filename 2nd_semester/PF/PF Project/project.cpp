/* HASSAN ANWAR
BSEF12M014 - SE Morning */

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include<iomanip>

using namespace std;

//Constant integers for array sizes.
const int R_LENGTH=11; //roll no length.
const int N_LENGTH=41; //name length.
const int SIZE=40;	   //size for different arrays used in program.

//Student structure.
struct Student
{
	char rollNo[R_LENGTH];
	char name[N_LENGTH];

	int numCourses;
	double *gpa;
	double sgpa;

};

//FUNCTIONS PROTOTYPES:-

//functions to read and compute data.
Student *readAllRecords(int &, char[]);
void readOneRecord(Student*, int, ifstream&);
void computeAllSGPAs(Student*, int);
void computeOneSGPA(Student*, int, int);

//functions to display Start display and choice menu.
void startDisplay(char[], int);
void menuChoice(Student*, char[], int);

//choice Menu functions.
void displayList(Student*, int);
void displayMax(Student*, int);
void displayMin(Student*, int);
int searchStudent(Student*, char*, int);
void update(Student*, int);
void updateName(Student*, int, int);
void updateCourse(Student*, int, int);
void quit(Student*, char[], int);


//Main
int main()
{

	int records=0;				        //ineger variable for total records to be read from file.
	char fileName[SIZE]="students.txt"; //file name which has to be opened in function(Change here only if needed).

	//readAllRecords will return a Student pointer pointing to memory which contain data that is read.
	Student *readPtr = readAllRecords(records, fileName);

	//it will read all GPAs from memory and compute SGPAs of respective students.
	computeAllSGPAs(readPtr, records);

	//to display start screen display once when program starts.
	startDisplay(fileName, records);

	//Choice menu will be displayed after every function until user choose quit option.
	menuChoice(readPtr, fileName, records);

	//when user choose quit option, all memory allocated in heap will be deallocated.
	//So readPtr must be null to avoid dangling pointer.
	readPtr = 0;

	//program will terminate as user choose quit option.
	return 0;

}


//receives records variable by reference from Main and fileName to be read.
Student *readAllRecords(int &records, char fileName[]) //returns a Student pointer to main.
{

	int i=0; //for array indexing.

	Student *ptr=0; //Student pointer for dynamic memory allocation.

	//File opening which has to be read.
	ifstream fin(fileName);

	//opening check.
	if(!fin)
	{
		cout<<"ERROR!!! File not found."<<endl;
	}
	else
	{

		//takes total number of records(in file) from file.
		fin>>records;

		//Dynamic memory allocation of array of total records size.
		ptr = new Student[records];

		//loop to read one record.
		for(i=0; i<records; i++)
		{
			//reads one record of a student at one time.
			readOneRecord(ptr, i, fin);
		}

		//closing file after reading all data.
		fin.close();

	}

	//return Student pointer to main.So that there is no memory leak.
	return ptr;

}


/*receives pointer to Student, Student Structure array index for particular student record and
file handler to read further data from file*/
void readOneRecord(Student *ptr, int i, ifstream &fin)
{

	int count=0; //count variable for indexing of gpa array.
	fin>>ptr[i].rollNo;	//read roll number of particular student.
	fin.ignore(); // to remove white space from buffer.
	fin.getline(ptr[i].name, N_LENGTH); //to read full name of student including spaces.

	fin>>ptr[i].numCourses; // to read total number of courses a particular student has.

	//GPA reading
	//Dynamic memory allocation of array(size equal to number of courses) to read all GPAs from file.
	ptr[i].gpa = new double[ptr[i].numCourses];

	//We will read GPA as string and will convert in float value after checking F case.
	char string[SIZE];

	for(count=0; count<ptr[i].numCourses; count++)
	{
		//read string.
		fin>>string;

		//comparison of string with F.
		if(strcmp(string,"F") == 0)
		{
			ptr[i].gpa[count] = 0.0; //if it read F, gpa of that course must be 0.0.
		}
		else
		{
			ptr[i].gpa[count] = atof(string); //in case its a number, convert it in float value and save.
		}


	}

}


//receives pointer and number of records from Main. Calculates SGPAs of all students.
void computeAllSGPAs(Student* ptr, int records)
{

	for(int i=0; i<records; i++)
	{
		//calls a function to compute one SGPA of one student.
		computeOneSGPA(ptr, i, ptr[i].numCourses);
	}


}


/*receives pointer to Student, Student Structure array index of particular student record and
number of courses*/
void computeOneSGPA(Student* ptr, int i, int courses)
{

	double sum=0.0;

	//loop calculates total sum of all GPAs of a particular student.
	for(int counter=0; counter<courses; counter++)
	{
		sum = sum + ptr[i].gpa[counter];
	}

	//Save SGPA in Student Structure pointer of a particular student.
	ptr[i].sgpa = sum/courses;

}


//receives fileName and records from Main which have to be shown in start display once.
void startDisplay(char fileName[], int records)
{
	cout<<"---- Welcome to Student Record Managment System ----"<<endl<<endl;

	cout<<"Reading data from '"<<fileName<<"'"<<" . . ."<<endl<<endl;

	cout<<"File opened successfully and records of "<<records<<" students have been read."<<endl<<endl;

}


//receives pointer to Student, fileName(for Quit function call argument) and records from Main.
void menuChoice(Student *ptr, char file[], int records)
{
	//do-while loop to display the Menu repeatedly after every function execution.
	int choice;
	do
	{

		cout<<"Menu"<<endl;
		cout<<"1. Display list of all students"<<endl;
		cout<<"2. Display student record(s) having Maximum SGPA"<<endl;
		cout<<"3. Display student record(s) having Minimum SGPA"<<endl;
		cout<<"4. Search by Roll Number"<<endl;
		cout<<"5. Update a Student record"<<endl;
		cout<<"6. Quit"<<endl<<endl;
		cout<<"Enter your choice: ";

		cin>>choice;

		cout<<endl;

		//input validation
		while(choice<1 || choice>6)
		{
			cout<<"Invalid Entry!!! Enter again: ";
			cin>>choice;
		}

		//if - else if. To call a particular function according to the user demand.
		if(choice==1)
		{
			displayList(ptr, records);
			cout<<endl;
		}

		else if(choice==2)
		{
			displayMax(ptr, records);
			cout<<endl;
		}

		else if(choice==3)
		{
			displayMin(ptr, records);
			cout<<endl;
		}

		else if(choice==4)
		{
			//in case of Searching, we read input here and send it in function.
			//So searchStudent fuunction can be used in update function.
			char roll[SIZE];

			cout<<"Enter Roll no: ";
			cin>>roll;
			searchStudent(ptr, roll, records);
			cout<<endl;
		}

		else if(choice==5)
		{
			update(ptr, records);
			cout<<endl;
		}

		else if(choice==6)
		{
			quit(ptr, file, records);
			cout<<endl;
		}

	}
	while(choice!=6);

}


//receives pointer and number of records from menuChoice function.
void displayList(Student* ptr, int records)
{
	//Headings-setw manipulators for tabular output.
	cout<<left<<setw(20)<<"Roll No."<<setw(30)<<"Name"<<setw(15)<<"Courses"<<setw(10)<<"SGPA"<<endl;

	//loop to display records of all students using indexing(of DMA array) of pointer to Student structure.
	for(int i=0; i<records; i++)
	{
		cout << left << setw(20) << ptr[i].rollNo << setw(30) << ptr[i].name << setw(15) << ptr[i].numCourses;
		cout << setw(10) << setprecision(2) << fixed << ptr[i].sgpa << endl;
	}

}


//receives pointer and number of records from menuChoice function.
void displayMax(Student *ptr, int records)
{

	double max=ptr[1].sgpa; //initializing max variable .
	int maxIndex=0;

	for(int i=0; i<records; i++)
	{
		//if SGPA of a student is greater than maxIndex, assign it's index to maxIndex.
		if(ptr[i].sgpa > max)
		{
			max = ptr[i].sgpa;
			maxIndex = i;
		}
	}

	cout<<"Students having Maximum SGPA:- "<<endl;

	for(int i=0;i<records;i++)
	{
		if(ptr[i].sgpa == ptr[maxIndex].sgpa)
		{
			//Display results of student having maximum SGPA
			cout<<"Roll No: " << ptr[i].rollNo << endl;
			cout<<"Name: " << ptr[i].name << endl;
			cout<<"SGPA: " << ptr[i].sgpa << endl;
			cout<<endl;

		}


	}



}


//receives pointer and number of records from menuChoice function.
void displayMin(Student *ptr, int records)
{

	double min=ptr[1].sgpa; //initializing min variable .
	int minIndex=0;

	for(int i=0; i<records; i++)
	{
		//if SGPA of a student is lesser than minIndex, assign it's index to minIndex.
		if(ptr[i].sgpa < min)
		{
			min = ptr[i].sgpa;
			minIndex = i;
		}
	}

	cout<<"Student having Minimum SGPA:- "<<endl;

	for(int i=0; i<records; i++)
	{
		if(ptr[i].sgpa==ptr[minIndex].sgpa)
		{
			//Display results of student having minimum SGPA
			cout<<"Roll No: "<<ptr[i].rollNo<<endl;
			cout<<"Name: "<<ptr[i].name<<endl;
			cout<<"SGPA: "<<ptr[i].sgpa<<endl;
		}
	}

}


/*receives pointer, rollNumber to be searched and number of records.
Returns the matched results indexes(int).*/
int searchStudent(Student *ptr, char *searchRoll, int records)
{
	//bool variable for no record found check.
	bool check=true;

	//Counters i & j .
	int i=0, j=0, count=0;

	/*here Update variable will contain indexes of matched results which is returned to where function is called.
	It's use is important when this function is called from update function.*/
	int update=-1;

	//for length of roll Number that was entered by user.
	int length = strlen(searchRoll);

	//loop to convert all characters of roll Number to capital letters.
	for(i=0; i<length; i++)
	{
		searchRoll[i] = toupper(searchRoll[i]);
	}

	//Headings
	cout<<endl<<left<<setw(20)<<"Roll No."<<setw(30)<<"Name"<<setw(15)<<"Courses"<<setw(10)<<"SGPA"<<endl;

	//loop to check every student roll number.
	for(i=0; i<records; i++)
	{
		count=0;
		//loop to check every student roll Number's character with entered roll Number.
		for(j=0; j<length; j++)
		{
			if(ptr[i].rollNo[j] == searchRoll[j])
			{
				count++; //Increment in count for every matched character of roll Number.
			}
		}

		//if all characters match, means result is found.
		if(count == length)
		{
			//to display result.
			cout << left << setw(20) << ptr[i].rollNo << setw(30) << ptr[i].name << setw(15) << ptr[i].numCourses;
			cout << setw(10) << setprecision(2) << fixed << ptr[i].sgpa << endl;

			check=false; //set bool to false so No result found check can't run.
			update=i;    //assign index of student whose roll Number is matched with entered one.
		}

	}

	//No record found check(bool).
	if(check)
	{
		cout<<"Sorry!!! No record found."<<endl;
	}

	//returns update index(as explained above).
	return update;

}


//receives pointer and number of records from menuChoice function.
void update(Student *ptr, int records)
{
	//variable declaration.
	int index=0, length=0, choice=0;
	char name[SIZE];

	//Roll number to be searched and update.
	cout<<"Enter full Roll no: ";
	cin>>name;

	//for length
	length = strlen(name);

	//Check whether user entered complete rollNumber of length 10 i.e BSEF12M014.
	while(length != 10)
	{
		cout<<"Invalid Roll no!!! Please Enter full Roll no: ";
		cin>>name;
		length = strlen(name);
	}

	//calls searchStudent function and gets index of the student whose rollNumber is matched.
	index = searchStudent(ptr, name, records);

	//if there is no record of rollNumber user entered. Search function will return -1.
	if(index != -1)
	{
		cout<<endl<<"Choose:-"<<endl;
		cout<<"1. Update Name."<<endl<<"2. Add a course."<<endl;

		//Choice menu selection.
		cout<<"Enter your choice: ";
		cin>>choice;

		cout<<endl;

		//Input validation.
		while(choice<1 || choice>2)
		{
			cout<<endl<<"Invalid entry!!! Please Enter correct choice: ";
			cin>>choice;
		}

		//if - else if. To call a particular function according to the user demand.
		if(choice==1)
		{
			updateName(ptr, records, index);
		}
		else if(choice==2)
		{
			updateCourse(ptr, records, index);
		}

	}

}


/*receives pointer, number of records and Student Structure array index of particular student
from update function*/
void updateName(Student *ptr, int records, int index)
{
	//Input new name.
	cout<<"Enter new name: ";
	cin.ignore();

	//overwrite the old name saved with new name.
	cin.getline(ptr[index].name, N_LENGTH);

	//Success message.
	cout<<endl<<"Name Updated. . "<<endl;

}


/*receives pointer, number of records and Student Structure array index of particular student
from update function*/
void updateCourse(Student *ptr, int records, int index)
{
	//variable declaration.
	int count=0;
	char string[SIZE];

	//ipCheck for F cases
	double ipCheck=0.0;

	//Student variable.
	Student update;

	//total number of courses is incremented by one.
	int courseNo = ptr[index].numCourses + 1;

	//Dynamic memory allocation of array of incremented records size.
	update.gpa = new double[courseNo];

	cout<<"Enter GPA of new course: ";

	/*loop copies the new GPA array with old GPA array saved in Student Structure
	of that particular student and asks the new GPA for last array index(added course GPA position)*/
	for(count=0; count<courseNo; count++)
	{
		update.gpa[count] = ptr[index].gpa[count];

		//for last array index
		if(count == courseNo-1)
		{
			//ask to enter GPA as string
			cin>>string;

			//comparison of string with F.
			if(strcmp(string,"F") == 0)
			{
				update.gpa[count] = 0.0; //if it read F, gpa of that course must be 0.0.
			}
			else
			{
				ipCheck = atof(string); //in case its a number, convert it in float value and save.

				//Input validation
				while(ipCheck<0.0 || ipCheck>4.0 || strcmp(string,"F")!=0)
				{
					cout<<"Invalid GPA entered. Enter again: ";
					cin>>string;

					//In case user enters again F.
					if(strcmp(string,"F") == 0)
					{
						ipCheck = 0.0;
					}
					else
					{
						ipCheck = atof(string);
					}
				}

				update.gpa[count] = ipCheck; //assign it to array index.

			}
		}

	}

	//deallocation of dynamically allocated array(of GPA) of particular student and pointing it to null.
	delete [] ptr[index].gpa;
	ptr[index].gpa = 0;

	ptr[index].gpa = update.gpa;		//assign gpa pointer to Student Structure gpa pointer of particular student.
	ptr[index].numCourses = courseNo; //assign updated courses to Student Structure courses of particular student.
	computeOneSGPA(ptr, index, courseNo); //Compute SGPA of particular student.

	//Success message.
	cout<<endl<<"Course added. . "<<endl;

}


//receives pointer, file name and number of records
void quit(Student *ptr, char file[], int records)
{
	//to write data before quiting.
	ofstream fout(file);
	if(!fout)
	{
		cout<<"ERROR!!! File updation failed."<<endl;
	}
	else
	{	//Counters.
		int i=0, j=0;

		//for F grade case.
		double fGrade=1;

		//write records and go to next line(as file format)
		fout<<records<<endl;

		//Loop to write data of all students accordingly.
		for(i=0; i<records; i++)
		{
			//Write rollNumber, name and courses accordingly.
			fout << ptr[i].rollNo << " " << ptr[i].name << endl;
			fout << ptr[i].numCourses << endl;

			//to write GPAs of particular student.
			for(j=0; j<ptr[i].numCourses; j++)
			{
				//if GPA is 0.0, write 'F' in file.
				if(ptr[i].gpa[j] == 0.0)
				{
					fout<<"F";
					fout<<" ";
				}
				else
				{
					//Otherwise write same GPA values.
					fout << ptr[i].gpa[j];
					fout<<" ";
				}

			}
			//new line after writing all GPAs
			fout<<endl;
		}

		//DEALLOCATION Of all Dynamic Allocated Memories.

		//loop wil deallocate all GPA arrays allocated dynamically and pointing pointers to null.
		for(i=0; i<records; i++)
		{
			delete [] ptr[i].gpa;
			ptr[i].gpa = 0;
		}

		//deallocate Student Structure array allocated dynamically and pointing it to null.
		delete [] ptr;
		ptr = 0;

		//Good Bye message :)
		cout<<"---- GoodBye!!! ----"<<endl;
		cout<<endl;

	}

}
