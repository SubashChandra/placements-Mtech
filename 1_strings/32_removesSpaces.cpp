#include<cstdio>
#include<iostream>
#include<sstream>

using namespace std;

void auxFunc(string str)
{
	stringstream ss(str);
	string ans,temp;
	while(ss>>temp)
	{
		ans+=temp;
	}
	cout<<ans<<endl;
}

int main()
{
	int cases;
	cin>>cases;
	getchar();
	while(cases>0)
	{
		string str;
		getline(cin,str);
		auxFunc(str);
		cases--;
	}
	return 0;
}
