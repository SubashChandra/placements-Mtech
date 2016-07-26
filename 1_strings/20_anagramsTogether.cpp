#include<cstdio>
#include<iostream>
#include<map>
#include<vector>


using namespace std;

void auxFunc(vector<string> vec)
{
	int n=vec.size();
	map<string, vector<string> > m1;

	int i,j;
	for(i=0;i<n;i++)
	{
		string temp=vec[i];
		sort(temp.begin(),temp.end());
		m1[temp].push_back(vec[i]);
	}

	map<string, vector<string> >::iterator it;
	for(i=0;i<n;i++)
	{
		string temp=vec[i];
		sort(temp.begin(),temp.end());
		it=m1.find(temp);
		if(it!=m1.end())
		{
			vector<string> value = it->second;
			for(j=0;j<value.size();j++)
				cout<<value[j]<<" ";
			m1.erase(it);
		}
		
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	int i;
	for(i=0;i<n;i++)
		cin>>vec[i];

	auxFunc(vec);
	return 0;
}
