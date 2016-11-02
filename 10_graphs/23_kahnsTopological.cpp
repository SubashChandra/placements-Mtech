#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>


using namespace std;



void kahns(vector<vector<int> > vec)
{
	int v=vec.size();
	vector<int> indegree(v,0);

	for(int i=0;i<v;i++)
	{
		vector<int> cur=vec[i];
		for(int j=0;j<cur.size();j++)
		{
			indegree[cur[j]]++;
		}
	}

	//create a queue and enqueue all vertices with indegree 0
	queue<int> q1;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0)
			q1.push(i);
	}
	
	//track no of visited vertices
	int count=0;

	//result
	vector<int> result;


	while(q1.size()!=0)
	{
		int s=q1.front();
		q1.pop();

		result.push_back(s);

		vector<int> cur=vec[s];
		for(int i=0;i<cur.size();i++)
		{
			indegree[cur[i]]--;
			if(indegree[cur[i]]==0)
				q1.push(cur[i]);
		}
		count++;
	}

	if(count!=v)
	{
		cout<<"there exists a cycle"<<endl;
		return;
	}
	cout<<"topological sort"<<endl;
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	cout<<endl;
}




int main()
{
	int v;
	cin>>v;
	vector<vector<int> > vec(v);
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

	kahns(vec);
	
	return 0;
}


