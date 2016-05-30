#include <cstdio>
#include <iostream>

using namespace std;


int main()
{
	int n1,n2;
	cin>>n1>>n2;

	int arr1[n1],arr2[n2];

	int i,j;
	for(i=0;i<n1;i++)
		cin>>arr1[i];

	for(i=0;i<n2;i++)
		cin>>arr2[i];

	i=0,j=0;

	while(i<n1 && j<n2)
	{
		if(arr1[i]<arr2[j])
		{
			cout<<arr1[i]<<" ";
			i++;
		}
		else if(arr1[i]>arr2[j])
		{
			cout<<arr2[j]<<" ";
			j++;
		}
		else
		{
			cout<<arr1[i]<<" ";
			i++;
			j++;
		}
	}
	while(i<n1)
		cout<<arr1[i++]<<" ";
	while(j<n2)
		cout<<arr2[j++]<<" ";
	cout<<endl;
	return 0;
}

