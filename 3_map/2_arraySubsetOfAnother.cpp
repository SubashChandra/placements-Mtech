#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr1[], int n1, int arr2[], int n2)
{
	map<int,int> m1;
	map<int,int>::iterator it;

	int i;
	for(i=0;i<n1;i++)
	{
		m1.insert(pair<int,int>(arr1[i],1));
	}

	for(i=0;i<n2;i++)
	{
		it=m1.find(arr2[i]);
		if(it==m1.end())
		{
			cout<<"no"<<endl;
			return;
		}
	}

	cout<<"yes"<<endl;





}

int main()
{
	int n1;
	cin>>n1;

	int i,arr1[n1];

	for(i=0;i<n1;i++)
		cin>>arr1[i];
	
	int n2;
	cin>>n2;
	int arr2[n2];
	for(i=0;i<n2;i++)
		cin>>arr2[i];

	auxFunc(arr1,n1,arr2,n2);
	return 0;
}
