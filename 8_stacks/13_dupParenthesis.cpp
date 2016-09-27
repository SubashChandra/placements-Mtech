#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

string auxFunc(string str)
{
	stack<char> st;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!=')')
			st.push(str[i]);
		else
		{
			while(st.top()!='(')
				st.pop();
			st.pop();
			if(i+1<str.size() && str[i+1]==')' && st.top()=='(')
				return "Has Dup";
		}
	}
	return "No Dup";
}

int main()
{
	string str;
	cin>>str;
	cout<<auxFunc(str)<<endl;
	return 0;
}
