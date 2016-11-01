#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int arr[], int i, int j)
{
	if(i==j)
		return 0;

	int k;
	int minC=INT_MAX;
	int count;

	//place parenthesis at differenrt first and the last matrix
	for(k=i;k<j;k++)
	{
		count=auxFunc(arr,i,k)+auxFunc(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		minC=min(minC,count);
	}
	return minC;
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<auxFunc(arr,1,n-1)<<endl;
	return 0;
}
