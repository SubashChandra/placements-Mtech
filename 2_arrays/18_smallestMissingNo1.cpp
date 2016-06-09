#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	if(arr[0]!=0)
	{	
		cout<<"0"<<endl;
		return 0;
	}
	else
	{
		for(i=1;i<n;i++)
		{
			if(arr[i]!=i)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<n<<endl;
	return 0;
}

