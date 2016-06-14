//using a stack


#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int compare(vector<int> a, vector<int> b)
{
	return a[0]<b[0]?1:0;
}

void auxFunc(vector<vector<int> > vec)
{
	int i;
	//for(i=0;i<vec.size();i++)
	//	cout<<"("<<vec[i][0]<<","<<vec[i][1]<<")"<<" ";
	//cout<<endl;

	
	sort(vec.begin(), vec.end(), compare);

	for(i=0;i<vec.size();i++)
		cout<<"("<<vec[i][0]<<","<<vec[i][1]<<")"<<" ";
	cout<<endl;

	stack<vector<int> > st;
	st.push(vec[0]);
	vector<int> temp;
	for(i=1;i<vec.size();i++)
	{
		temp=st.top();
		if(temp[1]<vec[i][0]) //not overlapping
		{
			st.push(vec[i]);
		}

		else if(temp[1]<vec[i][1]) //otherwise update ending time if ending time of cur is greater than stack top
		{
			temp[1]=vec[i][1];
			st.pop();
			st.push(temp);
		}
	}

	//print stack
	while(st.size()!=0)
	{
		cout<<"("<<st.top()[0]<<","<<st.top()[1]<<")"<<" ";
		st.pop();
	}
	cout<<endl;



		
}


int main()
{
	vector<vector<int> > vec;
	vector<int> temp;
	int cases;
	cin>>cases;
	int x,y;
	for(int j=0;j<cases;j++)
	{
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			temp.push_back(x);
			temp.push_back(y);
			vec.push_back(temp);
			temp.clear();
		}

		auxFunc(vec);
	}

	return 0;
}

