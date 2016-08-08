#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

string auxFunc(string str)
{
	vector<int> freq(26,0);
	int i,j,n=str.size();
	for(i=0;i<n;i++)
	{
		if(isalpha(str[i]) && islower(str[i]))
			freq[str[i]-'a']++;
	}

	string beg;
	char mid;
	for(i=0;i<26;i++)
	{
		int curFreq=freq[i];
		if(freq[i]&1) //if odd
			mid=i+'a';
		for(j=0;j<curFreq/2;j++)
			beg+=(i+'a');
	}
	string en=beg;
	reverse(en.begin(), en.end());

	return beg+mid+en;
}


	


int main()
{
	string str;
	cin>>str;

	cout<<auxFunc(str)<<endl;
	return 0;
}
