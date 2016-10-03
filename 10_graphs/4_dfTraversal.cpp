#include<bits/stdc++.h>
using namespace std;

void auxUtil(vector<vector<int> > vec, int startNode, vector<int> &visited)
{
	visited[startNode]=1;
	cout<<startNode<<" ";
	vector<int> temp=vec[startNode];
	for(int i=0;i<temp.size();i++)
	{
		if(visited[temp[i]]==0)
			auxUtil(vec,temp[i],visited);
	}
}

void auxFunc(vector<vector<int> > vec, int startNode)
{
	vector<int> visited(vec.size(),0);
	auxUtil(vec,startNode,visited);
	cout<<endl;
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
	int startNode;
	cin>>startNode;
	auxFunc(vec,startNode);
	return 0;
}


