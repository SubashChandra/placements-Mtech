#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int auxFunc(string str, int k)
{
	int i,j;
	int ans=0;
	for(i=0;i<str.size();i++)
	{
		int distCount=0;
		vector<int> cnt(26,0);
		for(j=i;j<str.size();j++)
		{
			if(cnt[str[j]-'a']==0)
				distCount++;
			cnt[str[j]-'a']++;
			if(distCount==k)
			{
				ans++;
			}
		}
	}
	return ans;
}


int main()
{
	string str;
	cin>>str;
	int k;
	cin>>k;
	cout<<auxFunc(str,k)<<endl;
	return 0;
}
