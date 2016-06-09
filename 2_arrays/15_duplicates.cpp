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

	for(i=0;i<n;i++)
	{
		if(arr[abs(arr[i])]<0)
			cout<<abs(arr[i])<<" ";
		else
			arr[abs(arr[i])]*=-1;
	}
	cout<<endl;
	return 0;
}
