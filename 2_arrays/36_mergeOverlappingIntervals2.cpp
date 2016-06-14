//using a stack


#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int compare(vector<int> a, vector<int> b)
{
	return a[0]>b[0]?1:0;
}

void auxFunc(vector<vector<int> > vec)
{
	int i;
	//for(i=0;i<vec.size();i++)
	//	cout<<"("<<vec[i][0]<<","<<vec[i][1]<<")"<<" ";
	//cout<<endl;

	
	sort(vec.begin(), vec.end(), compare);

	for(i=0;i<vec.size();i++)
		cout<<"("<<vec[i][0]<<","<<vec[i][1]<<")"<<" ";
	cout<<endl;

	int index=0;
	
	for(i=0;i<vec.size();i++)
	{
		if(index!=0 && vec[index-1][0]<=vec[i][1])
		{
			while(index!=0 && vec[index-1][0]<=vec[i][1])
			{
				vec[index-1][0]=min(vec[index-1][0],vec[i][0]);
				vec[index-1][1]=max(vec[index-1][1],vec[i][1]);
				index--;
			}

		}
		else
			vec[index]=vec[i];
		index++;
	}

	for(i=0;i<index;i++)
		cout<<"("<<vec[i][0]<<","<<vec[i][1]<<")"<<" ";
	cout<<endl;

		
}


int main()
{
	vector<vector<int> > vec;
	vector<int> temp;
	int cases;
	cin>>cases;
	int x,y;
	for(int j=0;j<cases;j++)
	{
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			temp.push_back(x);
			temp.push_back(y);
			vec.push_back(temp);
			temp.clear();
		}

		auxFunc(vec);
	}

	return 0;
}

