#ifndef PT_H
#define PT_H



struct Pt
{
	int x;
	int y;

	Pt(int =0,int =0);
	void set(int, int);
	~Pt(void);
};

#endif