#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int main()
{
	string str;
	getline(cin,str,'\n');

	map<char,int> m1;
	map<char,int>::iterator it;

	int i;
	for(i=0;i<str.size();i++)
	{
		it=m1.find(str[i]);
		if(it==m1.end())
		{
			m1.insert(pair<char,int>(str[i],1));
		}
		else
			it->second=it->second+1;
	}

	int index=0;

	for(i=0;i<str.size();i++)
	{
		it=m1.find(str[i]);
		if(it->second>=1)
		{
			str[index]=str[i];
			it->second=0;
			index++;
		}
	}
	str.resize(index);
	cout<<str<<endl;
	return 0;
}
