#include<cstdio>
#include<iostream>

using namespace std;


void divideString(string &str,int n)
{
	string temp;
	while(str.size()>=n)
	{
		temp="";
		int i;
		for(i=0;i<n;i++)
		{
			temp+=str[i];
		}
		cout<<temp<<endl;
		str.erase(0,n);
	}
	//if(str.size()>0)
	//	cout<<str<<endl;
}


int main()
{
	string str;
	getline(cin,str,'\n');
	int n;
	cin>>n;
	int size=str.size()/n;
	divideString(str,size);
	return 0;
}
