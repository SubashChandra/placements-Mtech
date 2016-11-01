#include<cstdio>
#include<iostream>

using namespace std;

int auxFunc(int n, int k)
{
	//no floors no trials needed, one floor one trail needed
	if(k==0 || k==1)
		return k;
	
	//we  need k trails for one egg and k floors
	if(n==1)
		return k;

	int minVal=INT_MAX, x, res;

	//consider all dropings from floor 1 to floor k 
	//return the min of these values plus 1

	for(x=1;x<=k;x++)
	{
		res=max(auxFunc(n-1,x-1),auxFunc(n,k-x));
		minVal=min(res,minVal);
	}
	return minVal+1;
}


int main()
{
	int n,k; //n eegs  and k floors
	cin>>n>>k;
	cout<<auxFunc(n,k)<<endl;
	return 0;
}
