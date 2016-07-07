//dynamic programming


#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;


int auxFunc(int arr[], int be, int en,int year,vector<vector<int> > vec)
{
	if(be>en)
		return 0;
	if(vec[be][en]!=-1)
		return vec[be][en];

	return vec[be][en]=max(auxFunc(arr,be+1,en,year+1,vec)+year*arr[be],auxFunc(arr,be,en-1,year+1,vec)+year*arr[en]);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	vector<vector<int> > vec(n,vector<int>(n,-1));
	cout<<auxFunc(arr,0,n-1,1,vec)<<endl;
	return 0;
}
