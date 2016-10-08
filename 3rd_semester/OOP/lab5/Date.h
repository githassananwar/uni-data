#ifndef Date_H
#define Date_H
#include<iostream>

using namespace std;

class Date //My Class Name is Date. .
{
private:
	int day;
	int month;
	int year;
	static const int daysInMonth[ 13 ]; 

public:
	Date();
	bool operator >=(const Date&);
	bool operator !=(const Date&);
	int operator -(const Date&);
	friend Date operator +(int,const Date&);
	Date operator +(int);
	Date& operator ++(); //++i
	Date operator ++(int); //i++
	Date operator --(); //--i
	Date operator --(int); //i--
	friend istream& operator >> (istream &, Date&);
	friend ostream& operator << (ostream &, Date&);
	~Date(void);
};


#endif
