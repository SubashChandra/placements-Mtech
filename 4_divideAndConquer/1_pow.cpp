#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int a, int b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;

	int ans=auxFunc(a,b/2);
	if(b%2==0)
		return ans*ans;
	else
		return ans*ans*a;
}


int main()
{
	int a,b;
	cin>>a>>b;
	cout<<auxFunc(a,b)<<endl;
	return 0;
}
