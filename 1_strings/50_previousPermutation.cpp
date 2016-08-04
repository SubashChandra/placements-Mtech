#include<cstdio>
#include<iostream>

using namespace std;

string auxFunc(string str)
{
	int i,j;
	for(i=str.size()-1;i>=1;i--)
	{
		if(str[i-1]>str[i])
			break;
	}
	if(i==0)
	{
		return "not possible";
	}

	for(j=str.size()-1;j>=i;j--)
	{
		if(str[j]<str[i-1])
			break;
	}
	swap(str[i-1],str[j]);
	j=str.size()-1;

	while(i<j)
	{
		swap(str[i],str[j]);
		i++;
		j--;
	}
	return str;
}

int main()
{
	string str;
	cin>>str;
	cout<<auxFunc(str)<<endl;

	return 0;
}
