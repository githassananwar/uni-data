#ifndef CHARSTRING_H
#define CHARSTRING_H
#include<iostream>

using namespace std;

class CharString
{
private:
	char* cstr;
	int size;

public:
	CharString();
	CharString(const char*);
	CharString(const char*, int);
	CharString(const CharString &);
	CharString(const CharString&, int);
	int Size() const;
	void clear();
	friend ostream& operator<<(ostream&,const CharString&);
	CharString& operator=(const char*);
	void CopyFrom(const char*, int, int=0);
	CharString& operator=(const CharString&);
	void CopyFrom(const CharString&, int, int=0);
	CharString Substring(int , int) const;
	int FindSubstring(const char*, int=0) const;
	int FindSubstring(const CharString&, int=0) const;
	void concat (const char*);
	void concat (const char*, int, int=0);
	void append (const CharString& str);
	void append (const CharString&, int, int=0);
	~CharString();

};


#endif
