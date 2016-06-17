#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i,j;
	int temp[100]={0};
	for(i=0;i<n;i++)
	{
		if(arr[i]>=0 && arr[i]<=99)
			temp[arr[i]]++;
	}


	i=-1;
	j=0;
	while(j<100)
	{
		if(temp[j]==0)
		{
			if(i==-1)
				i=j;
			j++;
		}
		else
		{
			if(i!=-1)
			{
				if(j-i>1)
					cout<<i<<"-"<<j-1<<endl;
				else
					cout<<i<<endl;
				i=-1;
			}
			j++;
		}
	}
	if(i!=-1)
	{
		if(j-i>1)
			cout<<i<<"-"<<j-1<<endl;
		else
			cout<<i<<endl;
		i=-1;
	}

	return;
}

int main()
{
	int n;
	cin>>n;
	int i, arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr, n);

	return 0;
}
