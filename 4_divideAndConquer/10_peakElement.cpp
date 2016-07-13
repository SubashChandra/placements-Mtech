#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int l, int r)
{
	if(l==r)
		return l;;
	int mid=(l+r)/2;

	if(mid==l && arr[mid]>arr[mid+1])
		return mid;
	else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
		return mid;
	else if(arr[mid]<arr[mid+1])
		return auxFunc(arr,mid+1,r);
	else
		return auxFunc(arr,l,mid-1);
}

int main()
{
	int n;
	cin>>n;
	int i,arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,0,n-1)<<endl;
	return 0;
}
