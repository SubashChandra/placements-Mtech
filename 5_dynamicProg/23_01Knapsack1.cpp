#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int w[], int v[], int n, int weight)
{
	if(n==0 || weight==0)
		return 0;

	if(w[n-1]>weight)
		return auxFunc(w,v,n-1,weight);
	else
		return max(v[n-1]+auxFunc(w,v,n-1,weight-w[n-1]),auxFunc(w,v,n-1,weight));
}

int main()
{
	int n;
	cin>>n;
	int w[n];
	int v[n];
	int i;
	for(i=0;i<n;i++)
		cin>>v[i];
	for(i=0;i<n;i++)
		cin>>w[i];
	
	int weight;
	cin>>weight;
	cout<<auxFunc(w,v,n,weight)<<endl;
	return 0;
}
