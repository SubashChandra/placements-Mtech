#include<cstdio>
#include<iostream>

using namespace std;


void swap(string &str, int i, int j)
{
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}

void auxFunc(string &str, int l, int r)
{
	if(l>r)
		return;
	if(l==r)
		cout<<str<<endl;
	else
	{
		int i;
		for(i=l;i<=r;i++)
		{
			swap(str,l,i);
			auxFunc(str,l+1,r);
			swap(str,l,i);
		}
	}
}


int main()
{
	string str;
	getline(cin,str,'\n');

	auxFunc(str,0,str.size()-1);
	return 0;
}
