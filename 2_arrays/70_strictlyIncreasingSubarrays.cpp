#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int count=1;
	int ans=0;
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
			count++;
		else
		{
			if(count>1)
			{
				ans+=(count*(count-1))/2;
				count=1;
			}
		}
	}
	if(count>1)
		ans+=(count*(count-1))/2;

	cout<<ans<<endl;
}

int main()
{
	int cases,j;
	cin>>cases;
	for(j=0;j<cases;j++)
	{
	int n;
	cin>>n;
	int i, arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	}
	return 0;
}
