#include<cstdio>
#include<iostream>
using namespace std;

int auxFunc(int arr[], int l, int r)
{
	if(l>r)
		return 0;
	else if(l==r)
		return arr[l];

	int mid=(l+r)/2;
	int lArea=auxFunc(arr,l,mid);
	int rArea=auxFunc(arr,mid+1,r);

	int low=min(arr[mid],arr[mid+1]);
	int midArea=2*low;


	int lBound=mid;
	int rBound=mid+1;
	while(lBound>l || rBound<r)
	{
		int k;
		if(lBound==l)
			k=++rBound;
		else if(rBound==r)
			k=--lBound;
		else
		{
			if(arr[lBound-1]>=arr[rBound+1])
				k=--lBound;
			else
				k=++rBound;
		}
		low=min(low,arr[k]);
		midArea=max(midArea,low*(rBound-lBound+1));
	}
	return max(lArea, max(rArea,midArea));
	

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
