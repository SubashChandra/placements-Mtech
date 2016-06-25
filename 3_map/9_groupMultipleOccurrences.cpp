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
	{
		it=m1.find(arr[i]);
		if(it==m1.end())
			m1.insert(pair<int,int>(arr[i],1));
		else
			it->second++;
	}

	int temp[n];
	int ind=0;
	for(i=0;i<n;i++)
	{
		it=m1.find(arr[i]);
		if(it!=m1.end())
		{
			int count=it->second;
			while(count>0)
			{
				temp[ind++]=arr[i];
				count--;
			}
			m1.erase(it);
		}
	}
	for(i=0;i<n;i++)
	{
		arr[i]=temp[i];
		cout<<arr[i]<<" ";
	}
	cout<<endl;
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
