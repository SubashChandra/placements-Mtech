#include<bits/stdc++.h>
using namespace std;

void auxFunc(vector<vector<int> > vec, vector<int> &visited, int cur, stack<int> &st)
{
	if(visited[cur]==1)
		return;
	visited[cur]=1;

	vector<int> temp=vec[cur];
	for(int i=0;i<temp.size();i++)
	{
		if(visited[temp[i]]==0)
			auxFunc(vec,visited,temp[i],st);
	}
	st.push(cur);
}

void topological(vector<vector<int> > vec)
{
	vector<int> visited(vec.size(),0);
	int i;
	stack<int> st;
	for(i=0;i<vec.size();i++)
	{
		auxFunc(vec,visited,i,st);
	}

	while(st.size()!=0)
	{
		cout<<st.top()<< " ";
		st.pop();
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
	topological(vec);
	return 0;
}


