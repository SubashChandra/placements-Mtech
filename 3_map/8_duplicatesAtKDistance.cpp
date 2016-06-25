#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n, int k)
{
	int i;
	map<int,int> m1;
	map<int,int>::iterator it;

	int flag=0;
	for(i=0;i<n;i++)
	{
		it=m1.find(arr[i]);
		if(it==m1.end())
		{
			m1.insert(pair<int,int>(arr[i],i));
		}
		else
		{
			flag=1;
			if(i-it->second>k)
			{
				cout<<"no"<<endl;
				return;
			}

		}
	}
	if(flag==0)
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;
}


int main()
{
	int n;
	cin>>n;

	int arr[n], i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;
	auxFunc(arr,n,k);
	return 0;
}
