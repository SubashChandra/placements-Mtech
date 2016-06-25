#include<cstdio>
#include<iostream>
#include<map>

using namespace std;


void auxFunc(int arr[], int n)
{
	int sum=0;
	map<int,int> m1;
	map<int,int>::iterator it;

	int maxLen=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];

		if(arr[i]==0 && maxLen==0)
			maxLen=1;
		if(sum==0)
			maxLen=i+1;

		if(m1.find(sum)!=m1.end())
			maxLen=max(maxLen,i-m1[sum]);
		else
			m1[sum]=i;
	}
	cout<<maxLen<<endl;
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
