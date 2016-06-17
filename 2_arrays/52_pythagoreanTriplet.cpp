#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int arr[], int n)
{
	sort(arr,arr+n);

	int i,j,k;
	for(i=0;i<n-2;i++)
	{
		j=i+1;
		k=i+2;
		while(k<n)
		{
			int temp1=arr[i]*arr[i] +arr[j]*arr[j];
			int temp2=arr[k]*arr[k];
			if(temp1==temp2)
			{
				cout<<"true"<<endl;
				return;
			}
			else if(temp1>temp2)
			{
				k++;
			}
			else
			{
				j++;
				if(j==k)
					k++;
			}
		}
	}
	cout<<"false"<<endl;


}

int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
