#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int temp[n];
	int i;
	for(i=0;i<n;i++)
	{
		temp[arr[i]]=i;
	}
	for(i=0;i<n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;
}

int main()
{
	int i,n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
