#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int auxFunc(string str1,string str2)
{
	if(str1=="" || str2=="")
		return 1;
	
	//now append str1 to itself
	str1+=str1;
	void *ptr;

	//check if str2 is substring of str1

	if(str1.find(str2)!=string::npos)
		return 1;
	return 0;


}

int main()
{
	string str1,str2;
	getline(cin,str1,'\n');
	getline(cin,str2,'\n');

	if(auxFunc(str1,str2))
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}
	return 0;
}
