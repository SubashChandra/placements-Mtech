#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

int auxFunc(string str)
{
	int i;
	set<char> s1;
	for(i=0;i<str.size();i++)
	{
		if(isalpha(str[i]))
			s1.insert(tolower(str[i]));
	}
	if(s1.size()==26)
		return 1;
	else
		return 0;
}


int main()
{
	int cases;
	cin>>cases;
	getchar();
	while(cases>0)
	{
		string str;
		getline(cin,str);
		cout<<auxFunc(str)<<endl;
		cases--;
	}
	return 0;
}
