#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int l, int r, int &Max, int &Min)
{
	if(l>r)
		return;
	if(l==r)
	{
		Max=Min=arr[l];
		return;
	}
	else if(l+1==r)
	{
		Max=max(arr[l],arr[r]);
		Min=min(arr[l],arr[r]);
		return;
	}
	int mid=(l+r)/2;
	int lmax,rmax,lmin,rmin;
	
	auxFunc(arr,l,mid-1,lmax,lmin);
	auxFunc(arr,mid,r,rmax,rmin);
	
	Max=max(lmax,rmax);
	Min=min(lmin,rmin);
	return;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int min;
	int max;
	
	auxFunc(arr,0,n-1,max,min);
	cout<<min<< " "<<max<<endl;
	return 0;
}
