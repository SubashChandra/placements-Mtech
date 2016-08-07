#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(string str1, string str2)
{
	int n=str1.size();
	int m=str2.size();
	if(n==0)
		return m;
	if(m==0)
		return n;

	if(str1[0]==str2[0])
		return auxFunc(str1.substr(1),str2.substr(1));
	return 1+min(auxFunc(str1.substr(1),str2),min(auxFunc(str1,str2.substr(1)),auxFunc(str1.substr(1),str2.substr(1))));
}

int main()
{
	string str1, str2;
	cin>>str1;
	cin>>str2;

	cout<<auxFunc(str1,str2)<<endl;
	return 0;
}
