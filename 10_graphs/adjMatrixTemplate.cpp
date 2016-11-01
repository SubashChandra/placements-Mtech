#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

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
	return 0;
}


