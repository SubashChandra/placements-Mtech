#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int median(vector<int> vec)
{
	int n=vec.size();
	if(n%2==0)
	{
		return (vec[n/2]+vec[n/2-1])/2;
	}
	else 
		return vec[n/2];
}

int getMedian(vector<int> vec1, vector<int> vec2)
{
	int n1=vec1.size();
	int n2=vec2.size();
	int i;
	if(n1==1 && n2==1)
		return (vec1[0]+vec2[0])/2;
	else if(n1==2 && n2==2)
	{
		int val1=max(vec1[0],vec2[0]);
		int val2=min(vec1[1],vec2[1]);
		return (val1+val2)/2;
	}
	else
	{
		int med1=median(vec1);
		int med2=median(vec2);
		if(med1==med2)
			return med1;
		else if(med1>med2)
		{
			if(n1%2==0)
				vec1.erase(vec1.begin()+(n1/2),vec1.end());
			else
				vec1.erase(vec1.begin()+(n1/2)+1,vec1.end());

			vec2.erase(vec2.begin(),vec2.begin()+n2/2);
			return getMedian(vec1,vec2);
		}
		else
		{
		
			vec1.erase(vec1.begin(),vec1.begin()+(n1/2));
			if(n2%2==0)
				vec2.erase(vec2.begin()+(n2/2),vec2.end());
			else
				vec2.erase(vec2.begin()+(n2/2)+1,vec2.end());
			return getMedian(vec1,vec2);
		}
	}
}
int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{
		int n1;
		cin>>n1;
		int i;
		vector<int> vec1(n1);
		for(i=0;i<n1;i++)
			cin>>vec1[i];

		int n2=n1;
		vector<int> vec2(n2);
		for(i=0;i<n2;i++)
			cin>>vec2[i];

		cout<<getMedian(vec1,vec2)<<endl;
		cases--;
	}
	return 0;
}
	
