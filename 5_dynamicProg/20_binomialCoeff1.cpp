#include<iostream>
#include<cstdio>

using namespace std;

int auxFunc(int n, int k)
{
	if(k==0 ||k==n)
		return 1;
	return auxFunc(n-1,k-1)+auxFunc(n-1,k);
}

int main()
{
	int n,k;
	cin>>n>>k;
	cout<<auxFunc(n,k)<<endl;
	return 0;
}

