#include<cstdio>
#include<iostream>

using namespace std;

//assume diff is always positive
int auxFunc(int arr[], int l, int r, int diff) 
{
	if(l>r)
		return -1;
	int mid=(l+r)/2;

	if(arr[mid]+diff!=arr[mid+1])
		return arr[mid]+diff;
	else if(mid>l && arr[mid]-diff!=arr[mid-1])
		return arr[mid]-diff;

	else if(arr[r]!=arr[mid]+(r-mid)*diff)
		return auxFunc(arr,mid+1,r,diff);
	else
		return auxFunc(arr,l,mid-1,diff);
}

	
	



void missing(int arr[], int n)
{
	if(n==1)
		cout<<arr[0]+1<<endl;
	if(n==2)
		cout<< arr[1]+(arr[1]-arr[0])<<endl;
	
	int diff;

	diff=(arr[n-1]-arr[0])/n;

	cout<<auxFunc(arr,0,n-1,diff)<<endl;
}

int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	missing(arr,n);
	return 0;
}
