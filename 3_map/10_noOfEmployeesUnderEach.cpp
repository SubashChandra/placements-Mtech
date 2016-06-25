#include<cstdio>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

void auxFunc(map<string,string> m1)
{
	map<string,string>::iterator it1;

	map<string,vector<string> > m2;
	map<string,vector<string> >::iterator it2;

	map<string, int> m3;
	map<string,int>::iterator it3;

	for(it1=m1.begin();it1!=m1.end();it1++)
	{
		m3[it1->first]=0;
	}

	for(it1=m1.begin();it1!=m1.end();it1++)
	{
		it3=m3.find(it1->second);
		if(it1->first!=it1->second)
			it3->second++;

		it2=m2.find(it1->second);
		if(it2==m2.end())
		{
			vector<string> temp;
			temp.push_back(it1->first);
			m2[it1->second]=temp;
		}
		else
		{
			it2->second.push_back(it1->first);
		}

	}
	for(it2=m2.begin();it2!=m2.end();it2++)
	{
		vector<string> temp=it2->second;
		cout<<it2->first<<" -> ";
		for(int i=0;i<temp.size();i++)
			cout<<temp[i]<<" ";
		cout<<endl;
		
		for(int i=0;i<temp.size();i++)
		{
			if(it2->first!=temp[i])
			{
				m3[it2->first]+=m3[temp[i]];
			}
		}
	
	}

	cout<<"--------------------------"<<endl;
	for(it3=m3.begin();it3!=m3.end();it3++)
		cout<<it3->first<<" -> "<<it3->second<<endl;
}



int main()
{
	int i,n;
	cin>>n;
	map<string,string> m1;
	map<string,string>::iterator it;

	
	string key, value;
	for(i=0;i<n;i++)
	{
		cin>>key>>value;
		m1[key]=value;
	}
	auxFunc(m1);
	return 0;
}
