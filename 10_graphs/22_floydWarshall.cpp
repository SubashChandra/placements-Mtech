#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void floydWarshall(vector<vector<int> > vec)
{
	int v=vec.size();
	vector<vector<int> > dist(v,vector<int>(v));
	int i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			dist[i][j]=vec[i][j];

	int k;
	// add all vertices one by one to the set of intermediate vertices
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}


	cout<<"all pairs shortest paths"<<endl;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(dist[i][j]==INT_MAX)
				cout<<"INF ";
			else
				cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int v;
	cin>>v;
	vector<vector<int> > vec(v,vector<int>(v,INT_MAX));
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		vec[s][d]=w;
	}

	for(int i=0;i<v;i++)
		vec[i][i]=0;

	floydWarshall(vec);
	return 0;
}
