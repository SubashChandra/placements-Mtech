#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n, int sum)
{
	if(sum==0)
	{
		cout<<"not found"<<endl;
		return;
	}
	int i,j;
	i=0,j=0;
	int curSum=0;
	while(i<n && j<n)
	{
		if(curSum<sum)
		{
			curSum+=arr[j];
			j++;
		}
		else if(curSum>sum)
		{
			curSum-=arr[i];
			i++;

		}
		if(curSum==sum)
		{
			cout<<i<<" "<<j-1<<endl;
			return;
		}

	}
	cout<<"not found"<<endl;
}




int main()
{
	int n;
	cin>>n;

	int arr[n];

	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int sum;
	cin>>sum;
	auxFunc(arr,n,sum);
	return 0;
}
