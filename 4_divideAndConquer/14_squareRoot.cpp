#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int n, int l, int r)
{
	if(l>r)
		return r;
	int mid=(l+r)/2;

	if(mid*mid == n)
		return mid;
	else if(mid*mid<n)
		return auxFunc(n,mid+1,r);
	else
		return auxFunc(n,l,mid-1);
}

int main()
{
	int n;
	cin>>n;

	cout<<auxFunc(n,1,n)<<endl;
	return 0;
}
