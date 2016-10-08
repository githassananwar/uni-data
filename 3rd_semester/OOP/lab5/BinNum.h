#ifndef BINNUM_H
#define BINNUM_H
class BinNum
{
private:
	bool* arr;
	int size;
public:
	BinNum();
	BinNum(int);
	BinNum(const BinNum&);
	BinNum& operator=(const BinNum&);
	bool& operator[](int) const;
	BinNum operator!() const;
	void operator()(int, int);
	void print();
	~BinNum();
};

#endif 