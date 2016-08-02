#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void auxFunc(string str, int ind, vector<string> ans)
{
	int i;
	if(ind>=str.size())
	{
		for(i=0;i<ans.size();i++)
			cout<<"("<<ans[i]<<")";
		cout<<endl;
	}
	string cur;
	for(i=ind;i<str.size();i++)
	{
		if(i==ind)
		{
			cur=str[i];
			ans.push_back(cur);
		}
		else
		{
			ans.back()+=str[i];
		}
		auxFunc(str,i+1,ans);
	}


}
		


int main()
{
	string str;
	cin>>str;
	vector<string> ans;
	
	auxFunc(str,0,ans);
	return 0;
}
