#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str)
{
	int curX=0;
	int curY=0;

	int i;
	i=0;
	int nextX;
	int nextY;
	while(i<str.size())
	{
		nextX=(str[i]-'a')%5;
		nextY=(str[i]-'a')/5;

		while(curY<nextY)
		{
			cout<<"Move Down"<<endl;
			curY++;
		}

		while(curY>nextY)
		{
			cout<<"Move Up"<<endl;
			curY--;
		}

		while(curX<nextX)
		{
			cout<<"Move Right"<<endl;
			curX++;
		}
		while(curX>nextX)
		{
			cout<<"Move Left"<<endl;
			curX--;
		}


		cout<<"Press OK"<<endl;
		i++;
	}

}	

int main()
{
	string str;
	cin>>str;

	auxFunc(str);
	return 0;
}
