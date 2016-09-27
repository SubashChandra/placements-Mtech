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
	st.push(vec[0]);
	int i;
	for(i=1;i<vec.size();i++)
	{
		while(st.size()!=0 && st.top()<vec[i])
		{
			cout<<st.top()<<" -> "<<vec[i]<<endl;
			st.pop();
		}

		st.push(vec[i]);
	}

	while(st.size()!=0)
	{
		cout<<st.top()<<" -> -1"<<endl;
		st.pop();
	}
}
			
	

int main()
{
	int n;
	cin>>n;

	vector<int> vec;
	int data;
	while(n>0)
	{
		cin>>data;
		vec.push_back(data);
		n--;
	}

	auxFunc(vec);

		
	return 0;
}
