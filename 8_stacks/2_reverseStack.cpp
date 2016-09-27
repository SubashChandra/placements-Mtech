#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;


void insertAtBottom(stack<int> &st, int data)
{
	if(st.size()==0)
	{
		st.push(data);
		return;
	}
	int temp=st.top();
	st.pop();
	insertAtBottom(st,data);
	st.push(temp);
}

void reverse(stack<int> &st)
{
	if(st.size()==0)
		return;
	int data=st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st,data);
}

int main()
{
	int n;
	cin>>n;
	int data;
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		st.push(data);
	}

	reverse(st);
	while(st.size()!=0)
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;

		
	return 0;
}
