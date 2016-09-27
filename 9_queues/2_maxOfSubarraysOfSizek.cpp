#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<deque>


using namespace std;

void auxFunc(vector<int> vec, int k)
{
	deque<int> dq(k);
	//process first k elements
	int i;
	for(i=0;i<k;i++)
	{
		//remove pre smaller elements
		while(dq.size()!=0 && vec[i]>=vec[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}

	for(;i<vec.size();i++)
	{
		//print largest element
		cout<<vec[dq.front()]<<" ";

		//remove elements out of the cur window
		while(dq.size()!=0 && dq.front()<=(i-k))
			dq.pop_front();

		//remove pre smaller elements
		while(dq.size()!=0 && vec[i]>=vec[dq.back()])
			dq.pop_back();

		dq.push_back(i);
	}
	//print max of last window
	cout<<vec[dq.front()]<<endl;
}

	

int main()
{
	int n;
	cin>>n;
	vector<int> vec;
	while(n>0)
	{
		int data;
		cin>>data;
		vec.push_back(data);
		n--;
	}
	int k;
	cin>>k;
	auxFunc(vec,k);

	return 0;
}
