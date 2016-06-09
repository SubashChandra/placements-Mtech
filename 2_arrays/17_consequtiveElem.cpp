#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>> arr[i];

	int min=arr[0];
	for(i=0;i<n;i++)
		if(arr[i]<min)
			min=arr[i];

	min=min-1;
	for(i=0;i<n;i++)
		arr[i]-=min;
	int sum=0;
	for(i=0;i<n;i++)
		sum+=arr[i];
	if(sum==(n*(n+1))/2)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	return 0;
}
