#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int main()
{
	string str;
	getline(cin,str,'\n');

	
	int i;
	map<char,int> m;
	map<char,int>::iterator it;
	for(i=0;i<str.size();i++)
	{
		it=m.find(str[i]);
		if(it==m.end())
		{
			m.insert(pair<char,int>(str[i],1));
		}
		else
		{
			it->second=it->second+1;
		}
	}


	char maxChar;
	int count=0;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
		if(it->second>count)
		{
			maxChar=it->first;
			count=it->second;
		}
	}

	cout<<"MaxChar : "<<maxChar<<endl;
	return 0;

}
