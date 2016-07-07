#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i;
	int maxSoFar,curMax;
	maxSoFar=curMax=arr[0];

	for(i=1;i<n;i++)
	{
		curMax=max(curMax+arr[i],arr[i]);
		maxSoFar=max(curMax,maxSoFar);
	}

	cout<<maxSoFar<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i,arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
