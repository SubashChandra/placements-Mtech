#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

string auxFunc(vector<int> pre)
{
	int root=INT_MIN;
	stack<int> st;
	for(int i=0;i<pre.size();i++)
	{
		if(pre[i]<root)
			return "False";
		while(st.size()!=0 && st.top()<pre[i])
		{
			root=st.top();
			st.pop();
		}

		st.push(pre[i]);
	
	}
	return "True";
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		vec.push_back(data);
	}
	cout<<auxFunc(vec)<<endl;
		
	return 0;
}
