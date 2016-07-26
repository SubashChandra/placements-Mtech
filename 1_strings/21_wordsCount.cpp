#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str)
{
	int count=0;
	int state=0; //out

	int i;

	for(i=0;i<str.size();i++)
	{
		if(str[i]==' ' || str[i]=='\n' || str[i]=='\t')
			state=0;
		else if(state==0)
		{
			state=1;
			count++;
		}

	}
	cout<<count<<endl;
}

int main()
{
	string str;
	str="one two      three\n four\nfive   ";
	auxFunc(str);
	return 0;
}
