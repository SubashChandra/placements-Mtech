#include <cstdio>
#include <iostream>

using namespace std;


int auxFunc(int arr[], int l, int r)
{
	if(l>r) 
		return r+1;
	if(l != arr[l])
		return l;

	int mid=(l+r)/2;
	if(arr[mid]>mid)
		return auxFunc(arr,l,mid);
	else
		return auxFunc(arr,mid+1,r);
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int ind=auxFunc(arr,0,n-1);
	cout<<ind<<endl;
	return 0;
}
