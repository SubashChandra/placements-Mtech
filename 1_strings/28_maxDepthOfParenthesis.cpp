#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(string str)
{
	int count=0;
	int maxCount=0;

	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')
		{
			count++;
			maxCount=max(maxCount,count);
		}
		else if(str[i]==')')
			count--;
	}
	if(count!=0)
		return -1;
	return maxCount;
}

int main()
{
	string str;
	getline(cin,str);

	cout<<auxFunc(str)<<endl;
	return 0;
}
