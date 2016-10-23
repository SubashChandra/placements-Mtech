#include<cstdio>
#include<iostream>


using namespace std;

int auxFunc(int arr[], int n, int val)
{
	int i,j,x,y;

	int table[val+1][n];
	for(i=0;i<n;i++)
		table[0][i]=1;

	for(i=1;i<val+1;i++)
	{
		for(j=0;j<n;j++)
		{
			x=(i-arr[j]>=0)?table[i-arr[j]][j]:0;
			y=(j>=1)?table[i][j-1]:0;
			table[i][j]=x+y;
		}
	}
	return table[val][n-1];

}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int val;
	cin>>val;

	cout<<auxFunc(arr,n,val)<<endl;
	return 0;
}

