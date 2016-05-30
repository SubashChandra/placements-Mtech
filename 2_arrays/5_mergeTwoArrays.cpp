#include<cstdio>
#include<iostream>

using namespace std;


int main()
{
	int m;
	int n;
	cin>>m>>n;

	int arr1[m+n];
	int arr2[n];

	int i,j;
	for(i=0;i<m+n;i++)
		cin>>arr1[i];
	for(i=0;i<n;i++)
		cin>>arr2[i];

	i=m+n-1;
	j=m+n-1;
	while(i>=0)
	{
		if(arr1[i]!=-1)
		{
			swap(arr1[i],arr1[j]);
			j--;
		}
		i--;
	}

	//now sorted merge both arr1 and arr2
	i=n;
	j=0;
	int k=0;
	while(i<m+n && j<n)
	{
		if(arr1[i]<arr2[j])
		{
			arr1[k]=arr1[i];
			i++;
			k++;
		}
		else
		{
			arr1[k]=arr2[j];
			j++;
			k++;
		}
	}

	while(i<m+n)
	{
		arr1[k]=arr1[i];
		i++;
		k++;
	}

	while(j<n)
	{
		arr1[k]=arr2[j];
		j++;
		k++;
	}

	for(i=0;i<m+n;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	return 0;
}

