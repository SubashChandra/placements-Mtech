#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int small[n];
	int large[n];
	int i;

	small[0]=-1;
	int min=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[min])
		{
			small[i]=min;
		}
		else
		{
			small[i]=-1;
			min=i;	
		
		}
	}

	large[n-1]=-1;
	int max=n-1;

	for(i=n-2;i>=0;i--)
	{
		if(arr[i]<arr[max])
		{
			large[i]=max;
		}
		else
		{
			max=i;
			large[i]=-1;
		}
	}


	for(i=0;i<n;i++)
	{
		if(small[i]!=-1 && large[i]!=-1)
		{
			cout<<arr[small[i]]<< " "<<arr[i]<<" "<<arr[large[i]]<<endl;
			return;
		}
	}
	cout<<"not found"<<endl;
}
int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
