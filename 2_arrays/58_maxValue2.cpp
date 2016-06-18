#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i;

	int maxSum;
	int curSum=0;
	int index;
	int arrSum=0;
	for(i=0;i<n;i++)
	{
		curSum+=(i*arr[i]);
		arrSum+=arr[i];
	}
	maxSum=curSum;
	index=0;
	while(index<n)
	{
		curSum=curSum-arrSum+(n*arr[index]);
		if(curSum>maxSum)
			maxSum=curSum;
		index++;
	}
	cout<<maxSum<<endl;

}



int main()
{
	int n;
	cin>>n;
	int arr[n],i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
