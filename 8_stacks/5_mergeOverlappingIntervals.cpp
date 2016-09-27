#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>


using namespace std;

int compare(vector<int> a, vector<int> b)
{
	if(a[0]>b[0])
		return 0;
	else if(a[1]>b[1])
		return 0;
	return 1;
}

void auxFunc(vector<vector<int> > vec)
{
	if(vec.size()==0)
		return;
	sort(vec.begin(),vec.end(),compare);


	stack<vector<int> >st;
	st.push(vec[0]);

	int i=1;
	while(i<vec.size())
	{
		if(st.top()[1]>=vec[i][0])
		{
			st.top()[1]=max(st.top()[1],vec[i][1]);
		}
		else
			st.push(vec[i]);
		i++;
		
	}
	while(st.size()!=0)
	{
		cout<<st.top()[0]<<" "<<st.top()[1]<<endl;
		st.pop();
	}
}
			

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > vec(n,vector<int>(2));
	int x,y;
	for(int i=0;i<n;i++)
	{
		vector<int> temp(2);
		cin>>temp[0]>>temp[1];
		vec[i]=temp;
	}
	
	auxFunc(vec);

	return 0;
}
