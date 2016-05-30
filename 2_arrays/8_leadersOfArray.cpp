#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	vector<int> vec;
	int max=arr[n-1];
	vec.push_back(max);
	for(i=n-2;i>=0;i--)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			vec.push_back(max);
		}
	}
	reverse(vec.begin(),vec.end());
	for(i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	return 0;
}
