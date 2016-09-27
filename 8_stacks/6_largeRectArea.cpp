#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

void auxFunc(vector<int> vec)
{
	if(vec.size()==0)
		return;

	stack<int> st;
	int i;
	int maxArea=0;
	int curArea;
	for(i=0;i<vec.size();)
	{
		if(st.size()==0 || vec[st.top()]<=vec[i])
			st.push(i++);
		else
		{
			int tp=st.top();
			st.pop();
			curArea=vec[tp]*(st.size()==0?i:(i-st.top()-1));
		
			maxArea=max(maxArea,curArea);
		}
	}

	while(st.size()!=0)
	{
		int tp=st.top();
		st.pop();
		curArea=vec[tp]*(st.size()==0?i:(i-st.top()-1));
		maxArea=max(maxArea,curArea);
	}
	cout<<maxArea<<endl;
}


int main()
{
	int n;
	cin>>n;
	int data;
	vector<int> vec;
	while(n>0)
	{
		cin>>data;
		vec.push_back(data);
		n--;
	}

	auxFunc(vec);


	return 0;
}
