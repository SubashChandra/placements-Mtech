#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


//using two colors 0 and 1
bool isBipartite(vector<vector<int> > &vec)
{
	int src=0;
	int v=vec.size();
	vector<int> color(v,-1);


	//assig color 1 to src
	color[src]=1;	
	queue<int> q1;
	q1.push(src);
	while(q1.size()!=0)
	{
		int i=q1.front();
		q1.pop();

		for(int j=0;j<v;j++)
		{
			if(vec[i][j]==1 && color[j]==-1)
			{
				color[j]=1-color[i];
				q1.push(j);
			}
			//if two adjacent has same color
			else if(vec[i][j]==1 && color[i]==color[j])
			{
				return false;
			}
		}
	}
	return true;
}
	


int main()
{
	int v;
	cin>>v;
	int e;
	cin>>e;

	vector<vector<int> > vec(v,vector<int>(v,0));

	int i,j,x,y;
	for(i=0;i<e;i++)
	{
		cin>>x>>y;
		vec[x][y]=1;
		vec[y][x]=1;
	}


	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	if(isBipartite(vec))
		cout<<"bipartite"<<endl;
	else
		cout<<"not bipartite"<<endl;
	return 0;
}


