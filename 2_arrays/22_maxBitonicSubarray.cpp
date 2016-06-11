//given an array, find max length bitonic subarray

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


void auxFunc(vector<int> vec)
{
	int n=vec.size();
	int inc[n],dec[n];

	int i;
	inc[0]=1;
	for(i=1;i<n;i++)
	{
		if(vec[i]>=vec[i-1])
			inc[i]=inc[i-1]+1;
		else
			inc[i]=1;
	}

	dec[n-1]=1;
	for(i=n-2;i>=0;i--)
	{
		if(vec[i]>=vec[i+1])
			dec[i]=dec[i+1]+1;
		else
			dec[i]=1;
	}

	int max=inc[0]+dec[0]-1;
	for(i=1;i<n;i++)
	{
		if(inc[i]+dec[i]-1>max)
			max=inc[i]+dec[i]-1;
	}

	cout<<max<<endl;
}



int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);


	int i;
	for(i=0;i<n;i++)
		cin>>vec[i];

	auxFunc(vec);
	return 0;
}
