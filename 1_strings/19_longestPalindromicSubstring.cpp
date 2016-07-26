//an O(n2) algo with constant space

#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str)
{
	int maxLen=1;
	int start=0;
	int len=str.size();
	int low, high;

	int i;
	for(i=1;i<len;i++)
	{
		low=i-1;
		high=i;
		//even length
		while(low>=0 && high<len && str[low]==str[high])
		{
			if(high-low+1 > maxLen)
			{
				start=low;
				maxLen=high-low+1;
			}
			low--;
			high++;
		}

		//odd Length

		low=i-1;
		high=i+1;
		while(low>=0 && high<len && str[low]==str[high])
		{
			if(high-low+1 > maxLen)
			{
				start=low;
				maxLen=high-low+1;
			}
			low--;
			high++;

		}
	}

	cout<<"longest palindromic substring:  ";
	for(i=0;i<maxLen;i++)
		cout<<str[start+i];
	cout<<endl;
	cout<<"len: "<<maxLen<<endl;
}


int main()
{
	string str;
	getline(cin,str);
	auxFunc(str);
	return 0;
}
