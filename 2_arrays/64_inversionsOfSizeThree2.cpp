#include <cstdio>
#include<iostream>

using namespace std;

//O(n2) solution
void auxFunc(int arr[], int n)
{
	int i,j;
	
	int count=0;

	int lcount;
	int rcount;
	for(i=1;i<n-1;i++)
	{
		lcount=0;
		j=i-1;
		while(j>=0 && arr[j]>arr[i])
		{
			lcount++;
			j--;
		}

		rcount=0;
		
		j=i+1;
		while(j<n && arr[j]<arr[i])
		{
			rcount++;
			j++;
		}

		count+=(lcount*rcount);
	}
			

	
	cout<<count<<endl;
}



int main()
{
	int n;
	cin>>n;
	int arr[n], i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
