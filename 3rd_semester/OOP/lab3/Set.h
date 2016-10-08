#ifndef SET_H
#define SET_H

class Set
{
	int *set;
	int size;

public:
	Set(int=0);
	Set(const Set&);
	Set Union(const Set& );
	Set intersection(const Set&) const;
	bool isEqualTo(const Set& ) const;
	void print( ) const;

	~Set();
};

#endif