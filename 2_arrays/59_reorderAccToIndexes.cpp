#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int ind[], int n)
{
	int max=arr[0];
	int i;
	for(i=1;i<n;i++)
		if(arr[i]>max)
			max=arr[i];

	max++;
	cout<<max<<endl;
	for(i=0;i<n;i++)
	{
	//	cout<<i<<" "<<arr[ind[i]]<<" "<<max*(arr[i]%max)<<endl;
		arr[ind[i]]=arr[ind[i]]+ max*(arr[i]%max);
	}

	for(i=0;i<n;i++)
		cout<<arr[i]/max<<" ";
	cout<<endl;
}


int main()
{
	int n;
	cin>>n;
	int arr[n], i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	int ind[n];
	for(i=0;i<n;i++)
		cin>>ind[i];

	auxFunc(arr,ind,n);
	return 0;
}
