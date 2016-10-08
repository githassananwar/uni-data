#include<iostream>
#include<fstream>

using namespace std;

bool maze(char** matrix, int order, int si, int sj, int di, int dj, ofstream& fout)
{
	bool flag=0;
	matrix[si][sj]='*';

	if(si==di && sj==dj)
	{
		return 1;
	}

	if(!flag && sj+1<order && matrix[si][sj+1]=='1')
	{
		flag=maze(matrix,order,si,sj+1,di,dj, fout);
	}

	if(!flag && si+1<order && matrix[si+1][sj]=='1')
	{
		flag=maze(matrix,order,si+1,sj,di,dj, fout);
	}
	
	if(!flag && si-1>0 && matrix[si-1][sj]=='1')
	{
		flag=maze(matrix,order,si-1,sj,di,dj, fout);
	}

	if(!flag && sj-1>0 && matrix[si][sj-1]=='1')
	{
		flag=maze(matrix,order,si,sj-1,di,dj, fout);
	}
	
	if(flag==1)
	{
		fout<<"("<<si<<","<<sj<<")"<<"   ";
	}

	return flag;
	
}

int main()
{
	ifstream fin("in.txt");
	if(!fin)
	{
		cout<<"ERROR!!! File not found"<<endl;
	}
	else
	{
		int order, si, sj, di, dj;
		fin>>order;
		fin>>si;
		fin>>sj;
		fin>>di;
		fin>>dj;

		char ** matrix=new char* [order];

		for(int i=0;i<order;i++)
		{
			matrix[i]=new char [order];
		}

		for(int i=0;i<order;i++)
		{
			for(int j=0;j<order;j++)
			{
				fin>>matrix[i][j];
			}
		}

		fin.close();

		ofstream fout("out.txt");
		if(!fout)
		{
			cout<<"ERROR!!! File can't be created."<<endl;
		}
		else
		{
			fout<<order<<endl;
			fout<<si<<" "<<sj<<endl;
			fout<<di<<" "<<dj<<endl;
			if( maze(matrix,order,si,sj,di,dj,fout) )
			{
				fout<<endl<<endl;
				for(int i=0;i<order;i++)
				{
					for(int j=0;j<order;j++)
					{
						fout<<matrix[i][j]<<" ";
					}
					fout<<endl;

				}
			
				fout.close();
			}
			
			fin.close();

		}

	}

	return 0;
}