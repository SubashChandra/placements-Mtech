#include<cstdio>
#include<iostream>

using namespace std;


//using kadane's
void maxLeft(int arr[], int n, int sum[])
{
	int maxSoFar=arr[0];
	int curMax=arr[0];
	sum[0]=maxSoFar;

	for(int i=1;i<n;i++)
	{
		curMax=max(arr[i],curMax+arr[i]);
		maxSoFar=max(curMax,maxSoFar);
		sum[i]=maxSoFar;
	}

}

void maxRight(int arr[], int n, int sum[])
{
	int maxSoFar=arr[n];
	int curMax=arr[n];
	sum[n]=maxSoFar;

	for(int i=n-1;i>=0;i--)
	{
		curMax=max(curMax+arr[i],arr[i]);
		maxSoFar=max(curMax,maxSoFar);
		sum[i]=maxSoFar;
	}

}



void auxFunc(int arr[], int n)
{
	int leftMax[n];
	maxLeft(arr,n,leftMax);

	int rightMax[n];
	maxRight(arr,n-1,rightMax);

	int invertArr[n];
	int i;
	for(i=0;i<n;i++)
		invertArr[i]=-arr[i];

	int leftMin[n];
	maxLeft(invertArr,n,leftMin);

	int rightMin[n];
	maxRight(invertArr,n-1,rightMin);

	for(i=0;i<n;i++)
	{
		leftMin[i]*=-1;
		rightMin[i]*=-1;
	}

	int result=INT_MIN;

	for(i=0;i<n-1;i++)
	{
		int absVal=max(abs(leftMax[i]-rightMin[i+1]), abs(leftMin[i]-rightMax[i+1]));
		result=max(result,absVal);
	}

	cout<<result<<endl;
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
