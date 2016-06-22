//in constant space

#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr1[], int n1, int arr2[], int n2)
{
	int i,j,k;
	i=j=0;

	while(i<n1 && j<n2)
	{
		if(arr1[i]<=arr2[j])
			i++;

		else if(arr1[i]>arr2[j])
			swap(arr1[i++],arr2[j]);

		k=j;
		while(k<n2-1 && arr2[k]>arr2[k+1])
		{
			swap(arr2[k],arr2[k+1]);
			k++;
		}
	}

	for(i=0;i<n1;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;

	for(i=0;i<n2;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;
}


int main()
{
	int n1,n2;
	cin>>n1;
	int i, arr1[n1];
	for(i=0;i<n1;i++)
		cin>>arr1[i];

	cin>>n2;
	int arr2[n2];

	for(i=0;i<n2;i++)
		cin>>arr2[i];

	auxFunc(arr1,n1,arr2,n2);
	return 0;
}
