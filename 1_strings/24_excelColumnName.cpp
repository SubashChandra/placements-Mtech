#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int n)
{
	string ans;
	while(n>0)
	{
		int rem=n%26;
		if(rem==0)
		{
			ans+='Z';
			n=(n/26)-1;
		}
		else
		{
			ans+=(rem-1)+'A';
			n=n/26;
		}
	}
	reverse(ans.begin(),ans.end());

	cout<<ans<<endl;
}

int main()
{
	int n;
	cin>>n;
	auxFunc(n);

	return 0;
}
