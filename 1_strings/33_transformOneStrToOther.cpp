#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

void auxFunc(string str1, string str2)
{
	int ind1,ind2;
	ind1=str1.size()-1;
	ind2=str2.size()-1;

	int count=0;
	while(ind1>=0)
	{
		while(ind1>=0 && str1[ind1]!=str2[ind2])
		{
			ind1--;
			count++;
		}

		if(ind1>=0) //match
		{
			ind1--;
			ind2--;
		}
	}

	cout<<count<<endl;
}

int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;

	auxFunc(str1,str2);
	return 0;
}
