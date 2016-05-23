#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str1, string str2, string ans, int ind1, int ind2, int index, int end)
{
	if(index==end)
		cout<<ans<<endl;
	else if(index<end)
	{
		if(ind1<str1.size())
		{
			ans[index]=str1[ind1];
			auxFunc(str1,str2,ans,ind1+1,ind2,index+1,end);
		}
		if(ind2<str2.size())
		{
			ans[index]=str2[ind2];
			auxFunc(str1,str2,ans,ind1,ind2+1, index+1,end);
		}
	}
}
				


int main()
{
	string str1,str2,ans;
	getline(cin,str1);
	getline(cin,str2);

	ans=str1+str2;
	int ind1=0,ind2=0;
	auxFunc(str1,str2,ans,ind1,ind2,0,ans.size());
	return 0;
}
