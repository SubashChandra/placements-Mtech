#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

string auxFunc(string str, int n)
{
	map<int, string> m1;

	int i,j;
	int ind;

	int size=str.size();

	i=0;
	while(i<size)
	{
		
		for(j=0;j<n && i<size;j++)
		{
			m1[j]+=str[i];
			i++;
		}

		for(j=n-2;j>=1 && i<size;j--)
		{
			m1[j]+=str[i];
			i++;
		}
	}

	map<int,string>::iterator it;
	string ans;
	for(it=m1.begin();it!=m1.end();it++)
		ans+=it->second;

	return ans;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{
		string str;
		cin>>str;
		int n;
		cin>>n;
		cout<<auxFunc(str,n)<<endl;

		cases--;
	}

	return 0;
}


