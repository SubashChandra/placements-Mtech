#include<iostream>
#include<cstdio>

using namespace std;

void auxFunc(int arr[], int n)
{
	int count=0;
	int i,j;
	int zeroCount;
	while(1)
	{
		zeroCount=0;
		for(i=0;i<n;i++)
			if(arr[i]==0)
				zeroCount++;

		if(zeroCount==n)
			break;

		for(i=0;i<n;i++)
		{
			if(arr[i]%2==1) //odd no found so , break;
				break;
		}

		j=i;
		while(j<n)
		{
			if(arr[j]%2==1)
			{
				arr[j]--;
				count++;
			}
			j++;
		}

		//if no odd found at all
		if(i==n)
		{
			for(i=0;i<n;i++)
				arr[i]/=2;
			count++;
		}
	}
	cout<<count<<endl;

}


	

int main()
{
	int n;
	cin>>n;

	int i, arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
