#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

string auxFunc(string str)
{
	if(str.size()==0)
		return "Balanced";
	stack<char> s1;
	int i;
	for(i=0;i<str.size();i++)
	{
		char temp=str[i];
		if(temp=='(' || temp=='{' || temp=='[')
			s1.push(temp);
		else
		{
			if(s1.size()==0)
				return "Not Balanced";
			if((temp==')' && s1.top()=='(') || (temp=='}' && s1.top()=='{') || (temp==']' && s1.top()=='['))
			{
				s1.pop();
			}
			else
				return "Not Balanced";
		}
	}
	if(s1.size()==0)
		return "Balanced";
	else
		return "Not Balanced";
}

int main()
{
	string str;
	cin>>str;

	cout<<auxFunc(str)<<endl;
	return 0;
}
