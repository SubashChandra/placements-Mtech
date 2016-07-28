#include<cstdio>
#include<iostream>

using namespace std;

//check if str1 is a subsequence of str2
int auxFunc(string str1, string str2)
{
	int ind1, ind2;;

	int n1,n2;
	ind1=ind2=0;
	n1=str1.size();
	n2=str2.size();
	while(ind1<n1)
	{
		if(ind2<n2)
		{
			if(str1[ind1]==str2[ind2])
			{
				ind1++;
				ind2++;
			}
			else
			{
				ind2++;
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

			

int main()
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);

	cout<<auxFunc(str1,str2)<<endl;
	return 0;
}
