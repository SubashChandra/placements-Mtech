#include<cstdio>
#include<iostream>

#define MAX_CHAR 256
using namespace std;

int fact(int n)
{
	return (n<=1)?1:n*fact(n-1);
}

void populateCount(string str, int count[])
{
	int i;
	for(i=0;i<str.size();i++)
		count[str[i]]++;
	for(i=1;i<256;i++)
		count[i]+=count[i-1];
}

void updateCount(int count[], char ch)
{
	int i;
	for(i=ch;i<256;i++)
		count[i]--;
}

int auxFunc(string str)
{
	int len=str.size();
	int mul=fact(len);
	int rank=1;
	int count[MAX_CHAR]={0};

	populateCount(str,count);
	int i;
	for(i=0;i<len;i++)
	{
		mul/=(len-i);
		rank+=(count[str[i]-1] * mul);

		updateCount(count,str[i]);
	}


	return rank;
}

int main()
{
	string str;

	getline(cin,str);
	cout<<auxFunc(str)<<endl;
	return 0;
}
