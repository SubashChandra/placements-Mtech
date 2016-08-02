// must do in one iteration

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(string str, int k)
{
	map<char,int> index;
	map<int,char> reverse;

	int i;
	for(i=0;i<str.size();i++)
	{
		if(index.find(str[i])==index.end())
		{
			index[str[i]]=i;
			reverse[i]=str[i];
		}
		else
		{
			
			int ind=index[str[i]];;
			reverse.erase(ind);
		}
	}
	if(k>reverse.size())
	{
		cout<<"not available"<<endl;
		return;
	}

	map<int,char>::iterator it;
	int count=1;
	for(it=reverse.begin();it!=reverse.end();it++)
	{
		if(count==k)
		{
			cout<<it->second<<endl;
			return;
		}
		count++;
	}


}


int main()
{
	string str;
	cin>>str;
	int k;
	cin>>k;

	auxFunc(str,k);
	return 0;
}
