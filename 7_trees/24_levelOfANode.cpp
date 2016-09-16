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

void getLevel(Treeptr root,int data, int &ans, int &found, int level)
{
	if(root==NULL || found==1)
		return;
	if(root->data==data)
	{
		found=1;
		ans=level;
		return;
	}
	getLevel(root->left,data,ans,found,level+1);
	if(found==0)
		getLevel(root->right,data,ans,found,level+1);
}


void auxFunc(Treeptr root, int data)
{
	if(root==NULL)
		return;
	int ans;
	int found=0;
	getLevel(root,data,ans,found,1);
	if(found==1)
		cout<<ans<<endl;
	else
		cout<<"not found"<<endl;


}

int main()
{
	int n;
	Treeptr root=NULL;
	cin>>n;
	while(n>0)
	{
		int data;
		cin>>data;
		root=insert(root,data);
		n--;

	}

	cout<<"preorder:"<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"postorder:"<<endl;
	postOrder(root);
	cout<<endl;
	
	int data;
	cin>>data;
	auxFunc(root,data);
	return 0;
}
