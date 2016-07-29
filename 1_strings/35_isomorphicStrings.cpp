#include<cstdio>
#include<iostream>
#include<map>
#include<set>

using namespace std;

int auxFunc(string str1, string str2)
{
	if(str1.size()!=str2.size())
		return 0;

	int n=str1.size(),i;
	map<char,char> m1;
	set<char> used;
	for(i=0;i<n;i++)
	{
		if(m1.find(str1[i])==m1.end())
		{
			m1[str1[i]]=str2[i];
			if(used.find(str2[i])==used.end())
				used.insert(str2[i]);
			else
				return 0;
		}
		else
		{
			if(m1[str1[i]]!=str2[i])
				return 0;
		}
	}
	return 1;
}
	


int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{

	string str1,str2;
	cin>>str1;
	cin>>str2;

	cout<<auxFunc(str1,str2)<<endl;
	cases--;
	}
	return 0;
}
