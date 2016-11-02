#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>


using namespace std;

struct node
{
	int v;
	int w;
};

typedef struct node Node;
typedef Node *Nodeptr;


void shortestPathInDAG(vector<vector<Nodeptr> > vec, int src)
{
	int v=vec.size();
	vector<int> indegree(v,0);

	for(int i=0;i<v;i++)
	{
		vector<Nodeptr> cur=vec[i];
		for(int j=0;j<cur.size();j++)
		{
			indegree[cur[j]->v]++;
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

		vector<Nodeptr> cur=vec[s];
		for(int i=0;i<cur.size();i++)
		{
			indegree[cur[i]->v]--;
			if(indegree[cur[i]->v]==0)
				q1.push(cur[i]->v);
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

	vector<int> dist(v,INT_MAX);
	dist[src]=0;
	
	for(int i=0;i<result.size();i++)
	{
		//update distances of all adjacent elements
		int cur=result[i];
		if(dist[cur]!=INT_MAX)
		{
			vector<Nodeptr> temp=vec[cur];
			for(int j=0;j<temp.size();j++)
			{
				if(dist[temp[j]->v] > dist[cur]+temp[j]->w)
					dist[temp[j]->v] = dist[cur]+temp[j]->w;
			}
		}
	}

	cout<<"shortest paths from src: "<<src<<endl;
	for(int i=0;i<dist.size();i++)
	{
		if(dist[i]==INT_MAX)
			cout<<"INF ";
		else
			cout<<dist[i]<<" ";
	}
		cout<<endl;

}
	




int main()
{
	int v;
	cin>>v;
	vector<vector<Nodeptr> > vec(v);
	int e;
	cin>>e;
	while(e>0)
	{
		int x,y,z;
		cin>>x>>y>>z;
		Nodeptr newnode = (Nodeptr)malloc(sizeof(Node));
		newnode->v=y;
		newnode->w=z;
		vec[x].push_back(newnode);
		e--;
	}

	for(int i=0;i<v;i++)
	{
		cout<<i<<" : ";
		vector<Nodeptr> temp=vec[i];
		for(int j=0;j<temp.size();j++)
		{
			cout<<temp[j]->v<<","<<temp[j]->w<<" ";
		}
		cout<<endl;
	}

	shortestPathInDAG(vec,1);
	
	return 0;
}


