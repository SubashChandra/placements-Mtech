#include<cstdio>
#include<iostream>

using namespace std;

void auxFunc(string str)
{
	int i,j;
	i=0;
	j=str.size()-1;

	while(i<j)
	{
		while(i<j && !isalpha(str[i]))
			i++;
		while(i<j && !isalpha(str[j]))
			j--;
		if(i<j)
			swap(str[i],str[j]);
		i++;
		j--;
	}
	cout<<str<<endl;

}
int main()
{
	string str;
	cin>>str;

	auxFunc(str);
	return 0;
}
