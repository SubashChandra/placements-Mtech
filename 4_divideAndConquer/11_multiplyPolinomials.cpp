#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr1[], int n1, int arr2[], int n2)
{
	map<int,int> m1;
	map<int,int>::iterator it;

	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			int prod=arr1[i]*arr2[j];
			m1[i+j]+=prod;
		}
	}
	
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout<<it->second<<" ";
	}
	cout<<endl;
}
	

int main()
{
	int n1;
	cin>>n1;
	int arr1[n1];
	int i;
	for(i=0;i<n1;i++)
		cin>>arr1[i];

	int n2;
	cin>>n2;
	int arr2[n2];
	for(i=0;i<n2;i++)
		cin>>arr2[i];

	auxFunc(arr1,n1,arr2,n2);
	return 0;
}
