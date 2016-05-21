#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(string str)
{
	map<char,int> m1;
	map<char,int>::iterator it;
	int i;
	for(i=0;i<str.size();i++)
	{
		it=m1.find(str[i]);
		if(it==m1.end())
			m1.insert(pair<char,int>(str[i],1));
		else
			it->second=it->second+1;
	}

	for(i=0;i<str.size();i++)
	{
		it=m1.find(str[i]);
		if(it->second==1)
		{
			cout<<str[i]<<endl;
			break;
		}
	}
}

int main()
{
	string str;
	getline(cin,str,'\n');

	auxFunc(str);
	return 0;
}
