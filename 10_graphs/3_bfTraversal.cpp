#include<bits/stdc++.h>
using namespace std;

void bft(vector<vector<int> >vec, int startNode)
{
	int v=vec.size();
	vector<int> visited(v,0);

	queue<int> q;
	q.push(startNode);
	visited[startNode]=1;
	while(q.size()!=0)
	{
		int temp=q.front();
		cout<<temp<<" ";
		q.pop();
		vector<int> cur=vec[temp];
		for(int i=0;i<cur.size();i++)
		{
			if(visited[cur[i]]==0)
			{
				visited[cur[i]]=1;
				q.push(cur[i]);
			}
		}
	}
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

	cout<<"breadth first traversal"<<endl;
	int startNode;
	cin>>startNode;
	bft(vec,startNode);
	return 0;
}


