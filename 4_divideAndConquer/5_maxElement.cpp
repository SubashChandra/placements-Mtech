//max element in an array wchih is first increasinh and them decreasig

#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int l, int r)
{

	if(l<=r)
	{
		if(l==r)
			return l;
		else if(l+1==r)
		{
			if(arr[l]>arr[r])
				return l;
			else
				return r;
		}
	
		int mid=(l+r)/2;
		if(mid>l && arr[mid]>arr[mid-1] && mid<r && arr[mid]>arr[mid+1])
			return mid;

		else if(arr[mid]<arr[mid+1])
			return auxFunc(arr,mid+1,r);
		else
			return auxFunc(arr,l,mid-1);
	}
	return -1;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{
		int n;
		cin>>n;
		int arr[n],i;

		for(i=0;i<n;i++)
			cin>>arr[i];

		int ind=auxFunc(arr,0, n-1);
		cout<<arr[ind]<<endl;
		cases--;
	}
	return 0;
}
