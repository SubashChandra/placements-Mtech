#include<cstdio>
#include<iostream>

using namespace std;

int kadane(int arr[], int n)
{
	int i;


	int curMax,maxSoFar;

	curMax=0;
	maxSoFar=INT_MIN;
	for(i=0;i<n;i++)
	{
		curMax=max(arr[i],curMax+arr[i]);
		maxSoFar=max(maxSoFar,curMax);

	}

	return maxSoFar;
}


void auxFunc(int arr[], int n)
{
	int max1=kadane(arr,n);
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i]*=-1;
	}

	int max2=kadane(arr,n);
	max2=sum+max2;

	cout<<max(max1,max2)<<endl;

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

