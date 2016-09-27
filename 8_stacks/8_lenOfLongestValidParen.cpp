#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

int auxFunc(string str)
{
	stack<int> st;
	st.push(-1);
	int maxLen=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')
			st.push(i);
		else
		{
			st.pop();
			if(st.size()!=0)
				maxLen=max(maxLen,i-st.top());
			else
				st.push(i);
		}
	}
	return maxLen;
}

int main()
{
	string str;
	cin>>str;
	cout<<auxFunc(str)<<endl;
	return 0;
}
