#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int j;
	i=0;
	j=n-1;
	while(i<j)
	{
		while(arr[i]==0 && i<j)
			i++;
		while(arr[j]==1 && i<j)
			j--;

		if(i>j)
			break;
		swap(arr[i++],arr[j--]);
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
