#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int s;
	int d;
	int w;
};

typedef struct node Node;
typedef Node *Nodeptr;


void bellman(vector<Nodeptr> edges, int src, int V)
{
	int e=edges.size();

	vector<int> dist(V,INT_MAX);
	dist[src]=0;

	//relax all edges v-1 no of times
	for(int i=1;i<=V-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u=edges[j]->s;
			int v=edges[j]->d;
			int w=edges[j]->w;

			if(dist[u] != INT_MAX && dist[v]>dist[u]+w)
				dist[v]=dist[u]+w;
		}
	}

	//check for negative edge cycle

	for(int i=0;i<e;i++)
	{
		int u=edges[i]->s;
		int v=edges[i]->d;
		int w=edges[i]->w;

		if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
		{
			cout<<"contains negative edge cycle"<<endl;
			return;
		}
	}

	cout<<"distance from source: "<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int e,v;
	cin>>v;
	cin>>e;
	vector<Nodeptr> edges(e);
	for(int i=0;i<e;i++)
	{
		edges[i]=(Nodeptr)malloc(sizeof(Node));
		cin>>edges[i]->s>>edges[i]->d>>edges[i]->w;
	}

	bellman(edges,0,v);
	return 0;
}
		


