#include <cstdio>
#include<iostream>

using namespace std;

//O(n3) solution
void auxFunc(int arr[], int n)
{
	int i,j,k;
	
	int count=0;

	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(arr[i]>arr[j] && arr[j]>arr[k])
				{
					cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
					count++;
				}
			}
		}
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
