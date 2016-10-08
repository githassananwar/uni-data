#ifndef MAT_H
#define MAT_H
class Mat
{
private:
	int row;
	int col;
	int** arr;

public:
	Mat();
	Mat& input();
	void output();
	Mat(const Mat &);
	Mat operator+(const Mat &);
	Mat operator*(const Mat &);
	Mat& operator=(const Mat &);
	Mat operator!();

	~Mat();
};


#endif
