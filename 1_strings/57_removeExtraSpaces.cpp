#include<cstdio>
#include<iostream>

using namespace std;


string auxFunc(string str)
{
	int i,j;
	i=0;

	while(i<str.size() && str[i]==' ')
		i++;
	j=str.size()-1;
	while(j>=0 && str[j]==' ')
		j--;

	str=str.substr(i,j-i+1);

	i=0;
	j=0;
	char pre=str[0];
	while(i<str.size())
	{
		str[j++]=str[i];
		pre=str[i];
		i++;
		while(str[i]==' ' && pre==' ')
			i++;
	}


	str=str.substr(0,j);

	i=0;
	j=0;
	while(i<str.size()-1)
	{
		if(str[i]==' ' && (str[i+1]=='.' || str[i+1]==',' || str[i+1]=='?'))
			i++;
		else
		{
			str[j++]=str[i];
			i++;
		}
	}
	str[j++]=str[i];
	str=str.substr(0,j);

	return str;
}


int main()
{
	string str;
	getline(cin,str);

	cout<<auxFunc(str)<<endl;
	return 0;
}
