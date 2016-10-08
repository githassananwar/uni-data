#include "LSLL.h"
#include <iostream>
using namespace std;

int main()
{
	Lsll<int> list;
	list.insertAtHead(2);
	/*list.insertAtHead(3);
	list.insertAtHead(4);
	list.insertAtHead(5);*/
	list.reverseListIt();
	list.display();
	list.reverseListRe();
	list.display();

	return 0;
}