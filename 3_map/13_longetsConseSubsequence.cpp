#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n)
{
	map<int,int> m1;
	map<int,int>::iterator it;

	int i;
	for(i=0;i<n;i++)
		m1[arr[i]]=1;


	int len=0;
	int maxLen=0;
	for(i=0;i<n;i++)
	{
		int cur=arr[i];

		while(m1.find(cur)!=m1.end())
		{
			cur=cur-1;
		}

		int begin=cur+1;
		len=0;
		while(m1.find(begin)!=m1.end())
		{
			len++;
			begin++;
		}
		maxLen=max(len,maxLen);
	}
	cout<<maxLen<<endl;
}

int main()
{
	int n;
	cin>>n;

	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
