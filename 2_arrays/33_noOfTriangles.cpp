#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


void auxFunc(vector<int> arr, int n)
{
	sort(arr.begin(),arr.end());

	int i,j,k;
	int count=0;
	for(i=0;i<n-2;i++)
	{
		j=i+1;
		k=i+2;
		while(j<n)
		{
			while(k<n && arr[i]+arr[j]>arr[k])
				k++;

			count+=(k-j-1);
			j++;
		}

	}
	cout<<count<<endl;
}



int main()
{
	int n;
	cin>>n;

	int i;
	vector<int> arr(n);
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
