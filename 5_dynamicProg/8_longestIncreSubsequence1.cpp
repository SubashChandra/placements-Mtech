//recursive solution


#include<cstdio>
#include<iostream>

using namespace std;

int lis(int arr[], int n, int &ans)
{

	if(n==1)
		return 1;
	int res,maxEndingHere=1;

	int i;
	for(i=1;i<n;i++)
	{
		res=lis(arr,i,ans);
		if(arr[i-1]<arr[n-1] && (res+1)>maxEndingHere)
			maxEndingHere=(1+res);

	}
	ans=max(ans,res);
	return maxEndingHere;
}

void auxFunc(int arr[], int n)
{
	int max=1;
	lis(arr,n,max);
	cout<<max<<endl;
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
