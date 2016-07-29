#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(string str1, string str2)
{
	int flag=0;
	int i,j;
	int n1,n2;
	n1=str1.size();
	n2=str2.size();

	if(abs(n1-n2)>1)
		return 0;
	
	i=0;
	j=0;
	while(i<n1 && j<n2)
	{
		if(str1[i]!=str2[j])
		{
			if(flag==0)
			{
				if(n1<n2)
					j++;

				else if(n1>n2)
					i++;
				else
				{
					i++;
					j++;
				}
				flag=1;
				

			}
			else
				return 0;
		}
		else
		{
			i++;
			j++;
		}
	}
	if((i==n1 && j==n2) &&  flag==1)
		return 1;
	else if(flag==0 && n1-i+n2-j==1)
		return 1;
	else
		return 0;
}
	

int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;

	cout<<auxFunc(str1,str2)<<endl;
	return 0;
}
