#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


void auxFunc(string str, vector<string> vec, vector<vector<int> > ind, int index)
{
	if(index==str.size())
	{
		cout<<str<<endl;
		return;
	}

	if(isalpha(str[index]))
	{
		auxFunc(str,vec,ind, index+1);
	}
	else
	{
		string temp=vec[str[index]-'0'];
		vector<int> curInd=ind[str[index]-'0'];
		for(int i=0;i<temp.size();i++)
		{
			for(int j=0;j<curInd.size();j++)
			{
				str[curInd[j]]=temp[i];
			}
			auxFunc(str,vec,ind,index+1);
		}
	}
}

int main()
{
	string str;
	cin>>str;
	
	char m[10][5]={"","ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX","YZ"};
	vector<string> vec(m,m+10);
	int i,j;
	vector<vector<int> > ind(10);
	for(i=0;i<str.size();i++)
	{
		int val=str[i]-'0';
		ind[val].push_back(i);
	}

	auxFunc(str,vec,ind,0);
	return 0;
}
