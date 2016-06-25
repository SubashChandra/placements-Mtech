#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

void auxFunc(int arr[], int n, int sum)
{
	int i;
	map<int,int> m1;
	for(i=0;i<n;i++)
		m1[arr[i]]++;

	int count=0;
	for(i=0;i<n;i++)
	{
		if(m1.find(arr[i])!=m1.end())
		{
			if(arr[i]*2==sum)
			{
				count+=(m1[arr[i]]*(m1[arr[i]]-1))/2;
				m1.erase(arr[i]);
			}
			else if(arr[i]<=sum && m1.find(sum-arr[i])!=m1.end())
			{
				count+=m1[arr[i]]*m1[sum-arr[i]];
				m1.erase(arr[i]);
				m1.erase(sum-arr[i]);
			}
		}
	}
	cout<<count<<endl;
}

				

int main()
{
	int n;
	cin>>n;

	int i,arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];
	int sum;
	cin>>sum;
	auxFunc(arr,n,sum);
	return 0;
}
