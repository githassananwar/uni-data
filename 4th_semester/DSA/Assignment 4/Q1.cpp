#include <iostream>
#include <fstream>
using namespace std;

float** addScalerMultiple(float** recMatrix, int order, int scRow, int row, float scaler);
float** rowScale(float** recMatrix, int order, int row, float scaler);
float** rowSwap(float** recMatrix, int order, int row1, int row2);
float calculateDeterminant(float** recMatrix, int order);
float** echelonForm(float** recMatrix, int order, int row, int col, int rowMinus, int colIndex, float& balance);

int main()
{
	
	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be created" << endl;
	}
	else
	{
		int order=0;
		float num=0;
		fin>>order;
		
		float ** matrix=new float* [order];
		for(int i=0;i<order;i++)
		{
			matrix[i]=new float [order];
		}

		for(int i=0;i<order;i++)
		{
			for(int j=0;j<order;j++)
			{
				fin>>num;
				matrix[i][j]=num;
			}
		}

		cout<<"Determinant: "<<calculateDeterminant(matrix, order)<<endl;

		for(int i=0;i<order;i++)
		{
			delete [] matrix[i];
			matrix[i]=0;
		}
		delete [] matrix;
		matrix=0;

		fin.close();

	}


	return 0;
}

float** addScalerMultiple(float** recMatrix, int order, int scRow, int row, float scaler)
{
	for(int i=0;i<order;i++)
	{
		recMatrix[scRow][i]=scaler*recMatrix[row][i] + recMatrix[scRow][i];
	}
	return recMatrix;
}

float** rowScale(float** recMatrix, int order, int row, float scaler)
{
	for(int i=0;i<order;i++)
	{
		recMatrix[row][i]=scaler*recMatrix[row][i];
	}
	return recMatrix;
}

float calculateDeterminant(float** recMatrix, int order)
{
	int row=0, col=0, rowMinus=0, colIndex=-1;
	float determinant=1, balance=1;

	recMatrix=echelonForm(recMatrix, order, row, col, rowMinus, colIndex, balance);
	
	for(int i=0;i<order;i++)
    {	
		determinant=determinant*recMatrix[i][i];
	}

	determinant=determinant*balance;

	return determinant;
}

float** echelonForm (float** recMatrix, int order, int row, int col, int rowMinus, int colIndex, float& balance)
{
	bool flag=1;
	
	if(col==order)
	{
		row++;
		if(row==order)
		{
			return recMatrix;
		}
		col=0;
		rowMinus=row;
	}

	if(recMatrix[row][col]!=0 && colIndex<col)
	{
		balance = recMatrix[row][col]*balance;
        recMatrix=rowScale(recMatrix, order, row, (1/recMatrix[row][col]) );
        colIndex=col;
		flag=0;
		col=order-1;
	}

	if(recMatrix[row][col]!=0 && flag)
	{
		recMatrix=addScalerMultiple(recMatrix, order, row, row-rowMinus, -1*recMatrix[row][col] ); 
	}
	
	return echelonForm(recMatrix, order, row, col+1, rowMinus-1, colIndex, balance);

}
