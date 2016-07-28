#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const char nMap[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void auxFunc(int arr[], int ind, int n, vector<char> ans)
{
	if(ind==n)
	{
		for(int i=0;i<n;i++)
			cout<<ans[i];
		cout<<endl;
		return;
	}
	else
	{
		int i;
		if(arr[ind]==0 || arr[ind]==1)
			return;
		for(i=0;i<strlen(nMap[arr[ind]]);i++)
		{
			ans[ind]=nMap[arr[ind]][i];
			auxFunc(arr,ind+1,n,ans);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	vector<char> str(n);
	auxFunc(arr,0,n,str);
	return 0;
}

