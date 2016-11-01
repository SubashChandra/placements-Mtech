#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int n)
{
	//for simplicity one extra row and one extra column are allocated
	int m[n][n];
	int i,j,k,L,q;

	//m[i][j]=minimum no of scalar multiplicattions needed to compute
	// rhe matrix A[i]A[i+1]... A[j]=A[i...j] where dimention of A[i] is arr[i-1]*arr[i]

	for(i=1;i<n;i++)
		m[i][i]=0; //cost of computing one matrix

	//L is chain length
	for(L=2;L<n;L++)
	{
		for(i=1;i<n-L+1;i++)
		{
			j=i+L-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
				m[i][j]=min(m[i][j],q);
			}
		}
	}
	return m[1][n-1];
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,n)<<endl;
	return 0;
}
