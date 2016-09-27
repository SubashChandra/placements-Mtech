#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

void auxFunc(vector<int> vec)
{
	if(vec.size()==0)
		return;
	int n=vec.size();

	vector<int> temp(n);
	temp[0]=1;
	stack<int> st;
	st.push(0);

	for(int i=1;i<n;i++)
	{
		while(st.size()!=0 && vec[st.top()]<= vec[i])
			st.pop();

		temp[i]=(st.size()==0)?i+1:i-st.top();
		st.push(i);

	}

	for(int i=0;i<n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;

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
