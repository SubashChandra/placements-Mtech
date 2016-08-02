#include<cstdio>
#include<iostream>

using namespace std;

int isPalin(string str)
{
	int i,j;
	i=0;
	j=str.size()-1;
	while(i<j)
	{
		if(str[i]!=str[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

int auxFunc(string str)
{
	if(isPalin(str))
		return 1;

	return 2;
}

int main()
{
	string str;
	cin>>str;

	cout<<auxFunc(str)<<endl;
	return 0;
}
