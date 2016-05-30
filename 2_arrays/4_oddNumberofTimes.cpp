#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n,i;
	cin>>n;
	int data,ans=0;
	for(i=0;i<n;i++)
	{
		cin>>data;
		ans=ans^data;
	}
	cout<<data<<endl;

	return 0;
}
