#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(int arr[], int n, int prod)
{
	int i,j;
	if(prod==0)
	{
		for(i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				cout<<"Yes"<<endl;
				return;
			}
		}
		cout<<"No"<<endl;
		return;
	}
	else
	{
		map<int,int> m1;
		map<int,int>::iterator it;

		for(i=0;i<n;i++)
		{
			if(arr[i]!=0)
			{
				it=m1.find(prod/arr[i]);
				if(it==m1.end())
				{
					m1.insert(pair<int,int>(arr[i],1));
				}
				else 
				{
					cout<<"Yes"<<endl;
					return;
				}
			}
		}
		cout<<"No"<<endl;
					
	}


}

int main()
{
	int n;
	cin>>n;
	int arr[n],i;
	
	for(i=0;i<n;i++)
		cin>>arr[i];

	int prod;
	cin>>prod;

	auxFunc(arr,n,prod);
	return 0;
}
