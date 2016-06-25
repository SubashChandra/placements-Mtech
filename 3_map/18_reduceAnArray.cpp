#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i;
	int temp[n];
	for(i=0;i<n;i++)
		temp[i]=arr[i];

	sort(temp,temp+n);
	map<int,int> m1;

	for(i=0;i<n;i++)
		m1[temp[i]]=i;

	for(i=0;i<n;i++)
	{
		arr[i]=m1[arr[i]];
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i,arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
