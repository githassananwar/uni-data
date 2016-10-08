#ifndef MY_QUEUE_EXCEPTIONS
#define MY_QUEUE_EXCEPTIONS

#include <exception>
using namespace std ;

class MyQueueExceptions : public exception
{
public:
	MyQueueExceptions(char * error) : exception(error)
	{

	}
	
};

#endif