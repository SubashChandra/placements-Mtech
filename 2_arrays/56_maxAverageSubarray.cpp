#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n, int k)
{
	int i,j;
	int index;
	int maxSum,sum;
	sum=0;
	maxSum=0;
	i=0;
	while(i<k)
		sum+=arr[i++];
	index=0;
	maxSum=sum;
	j=0;
	while(i<n)
	{
		sum-=arr[j];
		j++;
		sum+=arr[i];
		i++;
		if(sum>maxSum)
		{
			maxSum=sum;
			index=j;
		}
	}
	cout<<index<<endl;
}
	

int main()
{
	int n;
	cin>>n;
	int i;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;
	auxFunc(arr,n,k);
	return 0;
}
