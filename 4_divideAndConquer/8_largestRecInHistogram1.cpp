#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int l, int r)
{
	if(l>r)
		return INT_MIN;
	if(l==r)
		return arr[l];

	int minIndex=l;
	int i;
	for(i=l;i<=r;i++)
	{
		if(arr[i]<arr[minIndex])
			minIndex=i;
	}
	cout<<arr[minIndex]<<endl;
	int lVal=auxFunc(arr,l,minIndex-1);
	int rVal=auxFunc(arr,minIndex+1,r);
	int crossVal=(arr[minIndex]*(r-l+1));
	return max(lVal, max(rVal,crossVal));
}

int main()
{
	int n;
	cin>>n;
	int i,arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<auxFunc(arr,0,n-1)<<endl;
	return 0;
}
