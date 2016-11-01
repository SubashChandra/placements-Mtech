#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int w[], int v[], int n, int weight)
{
	int i,j;
	int k[n+1][weight+1];

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=weight;j++)
		{
			if(i==0 || j==0)
				k[i][j]=0;
			else if(w[i-1]<=weight)
				k[i][j]=max(v[i-1]+k[i-1][j-w[i-1]],k[i-1][j]);
			else
				k[i][j]=k[i-1][j];
		}
	}
	return k[n][weight];


}

int main()
{
	int n;
	cin>>n;
	int w[n];
	int v[n];
	int i;
	for(i=0;i<n;i++)
		cin>>v[i];
	for(i=0;i<n;i++)
		cin>>w[i];
	
	int weight;
	cin>>weight;
	cout<<auxFunc(w,v,n,weight)<<endl;
	return 0;
}
