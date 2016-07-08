#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str1, string str2)
{
	int n=str1.size();
	int m=str2.size();
	int i,j;
	int lic[n+1][m+1];

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				lic[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				lic[i][j]=lic[i-1][j-1]+1;
			else
				lic[i][j]=max(lic[i][j-1],lic[i-1][j]);
		}
	}
	cout<<lic[n][m]<<endl;
}

int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;

	auxFunc(str1,str2);
	return 0;
}
