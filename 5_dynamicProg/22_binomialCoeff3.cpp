#include<iostream>
#include<cstdio>

using namespace std;

int auxFunc(int n, int k)
{
	int c[k+1];
	memset(c,0,sizeof(c));

	c[0]=1;

	for(int i=1;i<=n;i++)
	{
		//compute next row of pascal's triangle 
		//using the previous row
		for(int j=min(i,k);j>0;j--)
		{
			c[j]=c[j]+c[j-1];
		}
	}
	return c[k];

}

int main()
{
	int n,k;
	cin>>n>>k;
	cout<<auxFunc(n,k)<<endl;
	return 0;
}

