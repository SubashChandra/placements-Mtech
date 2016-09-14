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

Treeptr auxFunc(vector<int> preorder, vector<int> inorder, int &preIndex, int l, int r)
{
	if(l>r)
		return NULL;
	int i;
	Treeptr newnode=getNew(preorder[preIndex]);
	preIndex++;

	for(i=l;i<=r;i++)
	{
		if(inorder[i]==newnode->data)
			break;
	}
	newnode->left=auxFunc(preorder, inorder, preIndex,l,i-1);
	newnode->right=auxFunc(preorder, inorder, preIndex,i+1,r);
	return newnode;
}

int main()
{
	int n,data,i;
	cin>>n;
	vector<int> inorder,preorder;
	for(i=0;i<n;i++)
	{
		cin>>data;
		inorder.push_back(data);
	}
	for(i=0;i<n;i++)
	{
		cin>>data;
		preorder.push_back(data);
	}


	Treeptr root=NULL;
	int preIndex=0;
	root=auxFunc(preorder,inorder,preIndex,0,n-1);
	cout<<"preorder:"<<endl;
	preOrder(root);
	cout<<endl;
	return 0;
}
