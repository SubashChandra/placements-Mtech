#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

void auxFunc(string str)
{
	do
	{
		cout<<str<<endl;
	}while(next_permutation(str.begin(),str.end()));
}

int main()
{
	string str;
	cin>>str;

	auxFunc(str);
	return 0;
}
