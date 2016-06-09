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

	int lSum[n];
	int rSum[n];

	lSum[0]=0;
	for(i=1;i<n;i++)
		lSum[i]=lSum[i-1]+arr[i-1];

	rSum[n-1]=0;
	for(i=n-2;i>=0;i--)
		rSum[i]=rSum[i+1]+arr[i+1];

	for(i=0;i<n;i++)
	{
		if(lSum[i]==rSum[i])
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
