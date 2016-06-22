#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	int i,j;
	i=0;
	j=n-1;
	while(i<j)
	{
		while(i<j && arr[i]<0)
			i++;
		while(i<j && arr[j]>0)
			j--;
		if(i<j)
			swap(arr[i++],arr[j--]);
	}



	for(i=0;i<n;i++)
	{
		if(arr[i]>0)	
			break;
	}
	
	int posInd=i;
	int negInd=1;
	while(negInd<posInd && posInd<n && arr[negInd]<0)
	{
		swap(arr[negInd],arr[posInd]);
		negInd=negInd+2;
		posInd++;
	}

	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}


int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);

	return 0;
}
