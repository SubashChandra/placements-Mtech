#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i;
	int flag=0;
	for(i=0;i<n-1;i++)
	{
		if(flag==0)
		{
			if(arr[i]>arr[i+1])
				swap(arr[i],arr[i+1]);
			flag=1;
		}
		else
		{
			if(arr[i]<arr[i+1])
				swap(arr[i],arr[i+1]);
			flag=0;
		}
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;


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
