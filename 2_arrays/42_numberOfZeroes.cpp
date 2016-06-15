#include<cstdio>
#include<iostream>

using namespace std;


int binSear(int arr[], int low, int high)
{
	if(low>high)
		return -1;
	
	int mid=(low+high)/2;
	if(arr[mid]==1)
		return binSear(arr,mid+1,high);
	else if((mid==low) || (arr[mid]==0 && arr[mid-1]==1))
		return mid;
	else
		return binSear(arr,low,mid-1);

}




void auxFunc(int arr[], int n)
{
	int index=binSear(arr,0,n-1);
	if(index==-1)
		cout<<"0"<<endl;
	else
		cout<<n-index<<endl;
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
