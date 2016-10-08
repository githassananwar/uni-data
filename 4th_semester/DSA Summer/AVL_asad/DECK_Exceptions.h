#ifndef MY_QUEUE_EXCEPTIONS
#define MY_QUEUE_EXCEPTIONS

#include <exception>
using namespace std ;

class DECK_Exceptions : public exception
{

public:
	DECK_Exceptions(char * error) : exception(error) 
	{

	}
};

#endif