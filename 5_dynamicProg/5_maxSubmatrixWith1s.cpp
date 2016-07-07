#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

void auxFunc(vector<vector<int> > vec)
{
	int n=vec.size();
	int m=vec[0].size();
	int i,j;
	int temp[n][m];

	for(i=0;i<m;i++)
		temp[0][i]=vec[0][i];

	for(i=0;i<n;i++)
		temp[i][0]=vec[i][0];

	int ans=0;
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(vec[i][j]==1)
			{
				temp[i][j]=min(temp[i-1][j],min(temp[i][j-1],temp[i-1][j-1]))+1;
				ans=max(ans,temp[i][j]);
			}
			else
				temp[i][j]=0;
		}
	}

	cout<<ans<<endl;
}
int main()
{
	int n,m;
	cin>>n>>m;

	int i,j;
	vector<vector<int> > vec(n,vector<int>(m));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>vec[i][j];
		}
	}

	auxFunc(vec);
	return 0;
}

