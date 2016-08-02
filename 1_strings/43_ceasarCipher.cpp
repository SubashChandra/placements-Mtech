#include<cstdio>
#include<iostream>

using namespace std;

string auxFunc(string str, int shift)
{
	shift=shift%26;

	if(shift==0)
		return str;
	int i;
	for(i=0;i<str.size();i++)
	{
		str[i]=(((str[i]-'a')+shift)%26)+'a';
	}
	return str;
}

int main()
{
	string str;
	int shift;
	cin>>str;
	cin>>shift;

	cout<<auxFunc(str,shift)<<endl;
	return 0;
}
