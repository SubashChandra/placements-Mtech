//given two strings, check if they are anagrams of each otehr

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

bool auxFunc(string str1,string str2)
{
	map<char,int>m1;
	map<char,int>::iterator it;

	int i;
	for(i=0;i<str1.size();i++)
	{
		it=m1.find(str1[i]);
		if(it==m1.end())
			m1.insert(pair<char,int>(str1[i],1));
		else
			it->second++;
	}


	for(i=0;i<str2.size();i++)
	{
		it=m1.find(str2[i]);
		if(it==m1.end())
		{
			return false;
		}
		else
			it->second--;
	}


	for(it=m1.begin();it!=m1.end();it++)
	{
		if(it->second>0)
			return false;
	}
	return true;
}

int main()
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);

	if(auxFunc(str1,str2))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	return 0;
}
