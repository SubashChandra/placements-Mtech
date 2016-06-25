#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

void auxFunc(int arr[], int n)
{
	map<int,vector<int> > m1;
	map<int,vector<int> >::iterator it;

	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			int sum=arr[i]+arr[j];
			it=m1.find(sum);
			if(it==m1.end())
			{
				vector<int> temp;
				temp.push_back(arr[i]);
				temp.push_back(arr[j]);
				m1[sum]=temp;
			}
			else
			{
				cout<<it->second[0]<<" + "<<it->second[1]<<" = "<<arr[i]<<" + "<<arr[j]<<endl;
				return;
			}
		}
	}
	cout<<"not found"<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i, arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
