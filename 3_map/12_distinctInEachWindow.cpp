#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n, int k)
{
	map<int,int> m1;
	map<int,int>::iterator it;

	int wl,wr;
	wl=wr=0;
	
	while(wr<k)
	{
		it=m1.find(arr[wr]);
		if(it==m1.end())
			m1[arr[wr]]=1;
		else
			it->second++;
		wr++;

	}
	cout<<m1.size()<<endl;


	while(wr<n)
	{
		it=m1.find(arr[wl]);
		if(it->second==1)
			m1.erase(it);
		else
			it->second--;
		wl++;
		it=m1.find(arr[wr]);
		if(it==m1.end())
			m1[arr[wr]]=1;
		else
			it->second++;
		wr++;
		cout<<m1.size()<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;
	cout<<"***"<<endl;

	auxFunc(arr,n,k);
	return 0;
}
