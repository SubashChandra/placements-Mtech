#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(string str)
{
	int state=0;

	int x=0
	int y=0;

	int i=0;
	while(i<str.size())
	{
		if(str[i]=='G')
		{
			if(state==0)
				y++;
			else if(state==1)
				x++;
			else if(state==2)
				y--;
			else if(state==3)
				x--;

		}
		else
		{
			if(str[i]=='R')
			{
				state=(state+1)%4;
			}
			else
			{
				state=state-1;
				if(state<0)
					state+=4;
			}
		}
		i++;
	}
	if(x==0 && y==0)
		return 1;
	else
		return 0;
}


int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{
		string str;
		cin>>str;
		if(auxFunc(str))
			cout<<"Circular"<<endl;
		else
			cout<<"Not Circular"<<endl;
		cases--;
	}
	return 0;
}
