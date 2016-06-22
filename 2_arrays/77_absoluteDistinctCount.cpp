#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i,j;
	i=0;
	j=n-1;

	int count=0;

	while(i<=j)
	{
		if(abs(arr[i])==abs(arr[j]))
		{
			count++;
			i++;
			j--;
		}
		else if(abs(arr[i])<abs(arr[j]))
		{
			count++;
			j--;
		}
		else
		{
			count++;
			i++;
		}

		while(i<n && arr[i]==arr[i-1])
			i++;
		while(j>=0 && arr[j]==arr[j+1])
			j--;
	}
	cout<<count<<endl;
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
