#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

#define INF INT_MAX

using namespace std;

void shortestPath(vector<vector<pair<int,int> > > &vec, int src)
{
	int V=vec.size();
	//creare a set to store vertices that are being processes
	set<pair<int, int> > setds;

	//crete a vector for distances
	vector<int> dist(V,INF);

	//
	setds.insert(make_pair(0,src));
	dist[src]=0;

	//looping tll all shortest distances are finalized
	//then setds wll becom emoty

	while(!setds.empty())
	{
		//the first vertex in set is the minDist vertex, 
		//extract it from the set

		pair<int,int> temp= *(setds.begin());
		setds.erase(setds.begin());


		//vertex label is stored in the secodn of pair
		//first is dist to keep set sorted
		int u=temp.second;

		vector<pair<int,int> > cur=vec[u];

		for(int i=0;i<cur.size();i++)
		{
			int v=cur[i].first;
			int w=cur[i].second;


			//if there is another path to v through u
			if(dist[v]>dist[u]+w)
			{
				if(dist[v]!=INF)
					setds.erase(setds.find(make_pair(dist[v],v)));
				
				//updating distance of v
				dist[v]=dist[u]+w;
				setds.insert(make_pair(dist[v],v));
			}
		}
	}

	cout<<"dist from source: "<<src<<endl;
	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
}



int main()
{
	int V;
	cin>>V;
	vector<vector<pair<int,int> > > vec(V);

	int e;
	cin>>e;
	int u,v,w;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		vec[u].push_back(make_pair(v,w));
		vec[v].push_back(make_pair(u,w));
	}


	shortestPath(vec,0);
	return 0;
}
