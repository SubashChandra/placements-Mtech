#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(map<string,string> m1)
{
	map<string, int> m2;
	map<string, int>::iterator it2;

	map<string,string>::iterator it1;

	for(it1=m1.begin();it1!=m1.end();it1++)
	{
		it2=m2.find(it1->first);
		if(it2==m2.end())
			m2[it1->first]=1;
		else
			it2->second++;

		it2=m2.find(it1->second);
		if(it2==m2.end())
			m2[it1->second]=1;
		else
			it2->second++;
	}

	string src;
	for(it2=m2.begin();it2!=m2.end();it2++)
	{
		if(it2->second==1 && m1.find(it2->first)!=m1.end())
		{
			src=it2->first;
		}
	}

	while(m1.find(src)!=m1.end())
	{
		cout<<src<<" -> "<<m1[src]<<"   ";
		src=m1[src];
	}
	cout<<endl;
	
}

int main()
{
	int n;
	cin>>n;
	int i;
	map<string,string> m1;
	string src,dst;
	for(i=0;i<n;i++)
	{
		cin>>src>>dst;
		m1[src]=dst;
	}

	auxFunc(m1);
	return 0;
}
