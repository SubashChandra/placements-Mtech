#include<cstdio>
#include<iostream>


using namespace std;

int isFound(string str, int ind, string pattern)
{
	int i,j;
	i=ind;
	j=0;
	while(i<str.size() && j<pattern.size())
	{
		if(str[i]!=pattern[j])
			return 0;
		i++;
		j++;
	}
	if(j==pattern.size())
		return 1;
	else
		return 0;
}

void auxFunc(string str, string pattern)
{
	int i,j;

	i=0;j=0;
	while(j<str.size())
	{
		int count=0;
		while(isFound(str,j,pattern))
		{
			count++;
			j+=pattern.size();
		}
		if(count>0)
			str[i++]='X';

		if(j<str.size())
			str[i++]=str[j++];
	}
	str.resize(i);
	cout<<str<<endl;
}

int main()
{
	string str;
	string pattern;
	cin>>str;
	cin>>pattern;

	auxFunc(str,pattern);
	return 0;
}
