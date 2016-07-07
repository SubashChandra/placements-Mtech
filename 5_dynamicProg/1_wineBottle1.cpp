//bcktracking


#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int be, int en,int year)
{
	if(be>en)
		return 0;
	return max(auxFunc(arr,be+1,en,year+1)+year*arr[be],auxFunc(arr,be,en-1,year+1)+year*arr[en]);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,0,n-1,1)<<endl;
	return 0;
}
