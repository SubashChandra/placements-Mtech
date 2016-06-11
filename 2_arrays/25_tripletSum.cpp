#include<cstdio>
#include<iostream>
#include<vector>


using namespace std;


void auxFunc(vector<int> arr, int n, int sum)
{
	sort(arr.begin(), arr.end());
	int i,j,k;
	int curSum;
	for(i=0;i<n;i++)
	{
		j=i+1;
		k=n-1;
		while(j<k)
		{
			curSum=arr[i]+arr[j]+arr[k];
			if(curSum==sum)
			{
				cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
				return;
			}
			else if(curSum>sum)
				k--;
			else
				j++;
		}
	}
	cout<<"not found"<<endl;
}


int main()
{
	int n;
	cin>>n;
	int i;
	vector<int> arr(n);
	for(i=0;i<n;i++)
		cin>>arr[i];
	int sum;
	cin>>sum;

	auxFunc(arr,n,sum);
	return 0;
}
