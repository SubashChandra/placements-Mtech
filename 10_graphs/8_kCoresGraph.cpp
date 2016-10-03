#include<bits/stdc++.h>
using namespace std;

bool dft(vector<vector<int> > vec, vector<int> &visited, int cur, vector<int> &degree, int k)
{
	visited[cur]=1;
	
	vector<int> temp=vec[cur];
	for(int i=0;i<temp.size();i++)
	{
		if(degree[cur]<k)
			degree[temp[i]]--;


		//if adjacent is not processed process it
		if(visited[temp[i]]==0)
		{
			//if degree of adjacent after processing becomes less than k,
			//den reduce degree of cur also
			if(dft(vec,visited,temp[i],degree,k))
				degree[cur]--;
		}

	}
	//return true if degree of cur is less than k
	return degree[cur]<k;
}	



void auxFunc(vector<vector<int> > vec, int k)
{
	int v=vec.size();
	vector<int> visited(v,0);

	int minDeg=INT_MAX;
	int startVertex;

	//store degrees of all vertices
	vector<int> degree(v);
	int i,j;
	for(i=0;i<v;i++)
	{
		degree[i]=vec[i].size();
		cout<<i<<"*: "<<degree[i]<<endl;
		if(degree[i]<minDeg)
		{
			minDeg=degree[i];
			startVertex=i;
		}
	}
	cout<<"*************"<<endl;

	dft(vec,visited, startVertex,degree,k);

	//dfs traversal to update degree of all vertices
	for(i=0;i<v;i++)
	{
		if(visited[i]==0)
			dft(vec,visited,i,degree,k);
	}


	for(i=0;i<v;i++)
	{
		if(degree[i]>=k)
		{
			cout<<i<<": ";
			vector<int> temp=vec[i];
			for(int j=0;j<temp.size();j++)
			{
				if(degree[temp[j]]>=k)
					cout<<temp[j]<<" ";
			}
			cout<<endl;
		}
	}
}




int main()
{
	int v;
	cin>>v;
	vector<vector<int> > vec(v,vector<int>(0));
	int e;
	cin>>e;
	while(e>0)
	{
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
		e--;
	}

	for(int i=0;i<v;i++)
	{
		cout<<i<<" : ";
		vector<int> temp=vec[i];
		for(int j=0;j<temp.size();j++)
		{
			cout<<temp[j]<<" ";
		}
		cout<<endl;
	}
	int k;
	cin>>k;
	auxFunc(vec,k);
	return 0;
}


