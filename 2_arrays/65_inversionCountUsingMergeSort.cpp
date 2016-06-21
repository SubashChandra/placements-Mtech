#include <cstdio>
#include<vector>
#include<iostream>

using namespace std;

int merge(int arr[], int l, int mid, int r)
{

	int i,j;
	vector<int> vec;

	i=l;
	j=mid+1;
	int count=0;
	while(i<=mid && j<=r)
	{
		if(arr[i]<=arr[j])
		{
			vec.push_back(arr[i]);
			i++;
		}
		else
		{
			vec.push_back(arr[j]);
			j++;
			count+=(mid-i+1);
		}
	}
	while(i<=mid)
	{
		vec.push_back(arr[i]);
		i++;
	}
	while(j<=r)
	{
		vec.push_back(arr[j]);
		j++;
	}

	j=0;
	while(j<vec.size())
	{
		arr[j+l]=vec[j];
		j++;
	}
	return count;
}

int mergeSort(int arr[], int l, int r)
{
	if(l>=r)
		return 0;

	int mid=(l+r)/2;

	int count=0;
	count=mergeSort(arr, l,mid);
	count+=mergeSort(arr,mid+1,r);
	count+=merge(arr,l,mid,r);

	return count;
}


//O(nlog(n)) solution
void auxFunc(int arr[], int n)
{
	int count=mergeSort(arr, 0, n-1);
		
	cout<<count<<endl;
}



int main()
{
	int cases,j;
	cin>>cases;
	while(cases>0)
	{

		int n;
		cin>>n;
		int arr[n], i;

		for(i=0;i<n;i++)
			cin>>arr[i];

		auxFunc(arr,n);
		cases--;
	}
	return 0;
}
