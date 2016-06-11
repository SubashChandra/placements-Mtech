#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i,j;
	int count[n];
	
	for(i=0;i<n;i++)
	{
		count[i]=0;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
				count[i]++;
		}
	}
	for(i=0;i<n;i++)
		cout<<count[i]<<" ";
	cout<<endl;
}


int main()
{
	int n;
	cin>>n;
	int arr[n];

	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
