//array may contain negatives as well

#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

void segregate(vector<int> &vec)
{
	int i, j;
	i=0;
	j=vec.size()-1;
	while(i<j)
	{
		while(i<j && vec[i]<=0)
			i++;
		while(i<j && vec[j]>0)
			j--;
		if(i<j)
			swap(vec[i++],vec[j--]);
	}
	
	for(i=0;i<vec.size();i++)
	{
		if(vec[i]>0)
			break;
	}
	vec.erase(vec.begin(), vec.begin()+i);
}
			

void auxFunc(vector<int> vec)
{
	int i;
	segregate(vec);
	//for(i=0;i<vec.size();i++)
	//{
	//	cout<<vec[i]<<" ";
	//}
	//cout<<endl;
	int n=vec.size();
	for(i=0;i<n;i++)
	{
		if(abs(vec[i])-1 < n && vec[abs(vec[i])-1]>0)
		{
			vec[abs(vec[i])-1]*=-1;
		}
	}

	for(i=0;i<n;i++)
	{
		if(vec[i]>0)
		{
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<n+1<<endl;
}

int main()
{
	int n,i;
	cin>>n;
	vector<int> vec(n);
	for(i=0;i<n;i++)
		cin>>vec[i];

	auxFunc(vec);
	return 0;
}
