#include<cstdio>
#include<iostream>
#include<sstream>

using namespace std;

int auxFunc(string str)
{
	if(str.size()<=1)
		return 0;
	if(!isupper(str[0]))
		return 0;
	if(str[str.size()-1]!='.')
		return 0;
	if(str[str.size()-1]=='.' && str[str.size()-2]==' ')
		return 0;

	int i;
	int n=str.size();
	for(i=1;i<n;i++)
	{
		if(str[i]==' ' && str[i-1]==' ')
			return 0;
	}

	str=str.substr(0,str.size()-1);
	stringstream ss(str);
	string temp;
	while(ss>>temp)
	{
		if(!isalpha(temp[0]))
			return 0;
		for(i=1;i<temp.size();i++)
		{
			if((!isalpha(temp[i])) || (!islower(temp[i])))
				return 0;
		}
	}
	return 1;
}



int main()
{
	string str;
	getline(cin,str);
	cout<<auxFunc(str)<<endl;
	return 0;
}
