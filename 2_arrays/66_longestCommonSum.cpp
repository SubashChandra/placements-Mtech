#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr1[], int n1,int arr2[], int n2)
{
	int i,j;
	int maxLen=0;
	int n=min(n1,n2);
	for(i=0;i<n;i++)
	{
		int sum1=0,sum2=0;
		for(j=i;j<n;j++)
		{
			sum1+=arr1[j];
			sum2+=arr2[j];
			
			if(sum1==sum2 && j-i+1>maxLen)
				maxLen=j-i+1;
		}
	}

	cout<<maxLen<<endl;
}	


int main()
{
	int n1,n2;
	cin>>n1;
	int i,arr1[n1];

	for(i=0;i<n1;i++)
	{
		cin>>arr1[i];
	}

	cin>>n2;
	int arr2[n2];
	for(i=0;i<n2;i++)
		cin>>arr2[i];
	auxFunc(arr1,n1,arr2,n2);
	return 0;
}
