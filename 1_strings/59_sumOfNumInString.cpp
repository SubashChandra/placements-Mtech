#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(string str)
{
	int ans=0;
	int curSum=0,i;

	i=0;
	while(i<str.size())
	{
		if(isdigit(str[i]))
		{
			curSum=curSum*10 + (str[i]-'0');
			i++;
		}
		else
		{
			i++;
			ans+=curSum;
			curSum=0;
		}
	}
	if(curSum)
		ans+=curSum;
	return ans;
}

int main()
{
	string str;
	cin>>str;

	cout<<auxFunc(str)<<endl;
	return 0;
}
