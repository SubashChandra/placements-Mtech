#include<cstdio>
#include<iostream>

using namespace std;


void auxFunc(string str, int ind)
{
	if(ind==str.size())
	{
		cout<<str<<" ";
		return;
	}

	if(str[ind]=='?')
	{
		str[ind]='0';
		auxFunc(str,ind+1);
		str[ind]='1';
		auxFunc(str,ind+1);
	}
	else
		auxFunc(str,ind+1);
}

int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{
		string str;
		cin>>str;
		auxFunc(str,0);
		cout<<endl;
		cases--;
	}
	return 0;
}

