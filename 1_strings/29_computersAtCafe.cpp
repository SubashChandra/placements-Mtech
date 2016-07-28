#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

void auxFunc(string str, int n)
{
	set<char> cUsing;
	set<char> cantUse;

	int i;
	for(i=0;i<str.size();i++)	
	{
		if(cantUse.find(str[i])!=cantUse.end())
		{
			continue;
		}
		else
		{
			if(cUsing.find(str[i])==cUsing.end())
			{
				if(cUsing.size()<n)
					cUsing.insert(str[i]);
				else
					cantUse.insert(str[i]);
			}
			else
			{
				cUsing.erase(str[i]);
			}
		}
	}
	cout<<cantUse.size()<<endl;
}

int main()
{
	int n;
	string str;
	cin>>n;
	getchar();

	getline(cin,str);
	auxFunc(str,n);
	return 0;
}
