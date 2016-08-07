#include<cstdio>
#include<iostream>


using namespace std;

int auxFunc(int arr[], int l, int r)
{
	if(l>r)
		return -1;

	if(l==r)
		return arr[l];

	int mid=(l+r)/2;
	if(arr[mid]==arr[mid+1])
		mid=mid+1;

	if(mid==l)
		return arr[mid];

	else if(arr[mid]!=arr[mid-1])
		return arr[mid];
	
	else if((r-mid)%2!=0)
		return auxFunc(arr,mid+1,r);
	else 
		return auxFunc(arr,l,mid-2);
}


int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,0,n-1)<<endl;
	return 0;
}
