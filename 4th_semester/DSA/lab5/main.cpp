#include "Queue.h"
#include<iostream>
#include <fstream>

using namespace std;

int main()
{
	struct Buy
	{
		int shares;
		double rate;

		void set(int shares, double rate)
		{
			this->shares=shares;
			this->rate=rate;
		}
	};

	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be created" << endl;
	}
	else
	{
		int count=0, shares=0;
		double rate=0, capitalGain=0;
		char status;

		Buy b, bForDequeue;
		bForDequeue.set(0,0);

		Queue<Buy> q(2);
		fin>>count;

		for(int i=0;i<count;i++)
		{
			fin>>status;
			if(status=='b')
			{
				fin>>shares;
				fin>>rate;
				b.set(shares,rate);
				q.enqueue(b);
			}
			else if(status=='s')
			{
				fin>>shares;
				fin>>rate;

				if(!(bForDequeue.shares>0))
				{
					bForDequeue=q.dequeue();
				}

				if(bForDequeue.shares>=shares)
				{
					capitalGain=(shares*rate)-(shares * bForDequeue.rate) + capitalGain;
					bForDequeue.shares = bForDequeue.shares - shares;
				}
				else
				{
					double previousShareRate = bForDequeue.shares * bForDequeue.rate;
					int updateShares=shares-bForDequeue.shares;
					bForDequeue=q.dequeue();
					capitalGain=(shares*rate) - ( previousShareRate + ( updateShares * bForDequeue.rate) ) +capitalGain ;
					bForDequeue.shares=bForDequeue.shares - shares;
				}
			}

		}

		cout<<capitalGain<<endl;
	}

	

	return 0;
}