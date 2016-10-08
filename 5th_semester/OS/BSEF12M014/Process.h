#ifndef PROCESS_H
#define PROCESS_H

class Process
{

public:
	int arrivalTime;
	int cpuBurst;
	int priority;
	int pNum;

	int startTime;
	int waitingTime;

	Process()
	{
		arrivalTime=0;
		cpuBurst=0;
		priority=0;

		startTime=0;
		waitingTime=0;

	}


};


#endif