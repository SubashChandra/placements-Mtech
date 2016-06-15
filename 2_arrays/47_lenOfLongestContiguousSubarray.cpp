#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


void auxFunc(vector<int> vec)
{
	int n=vec.size();
	sort(vec.begin(), vec.end());

	int count=1;
	int maxLen=0;
	for(int i=1;i<n;i++)
	{
		if(vec[i]==vec[i-1]+1)
		{
			count++;
		}
		else
		{
			maxLen=max(maxLen,count);
			count=1;
		}
	}
	maxLen=max(maxLen,count);

	cout<<maxLen<<endl;
}



int main()
{
	int n;
	cin>>n;
	int i;
	vector<int> vec(n);
	for(i=0;i<n;i++)
		cin>>vec[i];

	auxFunc(vec);
	return 0;
}
