#include<cstdio>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>


using namespace std;

void push1(queue<int> &q, int data)
{
	if(q.size()==0)
	{
		q.push(data);
		return;
	}
	else
	{
		int n=q.size();
		q.push(data);
		while(n>0)
		{
			int temp=q.front();
			q.pop();
			q.push(temp);
			n--;
		}
	}
}

int pop1(queue<int> &q)
{
	if(q.size()!=0)
	{
		int data=q.front();
		q.pop();
		return data;
	}
	return -1;

}

int main()
{
	int opt;
	cout<<"1 to push, 2 to pop nd 3 to exit"<<endl;
	cin>>opt;
	queue<int> q;
	while(opt!=3)
	{
		if(opt==1)
		{
			int data;
			cin>>data;
			push1(q,data);
		}
		else
		{
			int data=pop1(q);
			cout<<"popped "<<data<<endl;

		}
		cout<<"1 to push, 2 to pop nd 3 to exit"<<endl;
		cin>>opt;

	}
	return 0;
}
