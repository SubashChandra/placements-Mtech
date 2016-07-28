#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(string str, int k)
{
	map<char,int> m1;
	int l,r;
	l=r=0;
	int maxLen=-1;
	int n=str.size();
	string ans;
	while(r<n)
	{
		if(m1.size()<k && m1.find(str[r])==m1.end())
		{
			m1[str[r]]++;
			r++;
		}
		else if(m1.size()<=k && m1.find(str[r])!=m1.end())
		{
			m1[str[r]]++;
			r++;
		}
		else
		{
			if(r-l > maxLen)
			{
				maxLen=r-l;
				ans=str.substr(l,maxLen);
			}
			while(m1.size()==k && l<=r)
			{
				m1[str[l]]--;
				if(m1[str[l]]==0)
					m1.erase(str[l]);
				l++;
			}
		}
	}
	if(m1.size()==k)
	{
		if(r-l > maxLen)
		{
			maxLen=r-l;
			ans=str.substr(l,maxLen);
		}
	}
	cout<<maxLen<<endl;
	cout<<ans<<endl;
}
				
				




int main()
{
	string str;
	int k;

	getline(cin,str);
	cin>>k;

	auxFunc(str,k);
	return 0;
}
