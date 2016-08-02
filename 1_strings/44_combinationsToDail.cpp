#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

void auxFunc(string str, vector<string> vec, int ind, vector<char> temp)
{
	if(ind>=str.size())
	{
		for(int i=0;i<temp.size();i++)
			cout<<temp[i];
		cout<<endl;
		return;
	}

	for(int i=0;i<vec[str[ind]-'0'].size();i++)
	{
		temp[ind]=vec[str[ind]-'0'][i];
		auxFunc(str,vec,ind+1,temp);
	}
}
		
	

int main()
{
	string str;
	cin>>str;

	char m1[10][5]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string> vec(m1,m1+10);
	vector<char> temp(str.size());
	auxFunc(str,vec,0,temp);

	return 0;
}
