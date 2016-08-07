#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int auxFunc(vector<vector<int> > vec, int m, int n)
{
	if(m<0 || n<0)
		return INT_MAX;
	else if(m==0 && n==0)
		return vec[m][n];
	return vec[m][n]+min(auxFunc(vec,m-1,n),min(auxFunc(vec,m,n-1), auxFunc(vec,m-1,n-1)));
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
