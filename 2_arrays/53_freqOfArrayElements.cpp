#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		arr[(arr[i]-1)%n]+=n;
	}

	for(i=0;i<n;i++)
	{
		cout<<i+1<<" -> "<< ((arr[i])-1)/n<<endl;
	}

}

int main()
{
	int n;
	cin>>n;
	int arr[n], i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
