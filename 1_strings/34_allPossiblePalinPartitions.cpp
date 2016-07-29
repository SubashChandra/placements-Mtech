#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

bool isPalin(string str, int l, int r)
{
	while(l<r)
	{
		if(str[l]!=str[r])
		{
			return false;
		}
		l++;
		r--;
	}
	return true;
}


void auxFunc(vector<vector<string> > &vec, vector<string> cur, int ind, int n, string str)
{
	if(ind>=n)
	{
		vec.push_back(cur);
		return;
	}

	int i;
	//pick all possible ending points for strings
	for(i=ind;i<n;i++)
	{
		if(isPalin(str,ind,i))
		{
			cur.push_back(str.substr(ind,i-ind+1));

			//recur for remaining substring
			auxFunc(vec,cur,i+1,n,str);

			//remove substring [ind-i] from cur
			cur.pop_back();
		}
	}

}

void allPalin(string str)
{
	vector<vector<string> > vec;
	vector<string> cur;

	auxFunc(vec,cur,0,str.size(),str);
	int i,j;
	for(i=0;i<vec.size();i++)
	{
		for(j=0;j<vec[i].size();j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	string str;
	cin>>str;

	allPalin(str);
	return 0;
}
