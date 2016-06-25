#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n, int prod)
{
	int i;
	map<int,int> m1;

	for(i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			if(prod==0)
			{

				cout<<"yes"<<endl;
				return;
			}
		}
		else
		{
			if(prod%arr[i]==0)
			{
				if(m1.find(prod/arr[i])==m1.end())
					m1[arr[i]]=1;
				else
				{
					cout<<"yes"<<endl;
					return;
				}
			}
		}
	}
	cout<<"no"<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i, arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	int prod;
	cin>>prod;
	auxFunc(arr,n,prod);

	return 0;
}
