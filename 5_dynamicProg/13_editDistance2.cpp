#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str1, string str2)
{
	int n=str1.size();
	int m=str2.size();
	int i,j;
	int ed[n+1][m+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0)
				ed[i][j]=j;
			else if(j==0)
				ed[i][j]=i;
			else if(str1[i]==str2[j])
				ed[i][j]=ed[i-1][j-1];
			else
				ed[i][j]=1+min(ed[i-1][j],min(ed[i][j-1],ed[i-1][j-1]));
		}
	}
	cout<<ed[n][m]<<endl;

}

int main()
{
	string str1, str2;
	cin>>str1;
	cin>>str2;

	auxFunc(str1,str2);
	return 0;
}
