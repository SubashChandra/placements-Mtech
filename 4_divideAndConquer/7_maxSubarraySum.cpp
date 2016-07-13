#include<cstdio>
#include<iostream>

using namespace std;

int crossOver(int arr[], int l, int mid, int r)
{
	int lSum=INT_MIN;
	int i;
	int sum=0;
	for(i=mid;i>=l;i--)
	{
		sum+=arr[i];
		if(sum>lSum)
			lSum=sum;
	}

	sum=0;
	int rSum=INT_MIN;
	for(i=mid+1;i<=r;i++)
	{
		sum+=arr[i];
		if(sum>rSum)
			rSum=sum;
	}
	return lSum+rSum;
}

int auxFunc(int arr[], int l, int r)
{
	if(l==r)
		return arr[l];
	int mid=(l+r)/2;
	return max(auxFunc(arr,l,mid),max(auxFunc(arr,mid+1,r),crossOver(arr,l,mid,r)));
}


int main()
{
	int n;
	cin>>n;
	int arr[n], i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,0,n-1)<<endl;
	return 0;
}
