//recursive solution


#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


void auxFunc(int arr[], int n)
{
	int ans,i,j;
	ans=1;
	vector<int> lis(n,1);

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		cout<<lis[i]<<" ";
		ans=max(ans,lis[i]);
	}
	cout<<endl;
	cout<<ans<<endl;
}

int main()
{
	int n;
	cin>>n;
	int arr[n],i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
