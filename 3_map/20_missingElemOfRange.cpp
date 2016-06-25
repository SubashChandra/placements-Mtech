#include<cstdio>
#include<iostream>
#include<map>

using namespace std;


void auxFunc(int arr[], int n, int low, int high)
{
	int i;
	map<int,int> m1;
	map<int,int>::iterator it;

	for(i=0;i<n;i++)
		m1[arr[i]]++;

	for(i=low;i<=high;i++)
	{
		if(m1.find(i)==m1.end())
			cout<<i<<" ";
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

	int low,high;
	cin>>low>>high;

	auxFunc(arr,n,low,high);
	return 0;
}
