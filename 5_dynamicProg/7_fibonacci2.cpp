#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int n)
{
	int a,b,c,i;
	a=0;
	if(n==0)
	{
		cout<<a<<endl;
		return;
	}
	b=1;
	for(i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	cout<<b<<endl;
}

int main()
{
	int n;
	cin>>n;
	auxFunc(n);
	return 0;
}
