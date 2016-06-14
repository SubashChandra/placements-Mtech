#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int compare(string a, string b)
{
	string ab=a+b;
	string ba=b+a;

	return ab>ba?1:0;

}

void auxFunc(vector<string> vec)
{
	sort(vec.begin(), vec.end(), compare);

	for(int i=0;i<vec.size();i++)
		cout<<vec[i];
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	int temp,i;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		vec[i]=to_string(temp);
	}

	auxFunc(vec);
	return 0;
}
