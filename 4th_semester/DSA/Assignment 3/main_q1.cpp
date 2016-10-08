#include "Deck.h"
#include <iostream>

using namespace std;

int main()
{
	Deck<int> d;

	d.insertAtTail(2);

	cout<<d.getNoOfElements()<<endl;

	return 0;
}

