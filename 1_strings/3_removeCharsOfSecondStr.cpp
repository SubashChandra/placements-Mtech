//remove characters in the second string from the first string 


#include<cstdio>
#include<iostream>
#include<map>

using namespace std;	

void auxFunc(string &str1, string str2)
{
	map<char,int> m1;
	map<char,int>::iterator it;

	int i;
	for(i=0;i<str2.size();i++)
	{
		it=m1.find(str2[i]);
		if(it==m1.end())
		{
			m1.insert(pair<char,int>(str2[i],1));
		}
	}

	int index=0;
	for(i=0;i<str1.size();i++)
	{
		it=m1.find(str1[i]);
		if(it==m1.end())
		{
			str1[index]=str1[i];
			index++;
		}
	}
	str1.resize(index);
	return;

}

int main()
{
	string str1,str2;

	getline(cin,str1,'\n');
	getline(cin,str2,'\n');

	auxFunc(str1,str2);

	cout<<str1<<endl;
	return 0;
}

	
