//gven a string, check if its an interleaving of the two given strings
//will not work if they hav common characters
#include<cstdio>
#include<iostream>

using namespace std;

bool auxFunc(string str1, string str2, string str3)
{
	int ind1,ind2,index;
	ind1=ind2=index=0;

	while(index<str3.size())
	{
		if(ind1<str1.size() && str3[index]==str1[ind1])
			ind1++;
		else if(ind2<str2.size() && str3[index]==str2[ind2])
			ind2++;
		else
			return false;
		index++;
	}
	cout<<"***"<<endl;
	return true;
}


int main()
{
	string str1,str2,str3;
	getline(cin,str1);
	getline(cin,str2);
	getline(cin,str3);

	if( auxFunc(str1,str2,str3))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}

