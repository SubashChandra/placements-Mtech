#include<cstdio>
#include<iostream>


using namespace std;

void auxFunc(int arr[], int  n)
{
	int i;
	int c[3]={0};
	for(i=0;i<n;i++)
	{
		c[arr[i]%3]++;
	}

	int count=0;

	//of size 2
	if(c[0]>=2)
		count+=(c[0]*(c[0]-1))/2;
	count+=c[1]*c[2];

	//of size 3

	if(c[0]>=3)
		count+=(c[0]*(c[0]-1)*(c[0]-2))/6;
	if(c[1]>=3)
		count+=(c[1]*(c[1]-1)*(c[1]-2))/6;
	if(c[2]>=3)
		count+=(c[2]*(c[2]-1)*(c[2]-2))/6;

	count+=c[0]*c[1]*c[2];

	cout<<count<<endl;

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
