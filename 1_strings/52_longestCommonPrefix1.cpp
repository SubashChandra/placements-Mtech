#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

string auxFunc(string prefix, string str)
{
	int i,j;
	int n1,n2;
	i=j=0;
	n1=prefix.size();
	n2=str.size();
	string ans;
	while(i<n1 && j<n2)
	{
		if(prefix[i]!=str[j])
			return ans;
		ans+=prefix[i];
		i++;
		j++;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	int i;
	
	for(i=0;i<n;i++)
	{
		string temp;
		cin>>temp;
		vec[i]=temp;
	}
	
	string prefix=vec[0];
	for(i=1;i<n;i++)
	{
		prefix=auxFunc(prefix,vec[i]);
	}

	cout<<prefix<<endl;
	return 0;
}

	
