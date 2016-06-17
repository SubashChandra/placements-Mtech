#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;


void auxFunc(int arr1[],int l1, int r1, int arr2[], int l2,int r2, vector<int> vec, int index, int flag)
{
	
	
	if(flag==0)
	{
		if(l2>r2)
			return;
		int i=l1;
		while(index!=0 && i<=r1 && arr1[i]<vec[index-1])
			i++;
		
		while(i<=r1)
		{
			vec[index]=arr1[i];
			auxFunc(arr1,i+1,r1,arr2,l2,r2,vec,index+1,1);
			i++;
		}
	}
	else
	{
		int i=l2;
		while(i<=r2 && arr2[i]<vec[index-1])
			i++;

		while(i<=r2)
		{
			vec[index]=arr2[i];
			for(int j=0;j<=index;j++)
				cout<<vec[j]<<" ";
			cout<<endl;
			auxFunc(arr1,l1,r1,arr2,i+1,r2,vec,index+1,0);
			i++;
		}
	}


}
		


int main()
{
	int n1,n2;
	cin>>n1;

	int arr1[n1],i;
	for(i=0;i<n1;i++)
		cin>>arr1[i];

	cin>>n2;
	int arr2[n2];
	for(i=0;i<n2;i++)
		cin>>arr2[i];

	vector<int> vec(n1+n2);
	int flag=0;
	int index=0;
	auxFunc(arr1,0, n1-1,arr2,0, n2-1,vec,index,flag);
	return 0;
}
