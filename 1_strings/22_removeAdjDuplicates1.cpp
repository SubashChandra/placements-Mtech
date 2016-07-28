//using a stack in O(n) time

#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;

void auxFunc(string str)
{
	stack<char> st;

	int flag=0;// 1 implies top element of stack should be removed

	int i,n=str.size();
	for(i=0;i<n; )
	{
		if(st.size()==0 || st.top()!=str[i])
		{
			st.push(str[i]);
			i++;
		}
		else if(st.size()!=0 && st.top()==str[i])
		{
			while(i<n && str[i]==st.top())
				i++;
			st.pop();
		}
	}

	string ans;
	while(st.size()!=0)
	{
		ans+=st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;
}



int main()
{
	string str;
	cin>>str;

	auxFunc(str);
	return 0;
}
