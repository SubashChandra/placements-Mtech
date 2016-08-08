#include<cstdio>
#include<iostream>

using namespace std;

string auxFunc(string str)
{
	int i=0;
	for(i=0;i<str.size();i++)
	{
		if(isalpha(str[i]) && islower(str[i]))
			str[i]&= ~(1<<5);
	}
	return str;
}

int main()
{
	string str;
	cin>>str;

	cout<<auxFunc(str)<<endl;
	return 0;
}
