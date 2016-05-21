#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

void reverseWord(string &str, int l, int r)
{
	while(l<r)
	{
		swap(str[l++],str[r--]);
	}

}

void reverseWords(string &str)
{
	int i=0;
	int start,end;
	while(i<str.size())
	{
		start=i;

		while(i<str.size() && str[i]!=' ')
			i++;

		end=i-1;
		reverseWord(str,start,end);
		while(i<str.size() && str[i]==' ')
			i++;
	}
	
	reverse(str.begin(), str.end());
}



int main()
{
	string str;
	getline(cin,str);
	
	reverseWords(str);
	cout<<str<<endl;
	return 0;
}
