#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str, string temp, int ind)
{
	if(ind==str.size())
		cout<<temp<<endl;
	else
	{
		string s=temp;
		
		s+=str[ind];
		auxFunc(str,s,ind+1);
		
		s=temp;
		s+=' ';
		s+=str[ind];
		auxFunc(str,s,ind+1);
	}
}

int main()
{
	string str;
	getline(cin,str);

	string temp;
	temp+=str[0];
	auxFunc(str,temp,1);
	return 0;
}
