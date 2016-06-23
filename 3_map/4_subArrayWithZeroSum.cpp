#include<cstdio>
#include<iostream>
#include<map>


using namespace std;

void auxFunc(int arr[], int n)
{
	map<int,int> m1;
	map<int,int>::iterator it;
	
	int i,sum=0;

	for(i=0;i<n;i++)
	{
		sum+=arr[i];

		if(sum==0 || arr[i]==0 || m1.find(sum)!=m1.end())
		{
			cout<<"yes"<<endl;
			return;
		}
		m1.insert(pair<int,int>(sum,1));

	}

	cout<<"no"<<endl;
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
