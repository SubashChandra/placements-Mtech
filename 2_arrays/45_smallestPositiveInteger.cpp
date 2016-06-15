#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int result=1;
	int i;
	for(i=0;i<n && arr[i]<=result;i++)
		result+=arr[i];

	cout<< result<<endl;
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
