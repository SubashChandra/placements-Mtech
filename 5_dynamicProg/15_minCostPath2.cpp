#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int auxFunc(vector<vector<int> > vec, int m, int n)
{
	int n1=vec.size();
	int n2=vec[0].size();

	int temp[n1][n2];
	temp[0][0]=vec[0][0];
	int i,j;

	for(i=1;i<n2;i++)
		temp[0][i]=temp[0][i-1]+vec[0][i];

	for(i=1;i<n2;i++)
		temp[i][0]=temp[i-1][0]+vec[i][0];

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			temp[i][j]=vec[i][j]+min(temp[i-1][j],min(temp[i][j-1],temp[i-1][j-1]));
		}
	}
	return temp[m][n];
}

int main()
{
	int n1,n2;
	cin>>n1>>n2;
	vector<vector<int> > vec(n1,vector<int>(n2));
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cin>>vec[i][j];
		}
	}
	int m,n;
	cin>>m>>n;
	cout<<auxFunc(vec,m,n)<<endl;
	return 0;
}
