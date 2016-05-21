#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

void auxFunc(vector<string> vec, string  str)
{
	map<char,int> m1;
	map<char, int>::iterator it;

	int i,j;
	string temp;
	for(i=0;i<vec.size();i++)
	{
		temp=vec[i];

		for(j=0;j<temp.size();j++)
		{
			it=m1.find(temp[j]);
			if(it==m1.end())
				m1.insert(pair<char,int>(temp[j],1));
		}

		for(j=0;j<str.size();j++)
		{
			it=m1.find(str[j]);
			if(it==m1.end())
				break;
		}
		if(j==str.size())
			cout<<vec[i]<<endl;
		m1.clear();
	}
}

int main()
{
	vector<string> vec;
	int n;
	cin>>n;
	getchar();
	string str;
	while(n>0)
	{
		getline(cin,str);
		vec.push_back(str);
		n--;
	}
	getline(cin,str);

	auxFunc(vec,str);

	return 0;
}
