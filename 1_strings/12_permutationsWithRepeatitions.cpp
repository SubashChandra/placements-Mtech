#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

void auxFunc(string str, string temp, int index, int last)
{
	int i, size=str.size();

	for(i=0;i<size;i++)
	{
		temp[index]=str[i];

		if(index==last)
			cout<<temp<<endl;
		else
			auxFunc(str,temp,index+1,last);
	}
}

int main()
{
	string str;
	getline(cin,str);

	sort(str.begin(),str.end());
	string temp=str;
	auxFunc(str,temp,0,str.size()-1);

	return 0;
}
