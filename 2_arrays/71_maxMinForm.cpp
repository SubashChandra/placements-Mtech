#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		int temp=arr[i];

		while(temp>0)
		{
			j=(i<n/2)? 2*i+1 : 2*(n-i-1);

			if(i==j)
			{
				arr[i]=-temp;
				break;
			}

			swap(temp,arr[j]);

			arr[j]=-arr[j];

			i=j;
		}
	}

	for(i=0;i<n;i++)
	{
		if(arr[i]<0)
			arr[i]*=-1;
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
	

int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{
		int n;
		cin>>n;

		int i, arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		auxFunc(arr,n);
		cases--;
	}
	return 0;

}
