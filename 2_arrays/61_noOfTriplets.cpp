#include<cstdio>
#include<iostream>
#include<vector>



using namespace std;

void auxFunc(int arr[], int n, int sum)
{
	sort(arr,arr+n);

	int i,j,k;

	int count=0;
	int curSum=0;
	for(i=0;i<n-2;i++)
	{
		j=i+1;
		k=n-1;
		while(j<k)
		{
			curSum=arr[i]+arr[j]+arr[k];
			if(curSum>=sum)
			{
				k--;
			}
			else
			{
				count+=(k-j);
				j++;
			}
		}
	}

	cout<<count<<endl;
}


int main()
{
	int n;
	cin>>n;
	int i,arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	int sum;
	cin>>sum;

	auxFunc(arr,n,sum);
	return 0;
}
