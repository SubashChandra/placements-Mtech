#include<cstdio>
#include<iostream>


using namespace std;

void auxFunc(int arr[], int n, int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		arr[arr[i]%k]+=k;
	}

	int index=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]>arr[index])
			index=i;
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<index<<"->"<<arr[index]/k<<endl;
}


int main()
{
	int n;
	cin>>n;
	int arr[n],i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;

	auxFunc(arr,n,k);
	return 0;
}
