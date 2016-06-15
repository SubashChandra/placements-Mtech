//rearrage an array so that arr[i]=arr[arr[i]]

#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		arr[i]+=((arr[arr[i]])%n)*n;

	}
	for(i=0;i<n;i++)
		arr[i]/=n;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

}




int main()
{
	int n;
	cin>>n;

	int arr[n],i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	auxFunc(arr,n);
	return 0;
}
