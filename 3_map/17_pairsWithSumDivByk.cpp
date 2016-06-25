#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n, int k)
{
	if(n%2!=0)
	{
		cout<<"no"<<endl;
		return;
	}

	map<int,int> m1;
	map<int,int>::iterator it;

	int i;
	for(i=0;i<n;i++)
	{
		m1[arr[i]%k]++;
	}

	for(i=0;i<n;i++)
	{
		int rem=arr[i]%k;

		if(2*rem==k)
		{
			if(m1[rem]%2!=0)
			{
				cout<<"no"<<endl;
				return;
			}
		}
		else if(rem==0)
		{
			if(m1[rem]%2!=0)
			{
				cout<<"no"<<endl;
				return;
			}
		}

		else if(m1[rem]!=m1[k-rem])
		{
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"yes"<<endl;
}



int main()
{
	int n;
	cin>>n;
	int i,arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;

	auxFunc(arr,n,k);
	return 0;
}
