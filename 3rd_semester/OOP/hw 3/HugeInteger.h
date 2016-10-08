#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include<iostream>

using namespace std;

class HugeInteger
{
private:
	char* arr;
	char sign;
public:
	HugeInteger();
	HugeInteger(const HugeInteger&);
	friend istream& operator>>(istream&, HugeInteger&);
	friend ostream& operator<<(ostream& ,const HugeInteger&);
	HugeInteger& operator=(const HugeInteger&);
	HugeInteger operator+(const HugeInteger&);
	HugeInteger operator-(const HugeInteger&);
	bool operator==(const HugeInteger&);
	bool operator!=(const HugeInteger&);
	bool operator>(const HugeInteger&);
	bool operator<(const HugeInteger&);
	bool operator>=(const HugeInteger&);
	bool operator<=(const HugeInteger&);

	//My function
	bool greater(const HugeInteger&);
	
	~HugeInteger();

};


#endif

