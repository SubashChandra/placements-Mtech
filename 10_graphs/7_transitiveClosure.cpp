#include<bits/stdc++.h>
using namespace std;

void dft(vector<vector<int> > vec, vector<vector<int> > &tc, int u, int v)
{
	tc[u][v]=1;
	vector<int> temp=vec[v];
	for(int i=0;i<temp.size();i++)
	{
		if(tc[u][temp[i]]==0)
			dft(vec,tc,u,temp[i]);
	}
}



void transitiveClosure(vector<vector<int> > vec)
{
	vector<vector<int> > tc(vec.size(),vector<int>(vec.size(),0));

	for(int i=0;i<vec.size();i++)
	{
		dft(vec,tc,i,i);
	}

	int v=vec.size();
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<tc[i][j]<<" ";
		}
		cout<<endl;
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

	transitiveClosure(vec);
	return 0;
}


