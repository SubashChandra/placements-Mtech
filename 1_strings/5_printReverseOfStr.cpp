#include<cstdio>
#include<iostream>

using namespace std;


void printRev(string &str,int ind)
{
	if(ind<str.size())
	{
		printRev(str,ind+1);
		cout<<str[ind];
	}
}

int main()
{
	string str;
	getline(cin,str,'\n');

	printRev(str,0);
	cout<<endl;
	return 0;
}
