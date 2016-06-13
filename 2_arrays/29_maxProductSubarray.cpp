#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(int arr[], int n)
{
	int i,j;
	int curProd, maxProd,negCount;

	curProd=1,maxProd=1,negCount=0;

	i=0;
	j=0;
	while(i<n && j<n)
	{
		if(arr[j]!=0)
		{
			if(arr[j]<0)
				negCount++;
			curProd*=arr[j];
			maxProd=max(maxProd,curProd);
			j++;
		}
		else
		{
			if(negCount==0 ||negCount %2==0)
			{
				j=j+1;
				i=j;
				negCount=0;
				curProd=1;
			}
			else
			{
				while(i<n && arr[i]>0)
				{
					curProd=curProd/arr[i];
					i++;
				}
				curProd=curProd/arr[i];
				maxProd=max(maxProd,curProd);

				j=j+1;
				i=j;
				negCount=0;
				curProd=1;
			}
		}
	}
	if(negCount%2!=0)
	{
		while(i<n && arr[i]>0)
		{
			curProd=curProd/arr[i];
			i++;
		}
		curProd=curProd/arr[i];
		maxProd=max(maxProd,curProd);

	}

	cout<<maxProd<<endl;
}





int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;

}
