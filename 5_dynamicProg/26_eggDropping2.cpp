#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int n, int k)
{
	//2d table with dimensions i eggs and j floors
	int eggsFloor[n+1][k+1];
	int res;
	int i, j, x;

	// we need 1 trail for one floor and 0 trails for 0 floors
	for(i=1;i<=n;i++)
	{
		eggsFloor[i][0]=0;
		eggsFloor[i][1]=1;
	}

	//we always need j trails for 1 eggs and j floors
	for(j=1;j<=k;j++)
		eggsFloor[1][j]=j;
	
	//fill the rest
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			eggsFloor[i][j]=INT_MAX;
			for(x=1;x<=j;x++)
			{
				res=1+max(eggsFloor[i-1][x-1],eggsFloor[i][j-x]);
				eggsFloor[i][j]=min(res,eggsFloor[i][j]);
			}
		}
	}
	return eggsFloor[n][k];
}




int main()
{
	int n,k; //n eegs  and k floors
	cin>>n>>k;
	cout<<auxFunc(n,k)<<endl;
	return 0;
}
