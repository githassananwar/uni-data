#include "CharString.h"
#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
	int houseNo;
	char block;
	int streetNo;
	CharString city;
public:

	void operator=(const Address&);
	Address(int=0 , char='.' , int=0 , CharString="" );
	void displayAddress();
	~Address(void);
};


#endif
