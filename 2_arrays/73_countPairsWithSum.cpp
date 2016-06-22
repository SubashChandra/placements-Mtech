#include<cstdio>
#include<iostream>
#include<map>

using namespace std;


void auxFunc(int arr[], int n, int sum)
{
	map<int,int> m1;
	map<int,int>::iterator it;

	int i;
	for(i=0;i<n;i++)
	{
		it=m1.find(arr[i]);
		if(it==m1.end())
			m1.insert(pair<int,int>(arr[i],1));
		else 
			it->second++;
	}

	int count=0;
	for(i=0;i<n;i++)
	{
		it=m1.find(sum-arr[i]);
		if(it!=m1.end())
		{
			if(sum-arr[i]==arr[i] && it->second>1)
				count+=(it->second-1);
			else
				count+=it->second;
		}
	}

	cout<<count/2<<endl;
}

int main()
{
	int n;
	cin>>n;

	int i, arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	int sum;
	cin>>sum;

	auxFunc(arr,n,sum);

	return 0;
}
