//find max j-i such that arr[j]>arr[i]

#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i,j;
	//lmin[i] stores minvalue from arr[0] to arr[i]

	int lmin[n],rmax[n];
	int maxDiff;
	
	lmin[0]=arr[0];
	for(i=1;i<n;i++)
		lmin[i]=min(lmin[i-1],arr[i]);

	//rmax[i] stores max vablue from arr[n-1] to arr[i]
	rmax[n-1]=arr[n-1];
	for(i=n-2;i>=0;i--)
		rmax[i]=max(rmax[i+1],arr[i]);

	i=0;j=0;
	maxDiff=-1;
	while(i<n && j<n)
	{
		if(lmin[i]<rmax[j])
		{
			maxDiff=max(j-i,maxDiff);
			j++;
		}
		else
			i=i+1;
	}

	cout<<maxDiff<<endl;
}



int main()
{
	int n;
	cin>>n;

	int arr[n];
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	auxFunc(arr,n);
	return 0;
}
