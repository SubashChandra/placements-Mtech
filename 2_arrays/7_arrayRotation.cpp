#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
 {
    int testCases;
    cin>>testCases;
    while(testCases>0)
    {
        int n,d,i;
        cin>>n>>d;
        vector<int> vec(n);
        for(i=0;i<n;i++)
            cin>>vec[i];
            
        reverse(vec.begin(),vec.begin()+d);
        reverse(vec.begin()+d,vec.end());
        reverse(vec.begin(),vec.end());
        
        for(i=0;i<n;i++)
            cout<<vec[i]<<" ";
        cout<<endl;
        testCases--;
    }
    
	//code
	return 0;
}
