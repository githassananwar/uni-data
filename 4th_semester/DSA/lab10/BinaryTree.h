#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
class BinaryTree
{
private:
	T* data;
	bool* status;
	int height;

	void VLR(int i)
	{
		cout<<data[i]<<" ";

		if(2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			VLR(2*i+1);
		}
		if(2*i+2 < pow(2.0, height)-1 && status[2*i+2] == 1)
		{
			VLR(2*i+2);
		}
	}

	void LRV(int i)
	{
		if(2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			VLR(2*i+1);
		}
		if(2*i+2 < pow(2.0, height)-1 && status[2*i+2] == 1)
		{
			VLR(2*i+2);
		}

		cout<<data[i]<<" ";
	}

	void LVR(int i)
	{
		if(2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			VLR(2*i+1);
		}

		cout<<data[i]<<" ";
		
		if(2*i+2 < pow(2.0, height)-1 && status[2*i+2] == 1)
		{
			VLR(2*i+2);
		}
	}

	int search(int i, T key)
	{
		int index=-1;
		if(data[i] == key)
		{
			index=i;
		}
		if(index == -1 && 2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			index=search(2*i+1, key);
		}
		if(index == -1 && 2*i+2 < pow(2.0, height)-1 && status[2*i+2] == 1)
		{
			index=search(2*i+2 , key);
		}

		return index;
	}

	void removeSubTree(int i)
	{
		status[i]=0;
		if(2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			removeSubTree(2*i+1);
		}
		if(2*i+2 < pow(2.0, height)-1 && status[2*i+2] == 1)
		{
			removeSubTree(2*i+2);
		}
	}

	void displayAncestor(int i)
	{
		if(i==0)
		{
			cout<<data[i];
			return;
		}
		else if(i>0)
		{
			cout<<data[i]<<" ";
		}

		if(i%2 == 0)
		{
			displayAncestor( (i/2)-1 );
		}
		else
		{
			displayAncestor(i/2);
		}
	}

	int getHeight(int i)
	{
		int h=0;
		int rh=1, lh = 1;
		
		if(2*i+1 < pow(2.0, height) && status[2*i+1] == 1)
		{
			lh = lh+getHeight(2*i+1);
		}
		if(2*i+2 < pow(2.0, height) && status[2*i+2] == 1)
		{
			rh = rh+getHeight(2*i+2);
		}

		if(lh>rh)
		{
			return lh+1;
		}
		else
		{
			return rh+1;
		}

	}

	int getLevel(int i)
	{
		int level=0;
		if(i==0)
		{
			return 1;
		}

		level++;
		if(i%2==0)
		{
			level = level+getLevel( (i/2)-1 );
		}
		else
		{
			level = level+getLevel(i/2);
		}

		return level;
	}

	void dispExplorer(int i)
	{
		if(status[i] == 1)
		{
			for(int c=0; c<getLevelOfNode(data[i]); c++)
			{
				cout<<"\t";
			}

			cout<<data[i]<<endl;

			if(2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
			{
				dispExplorer(2*i+1);
			}
			if(2*i+2 < pow(2.0, height)-1 && status[2*i+2] == 1)
			{
				dispExplorer(2*i+2);
			}
		}
	}

	void displayParenthesis(int i)
	{
		if(status[i] == 1)
		{
			cout<<data[i];
		}
		else
		{
			cout<<" ";
		}

		if(2*i+1 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			cout<<"(";
			displayParenthesis(2*i+1);
		}
		if(2*i+2 < pow(2.0, height)-1 && status[2*i+1] == 1)
		{
			cout<<",";
			displayParenthesis(2*i+2);
			cout<<")";
		}
	}

//----------------------------------------PUBLIC---------------------------------------- 

public:

	BinaryTree(int h)
	{
		height=h;
		data=new T[pow(2.0, h)-1];
		status=new bool[pow(2.0, h)-1];

		for(int i=0; i<pow(2.0, h)-1; i++)
		{
			status[i]=0;
		}
	}

	void setRoot(T val)
	{
		status[0]=1;
		data[0]=val;
	}

	T getRoot()
	{
		if(status[0]==1)
		{
			return data[0];
		}
	}

	void setLeftChild(T parent, T child)
	{
		int i=search(0, parent);
		if(i!=-1)
		{
			if(2*i+1 < pow(2.0, height)-1)
			{
				status[2*i+1]=1;
				data[2*i+1]=child;
			}
		}
	}

	void setRightChild(T parent, T child)
	{
		int i=search(0, parent);
		if(i!=-1)
		{
			if(2*i+2 < pow(2.0 , height)-1)
			{
				status[2*i+2]=1;
				data[2*i+2]=child;
			}
		}
	}

	T getParent(T node)
	{
		int i=search(0 , node);
		if(i!=-1)
		{
			if(i%2 == 0)
			{
				return data[(i/2)-1];
			}
			else
			{
				return data[i/2];
			}
		}
	}

	void remove(T node)
	{
		int i=search(0, node);
		if(i!=-1)
		{
			removeSubTree(i);
		}
	}

	void displayAncestors(T node)
	{
		int i=search(0 , node);
		if(i==-1 || i==0) 
		{
			return;
		}

		if(i%2 == 0)
		{
			i=(i/2)-1;
		}
		else
		{
			i=i/2;
		}

		displayAncestor(i);
	}

	void displayDescendents(T node)
	{
		int i=search(0 , node);
		if(i==-1)
		{
			return;
		}

		if(2*i+2 < pow(2.0, height))
		{
			if(status[2*i+1] == 1)
			{
				VLR(2*i+1);
			}
			if(status[2*i+2]==1)
			{
				VLR(2*i+2);
			}
		}
	}

	int heightOfTree()
	{
		return getHeight(0);
	}

	void preOrder()
	{
		VLR(0);
	}

	void postOrder()
	{
		LRV(0);
	}

	void inOrder()
	{
		LVR(0);
	}

	void levelOrder()
	{
		for(int i=0; i<pow(2.0, height)-1; i++)
		{
			if(status[i] == 1)
			{
				cout<<data[i]<<" ";
			}
		}
	}

	int getLevelOfNode(T node)
	{
		return getLevel(search(0, node)) - 1;
	}

	void displayParenthesisView()
	{
		displayParenthesis(0);
	}

	void displayExplorerView()
	{
		dispExplorer(0);
	}

	~BinaryTree()
	{
		delete [] data;
		delete [] status;
		data=0;
		status=0;
	}

};

#endif
