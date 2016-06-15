#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n, int val)
{
	int sum,minLen=n+1;
	int i=0,j=0;
	sum=0;
	while(j<n)
	{
		while(j<n && sum<=val)
		{
			sum+=arr[j];
			j++;
		}
		while(sum>val && i<n)
		{
			minLen=min(minLen,j-i);
			sum-=arr[i];
			i++;
		}
	}
	cout<<minLen<<endl;
}



int main()
{
	int n;
	cin>>n;
	int arr[n], i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int val;
	cin>>val;
	auxFunc(arr,n,val);

	return 0;
}
