//binary search tree

#include<cstdio>
#include<iostream>
#include<map>
#include<stack>
#include<queue>

using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

typedef struct tree Tree;
typedef Tree *Treeptr;


Treeptr getNew(int data)
{
	Treeptr newnode=(Treeptr)malloc(sizeof(Tree));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

Treeptr insert(Treeptr root, int data)
{
	if(root==NULL)
		return getNew(data);

	if(data<root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	return root;
}

void preOrder(Treeptr root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Treeptr root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void postOrder(Treeptr root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void auxFunc(vector<int> pre, vector<int> in, int &preIndex, int l, int r)
{
	if(l>r)
		return;
	if(l==r)
	{
		cout<<pre[preIndex++]<<" ";
		return;
	}
	int curData=pre[preIndex];
	preIndex++;
	int i;
	for(i=l;i<=r;i++)
		if(in[i]==curData)
			break;
	auxFunc(pre,in,preIndex,l,i-1);
	auxFunc(pre,in,preIndex,i+1,r);
	cout<<curData<<" ";
}


int main()
{
	int n;
	cin>>n;
	vector<int> pre(n);
	vector<int> in(n);
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<n;i++)
		cin>>pre[i];
	int preIndex=0;
	auxFunc(pre,in,preIndex,0,n-1);
	cout<<endl;

	return 0;
}
