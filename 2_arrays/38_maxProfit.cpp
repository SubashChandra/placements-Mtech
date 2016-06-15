#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int j,profit,maxIndex;

	maxIndex=n-1;
	j=n-2;
	profit=0;
	while(j>=0)
	{
		if(arr[j]>arr[j+1])
		{
			if(maxIndex-(j+1)>1)
				profit+=(arr[maxIndex]-arr[j+1]);
			maxIndex=j;
			j--;
		}
		else
			j--;
	}
	if(maxIndex!=0)
		profit+=arr[maxIndex]-arr[0];

	cout<<profit<<endl;
}


int main()
{
	int n;
	cin>>n;
	int arr[n], i;

	for(i=0;i<n;i++)
		cin>>arr[i];


	auxFunc(arr,n);
	return 0;
}
