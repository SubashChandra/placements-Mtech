#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

struct pairSum
{
	int sum;
	int first;
	int second;
};

typedef struct pairSum PairSum;

int compare(PairSum a, PairSum b)
{
	return a.sum < b.sum;
}



int noCommon(PairSum a, PairSum b)
{
	if(a.first == b.first || a.first==b.second || a.second==b.first || a.second==b.second)
		return 0;
	return 1;
}

void auxFunc(int arr[], int n, int sum)
{
	int size=(n*(n-1))/2;

	
	vector<PairSum> aux(size);
	int i,j,k;
	
	k=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			aux[k].first=arr[i];
			aux[k].second=arr[j];
			aux[k].sum=arr[i]+arr[j];
		//	cout<<arr[i]<<" "<<arr[j]<<" "<<aux[k].sum<<endl;
			k++;
		}
	}

	//qsort(aux, size,sizeof(aux[0]), compare);
	sort(aux.begin(),aux.end(),compare);
	i=0;
	j=size-1;
	while(i<j)
	{
		if(aux[i].sum+aux[j].sum == sum && noCommon(aux[i], aux[j]))
		{
			cout<<aux[i].first<<" "<<aux[i].second<<" "<<aux[j].first<<" "<<aux[j].second<<endl;
			return;
		}
		else if(aux[i].sum+aux[j].sum<sum)
			i++;
		else
			j--;
	}
	cout<<"not found"<<endl;
	return;
}



int main()
{
	int n;
	cin>>n;
	int i,arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];
	int sum;
	cin>>sum;
	auxFunc(arr,n,sum);
	return 0;
}

