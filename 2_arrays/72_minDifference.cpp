#include<cstdio>
#include<iostream>

#include<vector>

using namespace std;

void auxFunc(int arr[] ,int n)
{
	sort(arr, arr+n);

	int n1,n2;
	int minDiff=INT_MAX;

	for(int i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i]<minDiff)
		{
			minDiff=arr[i+1]-arr[i];
			n1=arr[i];
			n2=arr[i+1];
		}
	}

	cout<<minDiff<<endl;
	cout<<n1<<" "<<n2<<endl;
}


int main()
{
	int n;
	cin>>n;

	int i, arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return n;

}
