#ifndef GRAPH_H
#define GRAPH_H

#include<queue>

template<typename T>
class Graph
{
	int vertices;
	int** data;

	void dfs(T v, bool* visited)
	{
		cout<<v<<"   ";
		visited[v]=1;
		for(int i=0;i<vertices;i++)
		{
			if(data[v][i]!=0 &&  visited[i]==0)
			{
				dfs(i,visited);
			}

		}

	}

public:
	Graph(int v)
	{
		vertices=v;
		data=new T* [vertices];
		for(int i=0; i<vertices; i++)
		{
			data[i]=new T [vertices];
		}

		
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				data[i][j]=0;
			}
		}
	}

	void addEdge(int u, int v, int wt=1)
	{
		data[u][v]=wt;

	}

	void deleteEdge(int u, int v)
	{
		data[u][v]=0;
	}

	void display()
	{
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				cout<<data[i][j]<<"	  ";
			}
			cout<<endl;
		}

	}

	void dfs(T vertex)
	{
		bool* visited=new bool [vertices];
		for(int i=0;i<vertices;i++)
		{
			visited[i]=0;
		}

		dfs(vertex, visited);
		
		for(int i=0;i<vertices;i++)
		{
			if(visited[i]==0)
			{
				dfs(i, visited);
			}

		}

		delete [] visited;
		visited=0;

	}

	void bfs(T vertex)
	{
		bool* visited=new bool [vertices];
		for(int i=0;i<vertices;i++)
		{
			visited[i]=0;
		}

		T x=0;
		queue<T> q;
		q.push(vertex);

		while(!q.empty())
		{
			x=q.front();

			if(visited[x]==0)
			{
				visited[x]=1;
				cout<<x<<"   ";
			}

			for(int i=0;i<vertices;i++)
			{
				if(data[x][i]!=0 && visited[i]==0)
				{
					q.push(i);
				}
			}
			q.pop();

		}

		delete [] visited;
		visited=0;

	}

	~Graph()
	{
		for(int i=0;i<vertices;i++)
		{
			delete [] data[i];
			data[i]=0;
		}
		delete [] data;
		data=0;
	}

};

#endif