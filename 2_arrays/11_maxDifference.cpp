#include <iostream>
using namespace std;
int main()
 {
	//code
	int testCases;
	cin>>testCases;
	while(testCases>0)
	{
	    int n,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	    
	    int max=arr[n-1];
	    int diff=0;
	    for(i=n-1;i>=0;i--)
	    {
	        if(arr[i]>max)
	            max=arr[i];
	        else if(max-arr[i]>diff)
	            diff=max-arr[i];
	    }
	    cout<<diff<<endl;
	    testCases--;
	}
	return 0;
}