#include<iostream>
using namespace std;


int main()
{

	int countRow=1, countCol=1, size=0, mid=0, start=0, end=0;

	cout<<"Enter size: ";
	cin>>size;

	mid=(size/2)+1;

	start=1;
	end=size;

	while(countRow<=size)
	{
		//upper part
		if(countRow<mid)
		{

			for(countCol=1;countCol<=size;countCol++)
			{

				if(countCol==start||countCol==end)
				{
					cout<<"*";

				}
				else
				{

					cout<<" ";
				}

			}

			start++;
			end--;

		}

		//Lower part
		else
		{
			for(countCol=1;countCol<=size;countCol++)
			{


				if(countCol==start||countCol==end)
				{
					cout<<"*";

				}
				else
				{

					cout<<" ";
				}

			}

			start--;
			end++;

		}


		countRow++;
		cout<<endl;



	}







	return 0;
}
