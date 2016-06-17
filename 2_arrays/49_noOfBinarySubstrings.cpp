#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(char arr[], int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]=='1')
			count++;

	cout<< (count*(count-1))/2<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i;
	char arr[n];
	
	cin>>arr;

	auxFunc(arr,n);

	return 0;
}
