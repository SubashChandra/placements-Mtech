//if "m" zeros can be flipped to get maximun contiguous 1's, find m indexes


#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
 

void auxFunc(int arr[], int n, int m)
{

	int l,r;
	int zeroCount=0;
	int i;
	l=0;
	r=0;
	vector<int> ans;
	vector<int> temp;
	int maxLength=0;


	while(r<n)
	{
		if(arr[r]==0)
		{
			
			if(zeroCount<m)
			{
				zeroCount++;
				temp.push_back(r);
				r++;
			}
			else
			{
				if((r-l)>maxLength)
				{
					maxLength=r-l;
					ans=temp;
				}

				temp.erase(temp.begin());
				while(arr[l]!=0)
				{
					l++;
				}
				zeroCount--;
				l++;
			}
		}

		else
		{
			r++;
				
				
		}
	}

	if((r-l)>maxLength)
	{
		maxLength=r-l;
		ans=temp;
	}
	cout<<"len: "<<maxLength<<endl;
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
		
	
}

int main()
{
	int n;
	cin>>n;
	int i,arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	int m;
	cin>>m;
	auxFunc(arr,n,m);
	

	return 0;
}
