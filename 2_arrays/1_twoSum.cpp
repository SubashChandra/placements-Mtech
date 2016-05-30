#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main() {
    //code
    int testCases;
    cin >>testCases;
    int i,j,n,x,flag;
    map<int,int> m1;
    map<int,int>::iterator it;
    for(i=0;i<testCases;i++)
    {
        flag=0;
        cin>>n>>x;
        int arr[n];
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        
        for(j=0;j<n;j++)
        {
            it=m1.find(x-arr[j]);
            if(it==m1.end())
            {
                m1.insert(pair<int,int>(arr[j],1));
            }
            else
            {
                cout<<"Yes"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"No"<<endl;
        m1.clear();
    }
    
    return 0;
}