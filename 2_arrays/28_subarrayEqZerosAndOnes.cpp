#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i, j;
	int zeros=0,ones=0;

	for(i=0;i<n;i++)
	{
		if(arr[i]==0)
			zeros++;
		else
			ones++;
	}

	i=0;
	j=n-1;
	while(i<j)
	{
		if(zeros==ones)
		{
			cout<<i<<" "<<j<<endl;
			return;
		}
		else if(zeros>ones)
		{
			if(arr[i]==0)
			{
				i++;
				zeros--;
			}
			else if(arr[j]==0)
			{
				j--;
				zeros--;
			}
			else
			{
				i++;
				ones--;
			}
		}
		else
		{
			if(arr[i]==1)
			{
				ones--;
				i++;
			}
			else if(arr[j]==1)
			{
				ones--;
				j--;
			}
			else
			{
				i++;
				zeros--;
			}
		}
	}
	cout<<"no such subarray"<<endl;	
}
		
			


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];


	auxFunc(arr,n);
	return 0;
}
