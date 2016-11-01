#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

bool isCyclicUtil(vector<vector<int> > &vec, vector<int> &visited, int u, int parent)
{
	visited[u]=1;

	vector<int> cur=vec[u];
	for(int i=0;i<cur.size();i++)
	{
		//if an adjacent is not visited, then recur on that
		if(visited[cur[i]]==0)
		{
			if(isCyclicUtil(vec,visited,cur[i],u))
				return true;
		}
		//if an adjacent is visted and its not parent of the current vertex, then there is a cycle
		else if(cur[i]!=parent)
			return true;

	}
	return false;
}


bool isTree(vector<vector<int> > &vec)
{
	
	vector<int> visited(vec.size(),0);
	isCyclicUtil(vec,visited, 0,-1);
	for(int i=0;i<visited.size();i++)
	{
		if(visited[i]==0)
			return false;
	}
	return true;

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
	if(isTree(vec))
		cout<<"is a tree"<<endl;
	else
		cout<<"not a tree"<<endl;

	return 0;
}


