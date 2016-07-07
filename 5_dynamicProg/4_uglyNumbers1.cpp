#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(int n)
{
	if(n==1)
	{
		cout<<"1"<<endl;
		return;
	}

	int num,count;
	num=2;
	count=1;
	while(count<n)
	{
		int temp=num;
		while(num>1 && num%2==0)
			num=num/2;

		while(num>1 && num%3==0)
			num=num/3;

		while(num>1 && num%5==0)
			num=num/5;
		if(num==1)
			count++;
		num=temp;
		num++;
	}
	cout<<num-1<<endl;
}




int main()
{
	int n;
	cin>>n;
	auxFunc(n);
	return 0;
}
