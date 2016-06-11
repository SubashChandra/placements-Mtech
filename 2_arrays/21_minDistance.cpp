#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n, int x, int y)
{
	int minDiff, lastElem=-1;
	minDiff=n;

	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x || arr[i]==y)
		{
			if(lastElem==-1)
				lastElem=i;
			else
			{
				if(arr[i]==arr[lastElem])
					lastElem=i;
				else
				{
					minDiff=min(minDiff,i-lastElem);
					lastElem=i;
				}
			}
		}
	}
	cout<<minDiff<<endl;
}

int main()
{
	int n,x,y;
	cin>>n;

	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cin>>x>>y;


	auxFunc(arr,n,x,y);
	return 0;
}
