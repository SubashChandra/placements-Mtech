#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int compare(vector<int> a, vector<int> b)
{
	if(a.size()>=b.size())
		return 0;
	return 1;
}

void auxFunc(int arr[], int n)
{
	int size=pow(2,n);
	int i,j,counter;
	vector<vector<int> > ans;
	vector<int> temp;
	for(counter=1;counter<size;counter++)
	{
		for(i=0;i<n;i++)
		{
			if(counter & 1<<i)
				temp.push_back(arr[i]);
		}
		ans.push_back(temp);
		temp.clear();
	}
	sort(ans.begin(),ans.end(),compare);
	for(i=0;i<ans.size();i++)
	{
		temp=ans[i];
		for(j=0;j<temp.size();j++)
			cout<<temp[j]<<" ";
		cout<<endl;
	}

}


int main()
{
	int n;
	cin>>n;
	int i,arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	auxFunc(arr,n);
	return 0;
}
