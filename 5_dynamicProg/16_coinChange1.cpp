#include<cstdio>
#include<iostream>


using namespace std;

int auxFunc(int arr[], int n, int val)
{
	//one solution, include no coins
	if(val==0)
		return 1;

	if(val<0)
		return 0;
	//no sol exists
	if(n<=0 && val>=1)
		return 0;
	
	return auxFunc(arr,n-1,val)+auxFunc(arr,n,val-arr[n-1]);
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int val;
	cin>>val;

	cout<<auxFunc(arr,n,val)<<endl;
	return 0;
}

