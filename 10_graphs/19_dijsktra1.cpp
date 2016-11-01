#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int minDist(vector<int> &dist, vector<int> &spSet)
{
	int min=INT_MAX,minIndex;
	for(int i=0;i<dist.size();i++)
	{
		if(spSet[i]==0 && dist[i]<min)
		{
			min=dist[i];
			minIndex=i;
		}
	}
	return minIndex;
}
		


void dijkstra(vector<vector<int> > &vec, int src)
{
	//set to 1 when i is included 
	vector<int> spSet(vec.size(),0);	
	
	//dist[i] will hold shortest dist from src to i
	vector<int> dist(vec.size(),INT_MAX);

	//src to itself is 0
	dist[src]=0;

	//find shortest path for all the vertices
	int size=vec.size();
	for(int count=0;count<size-1;count++)
	{
		//pick min dist vertex from  the set of vertices not yet processed
		int u=minDist(dist,spSet);
		//mark the picked vertex as procesed
		spSet[u]=1;

		//update dist values of adjacent vertices of teh picked vertex
		for(int v=0;v<size;v++)
		{
			//update only if its not in spSet, there is an edge from u to v
			if(spSet[v]==0 && vec[u][v]!=0 && dist[u]!=INT_MAX && dist[u]+vec[u][v]<dist[v])
				dist[v]=dist[u]+vec[u][v];
		}

	}

	//print sol
	cout<<"distance from src: "<<src<<endl;
	for(int i=0;i<size;i++)
		cout<<dist[i]<<" ";
	cout<<endl;

}

int main()
{
	int v;
	cin>>v;
	int e;
	cin>>e;

	vector<vector<int> > vec(v,vector<int>(v,0));

	int i,j,x,y,w;
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		vec[x][y]=w;
		vec[y][x]=w;
	}


	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	dijkstra(vec,0);
	return 0;
}


