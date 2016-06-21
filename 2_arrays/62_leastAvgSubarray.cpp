#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n,int k)
{
	int i,j;
	int sum,minSum;
	sum=0;
	j=0;
	while(j<k)
		sum+=arr[j++];

	
	minSum=sum;
	i=0;
	int index=i;
	while(j<n)
	{
		sum-=arr[i];
		i++;
		sum+=arr[j];
		j++;
		if(sum<minSum)
		{
			minSum=sum;
			index=i;
		}
	}

	cout<<index<<" - "<<index+k-1<<endl;
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
