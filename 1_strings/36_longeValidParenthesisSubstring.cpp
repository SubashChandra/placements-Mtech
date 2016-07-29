#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;

void auxFunc(string str)
{
	stack<int> st;
	int i,n=str.size();
	int maxLen=0;
	st.push(-1);

	for(i=0;i<n;i++)
	{
		if(str[i]=='(')
			st.push(i);
		else
		{
			st.pop();
			if(st.size()==0)
				st.push(i);
			else
				maxLen=max(maxLen,i-st.top());
		}
	}
	cout<<maxLen<<endl;
}


int main()
{
	string str;
	cin>>str;
	auxFunc(str);
	return 0;
}
