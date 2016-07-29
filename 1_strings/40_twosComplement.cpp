#include<cstdio>
#include<iostream>

using namespace std;

string auxFunc(string str)
{
	int i;
	for(i=0;i<str.size();i++)
	{
		if(str[i]=='0')
			str[i]='1';
		else
			str[i]='0';
	}

	i=str.size()-1;

	while(i>=0 && str[i]!='0')
	{
		str[i]='0';
		i--;
	}

	if(i<0)
		str='1'+str;
	else
		str[i]='1';

	return str;
}


int main()
{
	string str;
	cin>>str;
	cout<<auxFunc(str)<<endl;

	return 0;
}
