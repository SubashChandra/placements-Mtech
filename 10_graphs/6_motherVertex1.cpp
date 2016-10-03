#include<bits/stdc++.h>
using namespace std;

void dft(vector<vector<int> > vec, int cur, vector<int> &visited)
{
	visited[cur]=1;
	vector<int> temp=vec[cur];
	for(int i=0;i<temp.size();i++)
	{
		if(visited[temp[i]]==0)
			dft(vec, temp[i],visited);
	}
}

void auxFunc(vector<vector<int> > vec)
{
	int i;
	for(i=0;i<vec.size();i++)
	{
		
		vector<int> visited(vec.size(),0);
		visited[i]=1;
		dft(vec,i,visited);
		
		int count=0;
		for(int j=0;j<vec.size();j++)
			if(visited[j]==1)
				count++;
		if(count==vec.size())
			cout<<i<<endl;
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
	auxFunc(vec);
	return 0;
}


