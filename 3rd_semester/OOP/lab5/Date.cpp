#include "Date.h"
#include<iostream>

using namespace std;

const int Date::daysInMonth[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date()
{
	day=1;
	month=1;
	year=1990;

}

istream& operator>>(istream& input, Date & d)
{
	cout<<"Enter date(DD/MM/YYYY): ";
	input>>d.day>>d.month>>d.year;
	while(d.year<1900||d.year>2100)
	{
		cout<<"Invalid year. Enter again (YYYY): ";
		input>>d.year;
	}
	while(d.month<1||d.month>12)
	{
		cout<<"Invalid month. Enter again (MM): ";
		input>>d.month;
	}
	while(d.day<1 || d.day > d.daysInMonth[d.month])
	{
		cout<<"Invalid day. Enter again (DD): ";
		input>>d.day;
	}

	return input;

}

ostream& operator << (ostream & out, Date& d)
{
	out<<"Date: "<<d.day<<" / "<<d.month<<" / "<<d.year<<endl;
	
	return out;
}


bool Date :: operator !=(const Date& d)
{
	if(year!=d.year)
	{
		return 1;
	}
	else
	{
		if(month!=d.month)
		{
			return 1;
		}
		else
		{
			if(day!=d.day)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	
}

int Date :: operator -(const Date& d)
{
	int leftDate=0, rightDate=0, monDays=0, ans=0;
	for(int i=1;i<month;i++)
	{
		monDays=d.daysInMonth[i]+monDays;
	}
	leftDate=day+monDays+(year*365);

	monDays=0;
	for(int i=1;i<d.month;i++)
	{
		monDays=d.daysInMonth[i]+monDays;
	}
	rightDate=d.day+monDays+(d.year*365);

	ans=leftDate-rightDate;

	return ans;

}

Date operator +(int n, const Date& d)
{
	Date dr;
	dr=d;
	while(n>365)
	{
		dr.year=dr.year+1;
		n=n-365;
	}
	while(n > dr.daysInMonth[dr.month])
	{
		n=n-dr.daysInMonth[dr.month];
		dr.month=dr.month+1;
		if(dr.month>12)
		{
			dr.month=1;
			dr.year=dr.year+1;
		}

	}
	dr.day=dr.day+n;
	if(dr.day > dr.daysInMonth[dr.month])
	{
		dr.day=dr.day - dr.daysInMonth[dr.month];
		dr.month=dr.month+1;
		if(dr.month>12)
		{
			dr.month=1;
			dr.year=dr.year+1;
		}
	}

	return dr;
}


Date Date :: operator+(int n)
{
	Date dr;
	dr=*this;
	while(n>365)
	{
		dr.year=dr.year+1;
		n=n-365;
	}
	while(n > dr.daysInMonth[dr.month])
	{
		n=n-dr.daysInMonth[dr.month];
		dr.month=dr.month+1;
		if(dr.month>12)
		{
			dr.month=1;
			dr.year=dr.year+1;
		}

	}
	dr.day=dr.day+n;
	if(dr.day > dr.daysInMonth[dr.month])
	{
		dr.day=dr.day - dr.daysInMonth[dr.month];
		dr.month=dr.month+1;
		if(dr.month>12)
		{
			dr.month=1;
			dr.year=dr.year+1;
		}
	}

	return dr;
}

Date& Date :: operator ++() //++i
{
	day=day+1;
	if(day>this->daysInMonth[month])
	{
		day=day-this->daysInMonth[month];
		month=month+1;
		if(month>12)
		{
			month=1;
			year=year+1;
		}
		
	}

	return *this;

}

Date Date :: operator ++(int) //i++
{
	Date dr=*this;
	day=day+1;
	if(day>this->daysInMonth[month])
	{
		day=day-this->daysInMonth[month];
		month=month+1;
		if(month>12)
		{
			month=1;
			year=year+1;
		}
	}

	return dr;

}

Date Date :: operator --() //--i
{
	day=day-1;
	if(day==0)
	{
		month=month-1;
		if(month<1)
		{
			month=12;
			year=year-1;
		}
		day=this->daysInMonth[month];	
	}
	if(year<1900)
	{
		day=0;
		month=0;
		year=0;
	}

	return *this;

}

Date Date :: operator --(int) //i--
{
	Date dr=*this;
	day=day-1;
	if(day==0)
	{
		month=month-1;
		if(month<1)
		{
			month=12;
			year=year-1;
		}
		day=this->daysInMonth[month];
		
	}
	if(year<1900)
	{
		day=0;
		month=0;
		year=0;
	}

	return dr;

}

Date::~Date(void)
{
}
