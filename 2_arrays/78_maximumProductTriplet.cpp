#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int max1,max2,max3;
	max1=max2=max3=INT_MIN;
	int min1,min2;
	min1=min2=INT_MAX;
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]>max1)
		{
			max3=max2;
			max2=max1;
			max1=arr[i];
		}
		else if(arr[i]>max2)
		{
			max3=max2;
			max2=arr[i];
		}
		else if(arr[i]>max3)
		{
			max3=arr[i];
		}

		if(arr[i]<min1)
		{
			min2=min1;
			min1=arr[i];
		}
		else if(arr[i]<min2)
		{
			min2=arr[i];
		}
	}

	int prod= max(max1*max2*max3, max1*min1*min2);
	cout<<prod<<endl;
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
