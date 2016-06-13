#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i;
	int next=arr[n-1];
	arr[n-1]=-1;
	for(i=n-2;i>=0;i--)
	{
		int temp=arr[i];
		arr[i]=max(arr[i+1],next);
		next=temp;
	}

	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}


int main()
{
	int n;
	cin>>n;

	int i,arr[n];

	for(i=0;i<n;i++)
		cin>> arr[i];

	auxFunc(arr,n);
	return 0;
}
