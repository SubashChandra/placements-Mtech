#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[][2], int n)
{
	int i;
	map<int,int> m1;
	map<int,int>::iterator it;

	for(i=0;i<n;i++)
	{
		it=m1.find(arr[i][1]);
		if(it==m1.end())
			m1[arr[i][0]]=arr[i][1];
		else
		{
			if(it->second==arr[i][0])
			{
				cout<<"("<<it->first<<","<<it->second<<")"<<endl;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n][2];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i][0]>>arr[i][1];

	auxFunc(arr,n);
	return 0;
}
