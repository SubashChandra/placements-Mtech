//time = O(n)
//space = O(n)

#include <iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

int main() {
	//code
	int testCases;
	cin>>testCases;
	int i,j,n,data,flag;
	map<int,int> m1;
	map<int,int>::iterator it;
	for(i=0;i<testCases;i++)
	{
	    cin>>n;
	    for(j=0;j<n;j++)
	    {
	        cin>>data;
	        it=m1.find(data);
	        if(it==m1.end())
	        {
	            m1.insert(pair<int,int>(data,1));
	        }
	        else
	        {
	            it->second+=1;
	        }
	        
	    }
	    flag=0;
	    for(it=m1.begin();it!=m1.end();it++)
	    {
	        if(it->second>n/2)
	        {
	            flag=1;
	            cout<<it->first<<endl;
	            break;
	        }
	    }
	    if(flag==0)
	        cout<<"NO Majority Element"<<endl;
	    
	    m1.clear();
	}
	return 0;
}