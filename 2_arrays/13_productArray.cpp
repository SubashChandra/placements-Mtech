#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[n];
	int i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	int left[n]; //preduct if elements to the left of arr[i]
	int right[n]; 

	left[0]=1;
	for(i=1;i<n;i++)
		left[i]=left[i-1]*arr[i-1];

	right[n-1]=1;
	for(i=n-2;i>=0;i--)
		right[i]=right[i+1]*arr[i+1];

	for(i=0;i<n;i++)
		cout<<left[i]*right[i]<<" ";
	cout<<endl;

	return 0;
}
