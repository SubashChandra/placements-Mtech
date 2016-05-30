#include <iostream>
using namespace std;
int main()
 {
	//code
	int testCases;
	cin>>testCases;
	
	int i,j,k,n;
	for(i=0;i<testCases;i++)
	{
	    cin>>n;
	    int arr[n];
	    for(j=0;j<n;j++)
	        cin>>arr[j];
	   
	    j=0;
	    k=n-1;
	    while(j<k)
	        swap(arr[j++],arr[k--]);
	   
	    for(j=0;j<n;j++)
	        cout<<arr[j]<<" ";
	   cout<<endl;
	}
	return 0;
}