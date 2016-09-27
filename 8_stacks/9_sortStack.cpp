#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;


void insert(stack<int> &st, int data)
{
	if(st.size()==0)
	{
		st.push(data);
		return;
	}
	if(data>st.top())
	{
		st.push(data);
		return;
	}
	int temp=st.top();
	st.pop();
	insert(st,data);
	st.push(temp);
}

void sortStack(stack<int> &st)
{
	if(st.size()==0)
		return;
	int data=st.top();
	st.pop();
	sortStack(st);

	insert(st,data);
	
}

int main()
{
	int n;
	cin>>n;
	stack<int> st;
	int data;
	while(n>0)
	{
		cin>>data;
		st.push(data);
		n--;
	}
	sortStack(st);
	while(st.size()!=0)
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}
