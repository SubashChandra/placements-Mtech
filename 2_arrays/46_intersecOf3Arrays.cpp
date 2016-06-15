#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3)
{
	int i,j,k;
	i=j=k=0;
	while(i<n1 && j<n2 && k<n3)
	{
		if(arr1[i]<arr2[j] || arr1[i]<arr3[k])
			i++;
		else if(arr2[j]<arr1[i] || arr2[j]<arr3[k])
			j++;
		else if(arr3[k]<arr1[i] || arr3[k]<arr2[j])
			k++;
		else
		{
			cout<<arr1[i]<<" ";
			i++;
			j++;
			k++;
		}
	}
	cout<<endl;
}
	

int main()
{
	int n1,n2,n3;
	cin>>n1;
	int i,arr1[n1];
	for(i=0;i<n1;i++)
		cin>>arr1[i];

	cin>>n2;
	int arr2[n2];
	for(i=0;i<n2;i++)
		cin>>arr2[i];

	cin>>n3;
	int arr3[n3];
	for(i=0;i<n3;i++)
		cin>>arr3[i];

	auxFunc(arr1,n1,arr2,n2,arr3,n3);
	return 0;
}


