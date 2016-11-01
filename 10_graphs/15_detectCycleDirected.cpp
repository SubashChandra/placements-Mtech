#include<cstdio>
#include<iostream>
#include<vector>


using namespace std;

bool isCyclicUtil(vector<vector<int> > &vec, int v, vector<int> &visited, vector<int> &recStack)
{
	if(visited[v]==0)
	{
		//mark current node as visited and part of recursive stack 
		visited[v]=1;
		recStack[v]=1;

		vector<int> cur=vec[v];
		for(int i=0;i<cur.size();i++)
		{
			if(visited[cur[i]]==0  && isCyclicUtil(vec,cur[i],visited,recStack))
				return true;
			else if(recStack[cur[i]]==1)
				return true;
		}
	}
	//remove vertex from recursive stack
	recStack[v]=0;
	return false; //no cycle
}

bool isCyclic(vector<vector<int> > &vec)
{
	int v=vec.size();
	
	vector<int> visited(v,0);
	vector<int> recStack(v,0);

	for(int i=0;i<v;i++)
	{
		if(isCyclicUtil(vec,i,visited,recStack))
			return true;
	}
	return false;
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

	if(isCyclic(vec))
		cout<<"Contains Cycle"<<endl;
	else
		cout<<"No Cycle"<<endl;
	return 0;
}


