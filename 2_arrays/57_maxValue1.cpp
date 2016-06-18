#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i;
	int sum,maxSum;
	int ind;

	int counter=n;
	maxSum=INT_MIN;
	ind=0;
	while(counter>0)
	{
		int j=ind;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=arr[i]*j;
			j=(j+1)%n;
		}

		if(sum>maxSum)
			maxSum=sum;
		ind++;
		counter--;
	}

	cout<<maxSum<<endl;
}



int main()
{
	int n;
	cin>>n;
	int arr[n],i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
