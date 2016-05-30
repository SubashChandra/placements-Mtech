//time O(n)
//space O(1)

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
	//code
	int testCases;
	cin>>testCases;
	int i,j,n,data,flag;

	for(i=0;i<testCases;i++)
	{
	    cin>>n;
	    int arr[n];
	    for(j=0;j<n;j++)
	    {
	        cin>>arr[j];
	    }
	    
	    int data,count;
	    data=arr[0];
	    count=1;
	  
	    for(j=1;j<n;j++)
	    {
	        if(arr[j]==data)
	        {
	           count++;
	           
	        }
	        else
	        {
	            count--;
	            if(count<1)
	            {
	                data=arr[j];
	                count=1;
	            }
	        }
	    }
	    //data might be majority element
	    
	     count=0;
	    for(j=0;j<n;j++)
	    {
	        if(arr[j]==data)
	            count++;
	    }
	    if(count>n/2)
	        cout<<data<<endl;
	            
	    
	    else
	        cout<<"NO Majority Element"<<endl;
	}
	return 0;
}