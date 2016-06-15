#include<cstdio>
#include<iostream>

using namespace std;
 

void auxFunc(int arr[], int n)
{
	int zeroCount, oneCount, maxLength,zeroIndex;
	zeroCount=oneCount=maxLength=0;
	zeroIndex=-1;
	int targetIndex=-1;
	int i,j;
	i=j=0;
	while(j<n && i<n)
	{
		if(arr[j]==0)
		{
			zeroIndex=j;
			zeroCount++;
			j++;
			if(zeroCount>1)
			{
				while(i<j && arr[i]!=0)
				{
					oneCount--;
					i++;
				}
				zeroCount--;
				i++;
			}
			
		}


		else
		{
			oneCount++;
			if(oneCount+1>maxLength)
			{
				maxLength=oneCount+1;
				targetIndex=zeroIndex;
			}
			j++;
		}
		
	}
	if(arr[n-1]==0 && oneCount+1==maxLength)
		targetIndex=zeroIndex;
	if(maxLength>n)
		maxLength=n;
	cout<<maxLength<<endl;
	cout<<"Index:"<<targetIndex<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i,arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);


	return 0;
}
