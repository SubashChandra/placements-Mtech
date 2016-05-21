#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

void auxFunc(string &str)
{
	if(str.size()==0)
		return;

	int i,index=0;
	int count=1;
	char pre=str[0];
	i=1;
	while(i<str.size())
	{
		if(pre==str[i])
		{
			count++;
		}
		else
		{
			str[index]=pre;
			index++;
			if(count>1)
			{
				str[index]=count+'0';
				index++;
			}
			pre=str[i];
			count=1;
		}
		i++;
	}
	str[index]=pre;
	index++;
	if(count>1)
		str[index++]=count+'0';
	str.resize(index);
}
			

int main()
{
	string str;
	getline(cin,str);

	auxFunc(str);
	cout<<str<<endl;
	return 0;
}
