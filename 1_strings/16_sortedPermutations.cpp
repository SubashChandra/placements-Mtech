#include<cstdio>
#include<iostream>

using namespace std;

int findCeil(string str, char first, int l, int r)
{
	int ceilIndex=l;
	int i;
	for(i=l+1;i<=r;i++)
	{
		if(str[i]>first && str[i]<str[ceilIndex])
			ceilIndex=i;
	}
	return ceilIndex;
}

void auxFunc(string str)
{
	int n=str.size();
	sort(str.begin(),str.end());

	bool isFinished=false;

	while(!isFinished)
	{
		cout<<str<<endl;
		int i;
		for(i=n-2;i>=0;i--)
		{
			if(str[i]<str[i+1])
				break;
		}
		if(i==-1)
			isFinished=true;

		else
		{
			int ceilIndex=findCeil(str,str[i],i+1,n-1);
			swap(str[i],str[ceilIndex]);
			sort(str.begin()+i+1,str.end());
		}
	}
}
int main()
{
	string str;
	getline(cin,str);
	auxFunc(str);

	return 0;
}
