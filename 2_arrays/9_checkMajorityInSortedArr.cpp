#include <cstdio>
#include <iostream>

using namespace std;

int bs(int arr[], int l, int r, int data)
{
	if(l==r)
		return l;
	int mid=(l+r)/2;
	if(arr[mid]==data)
	{
		if(mid==l || (mid>0 && arr[mid-1]<data))
			return mid;

		else
		{
			return bs(arr,l,mid-1,data);
		}
	}
	else if(arr[mid]<data)
	{
		return bs(arr,mid+1,r,data);
	}
	else
		return bs(arr,l,mid-1,data);
}
		
		

int main()
{
	int n;
	cin>>n;
	int arr[n];

	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int maj;
	cin>>maj;

	int mid=n/2;

	if(arr[mid]!=maj)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		if(arr[mid-1]<maj && arr[mid+n/2]==maj)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			int firstIndex=bs(arr,0,mid,maj);
			if(arr[firstIndex+n/2]==maj)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}


