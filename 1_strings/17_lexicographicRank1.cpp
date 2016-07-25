#include<cstdio>
#include<iostream>

using namespace std;

int fact(int n)
{
	return (n<=1)?1:n*fact(n-1);
}


int findSmallerInRight(string str, char c, int l, int r)
{
	int count=0;
	for(int i=l;i<=r;i++)
	{
		if(str[i]<c)
			count++;
	}
	return count;
}

int auxFunc(string str)
{
	int len=str.size();
	int mul=fact(len);
	int rank=1;
	int countRight;

	int i;
	for(i=0;i<len;i++)
	{
		mul/=(len-i);
		countRight=findSmallerInRight(str,str[i],i+1,len-1);
		rank+=(countRight*mul);
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
