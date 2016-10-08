#include<iostream>

using namespace std;

void printPascal(int);

int main()
{

	int n=0;
	cout<<"Enter size: ";
	cin>>n;

	printPascal(n);

	cin.get();
	cin.get();

	return 0;

}


void printPascal(int n)
{
	//DMA of 2d array.
	int **p=new int*[n];

	for(int i=0;i<n;i++)
	{
		p[i]=new int[i+1];

	}

	
	int r=0, c=0, rPlace=0, cPlace=0;

	//Placement of 1s in 1st column.
	for(r=0;r<n;r++)
	{
		p[r][c]=1;

	}

	r--;

	//Placement of 1s in last row.
	for(c=0;c<n;c++)
	{
		p[r][c]=1;

	}

	//Set column index to 1
	c=1;

	//For calculating and placing values in remaining triangle.
	for(rPlace=n-2;rPlace>=1;rPlace--)
	{
		for(cPlace=1;cPlace<=rPlace;cPlace++)
		{
			p[rPlace][cPlace]=p[r][c]+p[r-1][c-1];
			c++;
		}

		r--;
		c=1;

	}

	//to Print right angle triangle form.
	for(r=0;r<n;r++)
	{
		for(c=0;c<=r;c++)
		{
			cout<<p[r][c]<<"   ";
		}
		cout<<endl;

	}

	cout<<endl<<endl;

	//to Print tree shape triangle form.
	r=n-1, c=0;
	int spBefore=n-1, row=0, col=0;

	for(row=0;row<n;row++)
	{
	    r=n-1;
	    c=row;

        for(int i=0;i<spBefore;i++)
        {
            cout<<" ";
        }

	    for(col=0;col<=row;col++)
	    {

	        cout<<p[r][c];

            for(int i=0;i<1;i++)
	        {
	            cout<<" ";
	        }

	        r--;
	        c--;


	    }

	    cout<<endl;
	    spBefore--;

	}


	//Deallocation of Dynamic memory.
	for(int i=0;i<n;i++)
	{
		delete [] p[i];
		p[i]=0;

	}

	delete [] p;
	p=0;


}



