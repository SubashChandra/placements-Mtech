#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int minLen(vector<string> vec)
{
	int len=vec[0].size();
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i].size()<len)
			len=vec[i].size();
	}
	return len;
}

string auxFunc(vector<string> vec)
{
	string ans;
	int i,j;
	int mLen=minLen(vec);
	for(i=0;i<mLen;i++)
	{
		char cur=vec[0][i];
		for(int j=1;j<vec.size();j++)
		{
			if(cur!=vec[j][i])
				return ans;
		}
		ans+=cur;
	}
	return ans;
}
		

int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	int i;
	string temp;
	for(i=0;i<n;i++)	
	{
		cin>>temp;
		vec[i]=temp;
	}

	string ans=auxFunc(vec);
	cout<<ans<<endl;
	return 0;
}

