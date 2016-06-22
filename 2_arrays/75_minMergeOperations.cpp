#include<cstdio>
#include<iostream>

using namespace std;

//min merge operations to make an array palindrome
void auxFunc(int arr[], int n)
{
	int i,j;
	int count=0;
	i=0;
	j=n-1;

	while(i<j)
	{
		if(arr[i]==arr[j])
		{
			i++;
			j--;
		}
		else if(arr[i]<arr[j])
		{
			arr[i+1]+=arr[i];
			count++;
			i++;
		}
		else 
		{
			arr[j-1]+=arr[j];
			count++;
			j--;
		}
	}
	cout<<count<<endl;
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
