#include "Mat.h"
#include<iostream>
#include<cmath>

using namespace std;


Mat::Mat()
{
	arr=0;
	col=0;
	row=0;

}

Mat ::Mat (const Mat & m)
{
	col=m.col;
	row=m.row;
	arr=new int*[row];
	for(int i=0;i<row;i++)
	{
		arr[i]=new int[col];
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			arr[i][j]=m.arr[i][j];
		}
		
	}

}

Mat& Mat::input()
{
	cout<<"Enter rows: ";
	cin>>row;

	cout<<"Enter columns: ";
	cin>>col;

	arr=new int*[row];
	for(int i=0;i<row;i++)
	{
		arr[i]=new int[col];
	}

	cout<<"Enter elements:-"<<endl;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"Enter in row "<<i+1<<" , column "<<j+1<<" : ";
			cin>>arr[i][j];
		}
		
	}

	return *this;

}


Mat& Mat :: operator=(const Mat & m)
{
	row=m.row;
	col=m.col;

	if(arr!=0)
	{
		for(int i=0;i<row;i++)
		{
			delete [] arr[i];

		}
		arr=0;
	}

	arr=new int*[row];
	for(int i=0;i<row;i++)
	{
		arr[i]=new int[col];
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{	
			arr[i][j]=m.arr[i][j];

		}
	}
	
	return *this;

}

Mat Mat:: operator+(const Mat & m)
{
	Mat mr;
	mr.col=col;
	mr.row=row;

	
	mr.arr=new int* [mr.row];
	for(int i=0;i<mr.row;i++)
	{
		mr.arr[i]=new int[mr.col];
	}
	for(int i=0;i<mr.row;i++)
	{
		for(int j=0;j<mr.col;j++)
		{	
			mr.arr[i][j]=0;

		}
	}

	if(row==m.row && col==m.col)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				mr.arr[i][j]=arr[i][j]+m.arr[i][j];
			}
		}

	}
	else
	{
		cout<<"Error Addition!!!"<<endl;
	}
	

	return mr;

}

Mat Mat :: operator*(const Mat & m)
{
	int i=0, j=0, k=0, sum=0;
	Mat mr;
	mr.col=m.col;
	mr.row=row;

	mr.arr=new int* [mr.row];
	for(i=0;i<mr.row;i++)
	{
		mr.arr[i]=new int[mr.col];
	}
	for(i=0;i<mr.row;i++)
	{
		for(j=0;j<mr.col;j++)
		{	
			mr.arr[i][j]=0;

		}
	}

	if(col==m.row)
	{
		for(i=0;i<mr.col;i++)
		{
			for(j=0;j<mr.row;j++)
			{
				sum=0;
				for(k=0;k<col;k++)
				{
					sum=sum+arr[i][k]*m.arr[k][j];
				}
				mr.arr[i][j]=sum;
				
			}
			
		}
	}
	else
	{
		cout<<"Error Multiplication!!!"<<endl;	
	}

	return mr;


}

Mat Mat :: operator!()
{
	int i=0, j=0, det=0;
	Mat mr;
	mr.col=col;
	mr.row=row;

	mr.arr=new int* [mr.row];
	for(i=0;i<mr.row;i++)
	{
		mr.arr[i]=new int[mr.col];
	}
	for(i=0;i<mr.row;i++)
	{
		for(j=0;j<mr.col;j++)
		{	
			mr.arr[i][j]=0;

		}
	}
	if(row==3 && col==3)
	{
		det=arr[0][0]*( (arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1]) ) - arr[0][1]*( (arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0]) ) + arr[0][2]*( (arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]) );


		if(det!=0)
		{
			mr.arr[0][0]=pow(-1,(double)(2))* (arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1]);
			mr.arr[0][1]=pow(-1,(double)(3))* (arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0]);
			mr.arr[0][2]=pow(-1,(double)(4))* (arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);

			mr.arr[1][0]=pow(-1,(double)(3))* (arr[0][1]*arr[2][2]-arr[0][2]*arr[2][1]);
			mr.arr[1][1]=pow(-1,(double)(4))* (arr[0][0]*arr[2][2]-arr[0][2]*arr[2][0]);
			mr.arr[1][2]=pow(-1,(double)(5))* (arr[0][0]*arr[2][1]-arr[0][1]*arr[2][0]);

			mr.arr[2][0]=pow(-1,(double)(4))* (arr[0][1]*arr[1][2]-arr[0][2]*arr[1][1]);
			mr.arr[2][1]=pow(-1,(double)(5))* (arr[0][0]*arr[1][2]-arr[0][2]*arr[1][0]);
			mr.arr[2][2]=pow(-1,(double)(6))* (arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]);


			int r=0, c=0;
			for(i=0;i<col;i++)
			{
				c=0;
				for(j=0;j<row;j++)
				{
					mr.arr[i][j]=mr.arr[r][c];
					mr.arr[i][j]=mr.arr[i][j]/det;
					c++;
				}
				r++;
			}

		}
		else
		{
			cout<<"Inverse error. Determinant is 0!!!"<<endl;
		}

	}
	else
	{
		cout<<"Inverse error!!!"<<endl;
	}
	
	return mr;

}

void Mat :: output()
{
	cout<<"Matrix:-"<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<arr[i][j]<<"     ";
		}
		cout<<endl;

	}
	

}

Mat::~Mat()
{
	for(int i=0;i<row;i++)
	{
		delete [] arr[i];

	}
	arr=0;

}
