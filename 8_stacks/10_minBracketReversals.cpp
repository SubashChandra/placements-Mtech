#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>

using namespace std;

int auxFunc(string str)
{
	stack<char> st;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='{')
			st.push(str[i]);
		else
		{
			if(st.size()==0)
				st.push(str[i]);
			else if(st.top()=='{')
				st.pop();
			else
				st.push(str[i]);
		}
	}
	if(st.size()==0)
		return 0;
	int openC,closeC;
	openC=closeC=0;

	while(st.size()!=0)
	{
		if(st.top()=='{')
			openC++;
		else
			closeC++;
		st.pop();
	}
	return ceil(openC/2.0)+ceil(closeC/2.0);
}

int main()
{
	string str;
	cin>>str;
	if(str.size()%2!=0)
	{		
		cout<<"not possible"<<endl;
		return 0;
	}
	cout<<auxFunc(str)<<endl;

	return 0;
}
