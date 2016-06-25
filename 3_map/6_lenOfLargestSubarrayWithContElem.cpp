#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

void auxFunc(int arr[], int n)
{
	set<int> s;
	set<int>::iterator it;

	int maxLen=0;
	int minElem,maxElem;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		s.insert(arr[i]);
		minElem=arr[i];
		maxElem=arr[i];
		for(j=i+1;j<n;j++)
		{
			it=s.find(arr[j]);
			if(it!=s.end())
				break;
			s.insert(arr[j]);
			minElem=min(minElem,arr[j]);
			maxElem=max(maxElem,arr[j]);
			
			
			if(maxElem-minElem==j-i)
				maxLen=max(maxLen,j-i+1);
		}
		s.clear();
	}

	cout<<maxLen<<endl;
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
