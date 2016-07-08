#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int n)
{
	int fib[n+1];

	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<=n;i++)
		fib[i]=fib[i-1]+fib[i-2];

	cout<<fib[n]<<endl;
}

int main()
{
	int n;
	cin>>n;
	auxFunc(n);
	return 0;
}
