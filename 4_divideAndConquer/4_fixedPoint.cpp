#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int l, int r)
{
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(arr[mid]==mid)
		return arr[mid];
	else if(arr[mid]>mid)
		return auxFunc(arr,l,mid-1);
	else
		return auxFunc(arr,mid+1,r);
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,0,n-1)<<endl;
	return 0;
}
